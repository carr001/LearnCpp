//#pragma once
#ifndef __ALLOCATOR_TEST__
#define __ALLOCATOR_TEST__
#include<iostream>
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
void Screen::operator delete(void * p, size_t size) {
	(static_cast<Screen*>(p))->next = frontStore;
	frontStore = static_cast<Screen*>(p);
}
#endif // !__ALLOCATOR_TEST__








