#pragma once
#include<iostream>
#include "class_test.h"

using namespace std;
int class_test1() {
	Complex a(2, 2);
	cout << a.real() << " "<<a.imag()<<endl;

	Complex b;
	cout << b.real() << " " << b.imag() << endl;

	const Complex c;
	cout << c.real() << " " << c.imag() << endl;
	return 0;
}