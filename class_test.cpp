#pragma once
#include<iostream>
#include "class_test.h"

using namespace std;
inline Complex operator+(const Complex& r1,const Complex& r2) {
	return Complex(r1.real() + r2.real(), r1.imag() + r2.imag());
}
inline Complex operator+(const double& r1, const Complex& r2) {//写在外面的原因是要处理这种复数doube加复数的情况
	return Complex(r1 + r2.real(), r2.imag());
}
inline bool operator ==(const Complex& r1, const Complex& r2) {
	return r1.real()==r2.real() && r1.imag()==r2.imag();
}
inline Complex operator-(const Complex& r1) {// 此操作取反
	return Complex(-r1.real(), -r1.imag());
}
//这说明了 编译器在执行cout<<r1<<r2<<endl;的时候，是从左到右的
ostream& operator <<(ostream& os,const Complex& r1) {
	return os << r1.real() << "+" << r1.imag() << "i" ;
}//<<也可以写在Complex类里面，但是使用的时候就要c1<<cout这样中，很违背常理  侯捷C++手把手教学(上) P6 - 24:24

using namespace std;
//double imag2(int *j) const { (*j)++; return *j; }; 会报错：非成员函数不能使用限定符const。结合class_test2说明，函数后面加const只对所对应的对象有用
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
