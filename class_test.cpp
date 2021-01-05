#pragma once
#include<iostream>
#include<vector>
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
double Account::m_rate = 0;//不能放在 class_test.h中
int Account::count = 0;//不能放在 class_test.h中
int class_test3() {
	cout << "########################### in class_test3###################" << endl;
	// 测试类与对象能否直接访问静态成员与静态函数，目前测试失败了
	//cout << Acount::m_rate << endl;
	Account::set_rate(0);
	Account a;
	a.m_rate = 0.4;
	cout << a.m_rate << endl;
	cout << a.count << endl;
	Account* b= new Account[10];
	cout << a.count << endl;

	a.set_rate(2);
	//cout << Acount::m_rate << endl;
	return 0;
}
int class_test4() {
	cout << "########################### in class_test4 ###################" << endl;
	// 测试调用singleton 也失败了
	//A::getInstance().setup();
	return 0;
}
void objectplay(void)//通过调用这个函数观察对象的析构与构造函数
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
	// test bast 类
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

int class_test7() {
	cout << "########################### in class_test7 ###################" << endl;
	// test explicit
	Fraction a(3, 5);
	//double d = 4 + a;

	//Fraction d2 = a + 4;
	return 0;
}
int class_test8() {
	cout << "########################### in class_test8 ###################" << endl;
	shared_ptr2<Foo> sp(new Foo);

	// note: 从类内部来看，*sp会调用函数返回一个对象,消耗*。sp->也会调用函数，返回一个指针，那么sp->method就变成了  px method，不合理，因此编译器会自动变成px->method
	Foo f(*sp);// 拷贝构造
	sp->method();
	
	return 0;
}
int class_test9() {
	cout << "########################### in class_test9 ###################" << endl;
	Func myFunc;
	myFunc("helloworld!");//这个对象像函数，与python对比。 定义了一个模型的实例model，然后model(input)就前向传递
	Func ()("helloworld!");//与上面相同，这里定义了一个临时对象
	return 0;
}
int class_test10() {
	cout << "########################### in class_test10 ###################" << endl;
	// test dynamic binding
	// 动态绑定三个条件：指针调用函数；指针向上转型；调用虚函数

	B b;
	A2 a = (A2)b;
	a.vfunc1(); // static binding  call

	A2* pa = new B;//point and upcast 
	pa->vfunc1(); // virtual function   dynamic binding

	pa = &b;//point and upcast 
	pa->vfunc1();// virtual function   dynamic binding
	return 0;
}
