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
		printf("a < b\n");// û����ֹ��������b����
}
void c_test3() {
	cout << "########################### in c_test4 ###################" << endl;
	int a = 3;	int t = 200;
	const int aa=2; //������������һ����
	int const aaa=20; // aaa �ǳ���

	//================== int* const ָ�볣�������ݱ���ɱ䣬ָ�벻�ɱ� ==========//
	int* const b =&a;
	//int* const bb =&aa;
	//int* const bbb =&aaa;
	*b = 2;
	//b = &t;

	//================== int* const������ָ��const����non-constָ�룬ָ��ɱ䣬���ݲ��ɱ� ==========//
	const int* c = &a;
	const int* cc =&aa;
	const int* ccc =&aaa;
	//*c = 2;
	c = &t;
	//*cc = 2;
	cc = &t;

	//================== int const*������ָ��const����non-constָ�룬ָ��ɱ䣬���ݲ��ɱ� ==========//
	int const* d = &a;
	int const* dd = &aa;
	int const* ddd = &aaa;
	//*d = 2;
	d = &t;
	//*dd = 2;
	dd = &t;
	
	//================== int const*������ָ��const����non-constָ�룬ָ��ɱ䣬���ݲ��ɱ� ==========//
	const int* const e = &a;
	const int* const ee = &aa;
	const int* const eee = &aaa;
	//*e = 2;
	//e = &t;
	//*ee = 2;
	//ee = &t;

	// �ܽ᣺
	// 1.�ڶ��͵����������һ���ģ���һ�͵ڶ���������������const��*ǰ����ָ���
	// 2.const��*ǰ����˳��� ����ָ�룬��*��ָ�볣��
	// 3.ָ�루�ģ�������ָ�����ָ��non-const���������ģ�ָ�룬ָ��ָ��û��Ҫ��
}