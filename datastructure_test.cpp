#include<iostream>
#include<vector>
#include "datastructure_test.h"
using namespace std;
template<class T>
class MyHeap {
public:
	MyHeap(T*, int);// T is assumed to have size attr.

	int BuildMaxHeap();
	int ExtraMax();
	int ExtraMin();
	int Heapfy();
private:
	int numEle;
	vector<int> a;
};
template<class T>
MyHeap<T>::MyHeap(T* t, int length) {

}
template<class T>
int MyHeap<T>::BuildMaxHeap() {

}


