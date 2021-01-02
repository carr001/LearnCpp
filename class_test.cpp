#pragma once
#include<iostream>
#include<vector>
#include "class_test.h"

using namespace std;
inline Complex operator+(const Complex& r1,const Complex& r2) {
	return Complex(r1.real() + r2.real(), r1.imag() + r2.imag());
}
inline Complex operator+(const double& r1, const Complex& r2) {//д�������ԭ����Ҫ�������ָ���doube�Ӹ��������
	return Complex(r1 + r2.real(), r2.imag());
}
inline bool operator ==(const Complex& r1, const Complex& r2) {
	return r1.real()==r2.real() && r1.imag()==r2.imag();
}
inline Complex operator-(const Complex& r1) {// �˲���ȡ��
	return Complex(-r1.real(), -r1.imag());
}
//��˵���� ��������ִ��cout<<r1<<r2<<endl;��ʱ���Ǵ����ҵ�
ostream& operator <<(ostream& os,const Complex& r1) {
	return os << r1.real() << "+" << r1.imag() << "i" ;
}//<<Ҳ����д��Complex�����棬����ʹ�õ�ʱ���Ҫc1<<cout�����У���Υ������  ���C++�ְ��ֽ�ѧ(��) P6 - 24:24

using namespace std;
//double imag2(int *j) const { (*j)++; return *j; }; �ᱨ���ǳ�Ա��������ʹ���޶���const�����class_test2˵�������������constֻ������Ӧ�Ķ�������
int class_test1() {
	Complex a(2, 2);
	cout << a.real() << " " << a.imag() << endl;

	Complex b;
	cout << b.real() << " " << b.imag() << endl;

	const Complex c;
	cout << c.real() << " " << c.imag() << endl;
	return 0;
}
int class_test2() {
	Complex a(2, 2);
	int i = 100;
	int* j = &i;
	a.imag2(j);
	cout << a.real() << " " << a.imag() << " " << *j << endl;
	return 0;
}
int class_test3() {
	cout << "########################### in class_test3###################" << endl;
	// ������������ܷ�ֱ�ӷ��ʾ�̬��Ա�뾲̬������Ŀǰ����ʧ����
	////cout << Acount::m_rate << endl;
	//Acount::set_rate(0);
	//Acount a;
	////a.m_rate = 1;
	////cout << a.m_rate << endl;

	//a.set_rate(2);
	////cout << Acount::m_rate << endl;
	return 0;
}
int class_test4() {
	cout << "########################### in class_test4 ###################" << endl;
	// ���Ե���singleton Ҳʧ����
	//A::getInstance().setup();
	return 0;
}
void objectplay(void)//ͨ��������������۲����������빹�캯��
{
	Derived d;
}
int class_test5() {
	cout << "########################### in class_test5 ###################" << endl;
	// constructor and deconstructor under inheritance and composition
	objectplay();
	return 0;
}
int class_test6() {
	cout << "########################### in class_test6 ###################" << endl;
	// test bast ��
	//vector<void> a;
	vector<Base> a;
	//int b[10] = { 0 };
	for (int i = 0;i < 10;i++) {
		a.push_back(*(new Derived()));
	}
	//for (int i = 0;i < 10;i++) {
	//	//cout <<typename(i) << " ";
	//	cout << a[i] << endl;
	//}
	return 0;
}

