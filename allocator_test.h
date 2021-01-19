//#pragma once
#ifndef __ALLOCATOR_TEST__
#define __ALLOCATOR_TEST__
#include<iostream>
#include"class_test.h"
//#include<cstddef>
using namespace std;
class Screen {// ���Ժ�ݣ��������C++ primer3 p765
public:
	Screen(int x) :id(x) {};
	int get() { return id; };
	void *operator new(size_t size);//��һ������������size_t
	void operator delete(void *,size_t size) ;//��һ������������void *
private://����ʵ���ڴ��������ݣ��൱�ڶ����cost
	Screen* next;//ʹ��allocator��Ҫ���ĵĶ����ڴ�
	static Screen* frontStore;
	static const int screenChunksz;
private://��������
	int id;
};
Screen *Screen::frontStore = 0;
const int Screen::screenChunksz = 24;
void* Screen::operator new(size_t size) {//���size��������new��ʱ����� ��Ĵ�С
	Screen *p;
	if (!frontStore) {//���fontStore����0����ô˵�����ǵ�һ�ε��ã������Ҫ�����ڴ�
		size_t chunk = screenChunksz * size;// size��ʾһ���������screenChunksz��ʾ��Ҫ���ٸ������
		frontStore = p = reinterpret_cast<Screen*>(new char[chunk]);
		for (;p != &frontStore[screenChunksz - 1];p++) {
			p->next = p + 1;
		}
		p->next = 0;//
	}
	p = frontStore;//���������ڴ�Ŀռ�ͷ
	frontStore = frontStore->next;
	return p;
}
void Screen::operator delete(void * p, size_t size) {//û�� free�ڴ棬����Ҳû���ڴ�й©����������ϵͳû���õ�ʣ���ڴ棬�����������ι黹
	(static_cast<Screen*>(p))->next = frontStore;
	frontStore = static_cast<Screen*>(p);
}
//**************** per class allocator 2*********************//
#include <iostream>
#include <cstddef>
using namespace std;
//ref. Effective C++ 2e,item 10
//1.mallocЧ��
//2.cookie����
//per-class allocator,2
class Airplane {
private:
	struct AirplaneRep {//����������
		unsigned long miles;
		char type;
	};
private:
	union {//ʵ�ʵĳ�Ա����������ʱ��next Airplane�ĵ�ַ��������ʱ�� rep
		AirplaneRep rep;  //�˴����ʹ���е�objects
		Airplane* next;  //�����free list�ϵ�object
				//embeded pointer Ƕ��ʽָ��
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
	//�����С����ת����::operator new()
	//�̳���ϵ��
	if (size != sizeof(Airplane)) {
		return ::operator new(size);
	}

	Airplane *p = headOfFreeList;
	if (p) {
		//���p��Ч���Ͱ�listͷ������һ��Ԫ��
		headOfFreeList = p->next;
	}
	else {
		//free list�ǿյģ���������һ���
		Airplane* newBlock = static_cast<Airplane*>
			(::operator new(BLOCK_SIZE * sizeof(Airplane)));

		//��С�鴮��һ��free list,
		//������ #0, ��������������Ϊ���γɹ�
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
	struct obj//��union��ͬ������ֻ����������ת��
	{
		obj* next;	//embeded pointer
	};
public:
	void* allocate(size_t size) {
		obj *p;
		if (!freeStore) {
			freeStore = p = (obj*)malloc(size * CHUNK);

			for (int i = 0; i < CHUNK - 1; ++i) {
				p->next = (obj*)((char*)p + size);// ǰ��������obj struc�Է�����ڴ����ת�͡�
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
	const int CHUNK = 5;	//ÿ�η���Ĵ�С
};
//������ Foo
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

//������ Goo
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








