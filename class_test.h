#pragma once

#ifndef __CLASS_TEST__
#define __CLASS_TEST__
int class_test1();
class Complex
{
public:
	//Complex(double i = 0, double j = 0) :re(i), im(j) {};//�����������ǳ�ͻ�ģ���   ��� P3 - 27 : 12

	Complex() :re(0), im(0) {};
	//Complex(){};
	//~Complex();
	double real() { return re; };
	double imag() { return im; };

private:
	double re, im;
};
/****************** ���� �� ����Ӧ���ڲ�ͬ�ļ��� ����LNK1169: �ҵ�һ���������ض���ķ��� �Ľ������**********/
//Complex::Complex() {
//}

//Complex::~Complex() {
//}

#endif // !__CLASS_TEST__

