#pragma once

#ifndef __CLASS_TEST__
#define __CLASS_TEST__
int class_test1();
int class_test2();
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
String::String(const char* cstr) {
	if (cstr) {
		m_data = new char[strlen(cstr)];
		strcpy(m_data,cstr);
	}
	else {
		m_data = new char[1];
		*m_data = '\0';
	}
}
inline String& String::operator=(const String& str) {
	if (*this == str) {//下面会出错
		return *this;
	}
	delete[] m_data;
	m_data = new char[strlen(str.m_data)+1];//同一类的所有对象都是friend
	strcpy(m_data,str.m_data);
	return *this;
}
#endif // !__CLASS_TEST__


