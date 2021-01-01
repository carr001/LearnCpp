#pragma once

#ifndef __CLASS_TEST__
#define __CLASS_TEST__
int class_test1();
int class_test2();
class Complex
{
public:
	Complex(double i, double j) :re(i), im(j) {};//��������治��ͻ
	//Complex(double i = 0, double j = 0) :re(i), im(j) {};//�����������ǳ�ͻ�ģ���   ��� ���C++�ְ��ֽ�ѧ(��) P3 - 27 : 12
	
	Complex() :re(0), im(0) {};
	//Complex(){};
	//~Complex();

	// ������� const�� ��ôʹ��class_test1�� c �����    ��� ���C++�ְ��ֽ�ѧ(��) P4 - 10:10
	//double real(){ return re; };
	//double imag(){ return im; };
	double imag2(int* j) const { (*j)++; return im; };
	int func(const Complex& param) { return param.re + param.im; };//ͬһ����ĸ���object��Ϊ��Ա 	��� ��� P4 - 29:50

	//��� �û�c2+= c1+=c0���������ӣ���ô�����õ�һ�С����Ҫ���ӣ���ôҪ�õڶ���
	/*inline void operator += (const Complex& r) { this->im += r.imag();this->re += r.real();
	};*/
	inline Complex& operator += (const Complex& r) { this->im += r.imag();this->re += r.real(); return *this; };

	double real()const { return re; };
	double imag() const{ return im; };

private:
	double re, im;
};
/****************** ���� �� ����Ӧ���ڲ�ͬ�ļ��� ����LNK1169: �ҵ�һ���������ض���ķ��� �Ľ������**********/
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
	if (*this == str) {//��������
		return *this;
	}
	delete[] m_data;
	m_data = new char[strlen(str.m_data)+1];//ͬһ������ж�����friend
	strcpy(m_data,str.m_data);
	return *this;
}
#endif // !__CLASS_TEST__


