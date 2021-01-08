//#pragma once
#ifndef __ALLOCATOR_TEST__
#define __ALLOCATOR_TEST__
#include<iostream>
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
void Screen::operator delete(void * p, size_t size) {
	(static_cast<Screen*>(p))->next = frontStore;
	frontStore = static_cast<Screen*>(p);
}
#endif // !__ALLOCATOR_TEST__








