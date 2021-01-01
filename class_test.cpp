#pragma once
#include<iostream>
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
