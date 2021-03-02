#include<iostream>
#include<stdio.h>
using namespace std;
struct  Worker
{
	int  no;
	char name[20];
};
void c_test1() {
	cout << "########################### in c_test1 ###################" << endl;
	Worker w;
	Worker *p=&w;
	p->no=20;
	(*p).name[0] = 'c';
	(*p).name[5] = '\0';
	puts((const char*)(p->name));
	puts((const char*)(&p->no));
}
void c_test2() {
	cout << "########################### in c_test2 ###################" << endl;
	char* p[10]; char(*p1)[10];
	int a[10];
	printf("%d\n",sizeof(p));
	printf("%d\n",sizeof(p1));
	printf("%d\n",sizeof(a));
}
void c_test3() {
	cout << "########################### in c_test3 ###################" << endl;
	char a[] = "xyz", b[] = { 'x', 'y', 'z' };
	if (strlen(a) > strlen(b))
		printf("a > b\n");
	else if (strlen(a) > strlen(b))
		printf("a == b\n");
	else
		printf("a < b\n");// 没有终止符，所以b更大
}
void c_test3() {
	cout << "########################### in c_test4 ###################" << endl;
	int a = 3;	int t = 200;
	const int aa=2; //这和下面情况是一样的
	int const aaa=20; // aaa 是常数

	//================== int* const 指针常量，内容必须可变，指针不可变 ==========//
	int* const b =&a;
	//int* const bb =&aa;
	//int* const bbb =&aaa;
	*b = 2;
	//b = &t;

	//================== int* const，可以指向const或者non-const指针，指针可变，内容不可变 ==========//
	const int* c = &a;
	const int* cc =&aa;
	const int* ccc =&aaa;
	//*c = 2;
	c = &t;
	//*cc = 2;
	cc = &t;

	//================== int const*，可以指向const或者non-const指针，指针可变，内容不可变 ==========//
	int const* d = &a;
	int const* dd = &aa;
	int const* ddd = &aaa;
	//*d = 2;
	d = &t;
	//*dd = 2;
	dd = &t;
	
	//================== int const*，可以指向const或者non-const指针，指针可变，内容不可变 ==========//
	const int* const e = &a;
	const int* const ee = &aa;
	const int* const eee = &aaa;
	//*e = 2;
	//e = &t;
	//*ee = 2;
	//ee = &t;

	// 总结：
	// 1.第二和第三种情况是一样的，第一和第二第三的区别在于const在*前还是指针后
	// 2.const在*前，按顺序读 常量指针，在*后，指针常量
	// 3.指针（的）常量，指针必须指向non-const，常量（的）指针，指针指向没有要求
}