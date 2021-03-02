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
	int aa = 3;
	const int a=2; // a 是常数
	int const b=20; // a 是常数

	int const* c =&a; // a 是常量指针
	const int* d =&a; // a 是常量指针
	const int* const e = &a; // a 是常量指针
	int* const e = &aa; // a 是常量指针
	//int* const e = &a; 
	//int* const e = &b; 
	
	d = &b;
	c = &b;
	//*c = 2;
	//*d = 2;
}