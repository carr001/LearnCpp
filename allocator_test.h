//#pragma once
#ifndef __ALLOCATOR_TEST__
#define __ALLOCATOR_TEST__
#include<iostream>
#include"class_test.h"
//#include<cstddef>
using namespace std;
class Screen {// 来自侯捷，侯捷来自C++ primer3 p765
public:
	Screen(int x) :id(x) {};
	int get() { return id; };
	void *operator new(size_t size);//第一个参数必须是size_t
	void operator delete(void *,size_t size) ;//第一个参数必须是void *
private://用于实现内存管理的数据，相当于额外的cost
	Screen* next;//使用allocator需要消耗的额外内存
	static Screen* frontStore;
	static const int screenChunksz;
private://真正数据
	int id;
};
Screen *Screen::frontStore = 0;
const int Screen::screenChunksz = 24;
void* Screen::operator new(size_t size) {//这个size的作用是new的时候接受 类的大小
	Screen *p;
	if (!frontStore) {//如果fontStore等于0，那么说明这是第一次调用，因此需要分配内存
		size_t chunk = screenChunksz * size;// size表示一个类对象多大。screenChunksz表示想要多少个类对象
		frontStore = p = reinterpret_cast<Screen*>(new char[chunk]);
		for (;p != &frontStore[screenChunksz - 1];p++) {
			p->next = p + 1;
		}
		p->next = 0;//
	}
	p = frontStore;//等于闲置内存的空间头
	frontStore = frontStore->next;
	return p;
}
void Screen::operator delete(void * p, size_t size) {//没有 free内存，但是也没有内存泄漏。这样操作系统没法得到剩余内存，这点后面介绍如何归还
	(static_cast<Screen*>(p))->next = frontStore;
	frontStore = static_cast<Screen*>(p);
}
//**************** per class allocator 2*********************//
#include <iostream>
#include <cstddef>
using namespace std;
//ref. Effective C++ 2e,item 10
//1.malloc效率
//2.cookie管理
//per-class allocator,2
class Airplane {
private:
	struct AirplaneRep {//这里做声明
		unsigned long miles;
		char type;
	};
private:
	union {//实际的成员变量，空闲时是next Airplane的地址，不空闲时是 rep
		AirplaneRep rep;  //此处针对使用中的objects
		Airplane* next;  //处针对free list上的object
				//embeded pointer 嵌入式指针
	};
public:
	unsigned long getMiles() {
		return rep.miles;
	}
	char getType() {
		return rep.type;
	}
	void set(unsigned long m, char t) {
		rep.miles = m;
		rep.type = t;
	}
public:
	static void* operator new(size_t size);
	static void operator delete(void* deadObject, size_t size);
private:
	static const int BLOCK_SIZE;
	static Airplane* headOfFreeList;
};
Airplane* Airplane::headOfFreeList = 0;
const int Airplane::BLOCK_SIZE = 512;

void* Airplane::operator new(size_t size) {
	//如果大小有误，转交给::operator new()
	//继承体系中
	if (size != sizeof(Airplane)) {
		return ::operator new(size);
	}

	Airplane *p = headOfFreeList;
	if (p) {
		//如果p有效，就把list头部下移一个元素
		headOfFreeList = p->next;
	}
	else {
		//free list是空的，所以申请一大块
		Airplane* newBlock = static_cast<Airplane*>
			(::operator new(BLOCK_SIZE * sizeof(Airplane)));

		//将小块串成一个free list,
		//但跳过 #0, 因它将被传回做为本次成果
		for (int i = 1; i < BLOCK_SIZE - 1; ++i) {
			newBlock[i].next = &newBlock[i + 1];
		}
		newBlock[BLOCK_SIZE - 1].next = 0;
		p = newBlock;
		headOfFreeList = &newBlock[1];
	}
	return p;
}
void Airplane::operator delete(void* deadObject, size_t size) {
	if (deadObject == 0) return;
	if (size != sizeof(Airplane)) {
		::operator delete(deadObject);
		return;
	}
	Airplane* carcass =
		static_cast<Airplane*>(deadObject);

	carcass->next = headOfFreeList;
	headOfFreeList = carcass;
}
//******************  static allocator***************************//
class allocator_m
{
private:
	struct obj//与union不同，这里只声明，用于转型
	{
		obj* next;	//embeded pointer
	};
public:
	void* allocate(size_t size) {
		obj *p;
		if (!freeStore) {
			freeStore = p = (obj*)malloc(size * CHUNK);

			for (int i = 0; i < CHUNK - 1; ++i) {
				p->next = (obj*)((char*)p + size);// 前面声明的obj struc对分配的内存进行转型。
				p = p->next;
			}
			p->next = nullptr;
		}
		p = freeStore;
		freeStore = freeStore->next;
		return p;
	}

	void deallocate(void* pDead, size_t size) {
		((obj*)pDead)->next = freeStore;
		freeStore = (obj*)pDead;
	}
private:
	obj *freeStore = nullptr;
	const int CHUNK = 5;	//每次分配的大小
};
//测试类 Foo
class Foo
{
private:
	long lData;
	string str;
	static allocator_m alloc;
public:
	Foo(long l) : lData(l) {}
	void* operator new(size_t size) {
		return alloc.allocate(size);
	}
	void operator delete(void* pDead, size_t size) {
		alloc.deallocate(pDead, size);
	}
};

allocator_m Foo::alloc;

//测试类 Goo
class Goo
{
private:
	Complex cpl;
	int data;
	static allocator_m alloc;
public:
	Goo(int i) : data(i) {}
	void* operator new(size_t size) {
		return alloc.allocate(size);
	}
	void operator delete(void* pDead, size_t size) {
		alloc.deallocate(pDead, size);
	}
};

allocator_m Goo::alloc;
//****************macro for static allocator *****************************//
//used in class definition
#define DECLARE_POOL_ALLOC() \
public: \
void* operator new(size_t size) { return myAlloc.allocate(size); } \
void operator delete(void* pDead, size_t size) { myAlloc.deallocate(pDead, size); } \
protected: \
static allocator_m myAlloc;

//used in class implementation
#define IMPLEMENT_POOL_ALLOC(class_name) \
allocator_m class_name::myAlloc;
class Foo2
{
	DECLARE_POOL_ALLOC();
private:
	long lData;
	string str;
public:
	Foo2(long l) : lData(l) {}


};

IMPLEMENT_POOL_ALLOC(Foo2);

class Goo2
{
	DECLARE_POOL_ALLOC();

private:
	Complex cpl;
	int data;

public:
	Goo2(int i) : data(i) {}
};

IMPLEMENT_POOL_ALLOC(Goo2);


#endif // !__ALLOCATOR_TEST__








