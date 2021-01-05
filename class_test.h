#pragma once

#ifndef __CLASS_TEST__
#define __CLASS_TEST__
#include<iostream>
#include<string>//cout输出string需要包含头文件
using namespace std;

int class_test1();
int class_test2();
int class_test3();
int class_test4();
int class_test5();
int class_test6();
int class_test7();
int class_test8();
int class_test9();
int class_test10();
int class_test11();
class Complex
{
public:
	Complex(double i, double j) :re(i), im(j) {};//这个与下面不冲突
	//Complex(double i = 0, double j = 0) :re(i), im(j) {};//这个与下面的是冲突的！！   详见 侯捷C++手把手教学(上) P3 - 27 : 12
	
	Complex() :re(0), im(0) {};
	//Complex(){};
	//~Complex();

	// 如果不加 const， 那么使用class_test1中 c 会出错    详见 侯捷C++手把手教学(上) P4 - 10:10
	//double real(){ return re; };
	//double imag(){ return im; };
	double imag2(int* j) const { (*j)++; return im; };
	int func(const Complex& param) { return param.re + param.im; };//同一个类的各个object互为友员 	详见 侯捷 P4 - 29:50

	//如果 用户c2+= c1+=c0这样的连加，那么可以用第一行。如果要连加，那么要用第二行
	/*inline void operator += (const Complex& r) { this->im += r.imag();this->re += r.real();
	};*/
	inline Complex& operator += (const Complex& r) { this->im += r.imag();this->re += r.real(); return *this; };

	double real()const { return re; };
	double imag() const{ return im; };

private:
	double re, im;
};
/****************** 声明 与 定义应该在不同文件下 否则：LNK1169: 找到一个或多个多重定义的符号 的解决方案**********/
//Complex::Complex() {
//}

//Complex::~Complex() {
//}
/***********************String class**********************/

class String {
public:
	String(const char* cstr = 0);
	String(const String& str);
	String& operator = (const String& str);
	bool operator == (const String& str);
	~String();
	char* get_c_str()  const { return m_data; }
private:
	char* m_data;
};
//String::String(const char* cstr) {
//	if (cstr) {
//		m_data = new char[strlen(cstr)];
//		strcpy(m_data,cstr);
//	}
//	else {
//		m_data = new char[1];
//		*m_data = '\0';
//	}
//}
//inline String& String::operator=(const String& str) {
//	if (*this == str) {//下面会出错
//		return *this;
//	}
//	delete[] m_data;
//	m_data = new char[strlen(str.m_data)+1];//同一类的所有对象都是friend
//	strcpy(m_data,str.m_data);
//	return *this;
//}
/***********************Account class**********************/
class Account {
public:
	static double m_rate;
	static int count;
	static int getm_rate() { return m_rate; };
	static void set_rate(const double& x) { m_rate = x; };
	Account() { count++; }
private:

};
//static double m_rate = 0;
// int class_test_var = 2;不能
/**********************class A for singleton***********************/
class A {
public:
	static A& getInstance() {
		static A a;
		return a; };
	void setup() const{ cout << "hello singleton" << endl; }
private:
	A();
	A(const A& rhs);
};
/************ constructor and deconstructor under inheritance and composition***************/
class Base
{
public:
	Base() {
		cout << "ctor of base" << endl;
	}
	~Base() {
		cout << "dtor of base" << endl;
	}
};
class Component
{
public:
	Component() {
		cout << "ctor of component" << endl;
	}
	~Component() {
		cout << "dtor of component" << endl;
	}
};
class Derived : public Base
{
public:
	Derived() {
		cout << "ctor of derived" << endl;
	}
	~Derived() {
		cout << "dtor of derived" << endl;
	}
protected:
	Component c;
private:
};
/************ explict ***************/
class Fraction {
public:
	//Fraction(int num,int dem=1);
	//Fraction(int num, int dem = 1) { m_numerator = num; m_domenator = dem; };//有多个运算符 "+" 与这些操作数匹配:“Fraction::operator +”: 2 个重载有相似的转换	x
	explicit Fraction(int num, int dem = 1) { m_numerator = num; m_domenator = dem; };// 无法从“double”转换为“Fraction”

	//explicit Fraction(double num, double dem = 1) { m_numerator = num; m_domenator = dem; };
	operator double()const { return (double)m_numerator / m_domenator; };
	Fraction operator+(Fraction const &rhs) { return Fraction(2, 3); };
	//Fraction operator+(int const &rhs) { return Fraction(2, 3); };
private:
	int m_numerator;
	int m_domenator;
};
/************ pointer like class ***************/
struct Foo {
//public:
	//Foo() {  }
	void method() { cout << "hello Foo" << endl; }
};
template<class T>
class shared_ptr2 {//如果是shared_ptr，那么 error 2872:不明确的符号 因为命名空间中已经由shared_ptr了
public:
	T& operator*()const { return *px; };
	T* operator->()const { return px; };
	shared_ptr2(T* p) :px(p) {};
private:
	T* px;
	long * pn;
};

//template <class T, class Ref， class Ptr>
//struct __list_iterator { //这是一个链表
//	typedef __list_iterator<T, Ref， Ptr> self;
//	typedef Ptr pointer;
//	typedef Ref pointer;
//	typedef __list_node<T>* link_type;
//	link_type node;
//	bool operator==(const self& x) const { return node == x.node; }
//	bool operator==(const self& x) const { return node != x.node; }
//	reference operator*() const { return (*node).data; }
//	pointer operator-> const { return &(operator*())}
//	self& operator++() { node = (link_type)((*node).next); return *this }
//	self& operator++(int) { self tmp = *this; ++*this; return tmp; }
//	self& operator--() { node = (link_type)((*node).prep); return *this }
//	self& operator--(int) { self tmp = *this; --*this; return tmp; }
//};

class Func {
public:
	void operator() (const string& str) const {
		cout << str << endl;
	}
};
/*****************Dynamic binding****************/
class A2 {
public:
	virtual void vfunc1()const {};
	virtual void vfunc2()const {};

	void func1() {};
	void func2() {};

};
class B :public A2 {
public:
	virtual void vfunc1()const {};
	void func2() {};
};
class C :public B {
public:
	virtual void vfunc1()const {};
	void func2() {};
};
#endif // !__CLASS_TEST__


