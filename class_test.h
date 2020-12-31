#pragma once

#ifndef __CLASS_TEST__
#define __CLASS_TEST__
int class_test1();
class Complex
{
public:
	Complex(double i, double j) :re(i), im(j) {};//这个与下面不冲突
	//Complex(double i = 0, double j = 0) :re(i), im(j) {};//这个与下面的是冲突的！！   详见 侯捷 P3 - 27 : 12
	
	Complex() :re(0), im(0) {};
	//Complex(){};
	//~Complex();

	// 如果不加 const， 那么使用class_test1中 c 会出错    详见 侯捷 P4 - 10:10
	//double real(){ return re; };
	//double imag(){ return im; };
	
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

#endif // !__CLASS_TEST__


