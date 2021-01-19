#include"basic_test.h"
#include"basic_test1.h"
#include<iostream>
#include<vector>

using namespace std;
int basic_test1() {
	//type name ��C++�е��÷� https://www.cnblogs.com/wuchanming/p/3765345.html
    /*���ǻ���һ���ؼ����÷����������������
   1). qualified name
       ����:std::cout, std::endl;�����������������(::)�ľ����޶�����
       ��������using������cout,endl���뵽��ǰ������֮��Ϳ���ֱ��ʹ��
       ���������ƣ����ʱ��cout��endl�Ͳ����޶����ˡ�
   2). dependent name
       dependent name��������ģ�����������,���磺*/
 /*   template <typename T> class X
    {
        int i;
        std::vector<int> ivec;
        std::vector<int>::iterator iter;

        T type;
        std::vector<T> tvec;
        std::vector<T>::iterator titer;
    };*/
    /* ǰ3����Ա�����ǲ�������ģ�����,������non-dependent name,��3����dependent name
    ,ֱ��ʵ������ģ���ʱ��Ż�֪��������ʲô���͡�*/

    //����������typename�ĵڶ����÷������ڼ���������һ�������£�
  /*  template <typename T> class Y
    {
        T::iterator* iter;
        ...
    };*/
    /* ���ǿ��ܱ������붨��һ�������������������������vector<int>��ʵ�������ģ�壬��ôiter
    ��Ӧ����һ��������ָ�룬���ǣ���������������������ʵ�������ģ�壺*/
 /*   class cType
    {
        static int iterator;
    };*/
    /* ��ôT::iterator *iter�ᱻ����������Ϊ��������ˡ���ʵ�ϣ�C++����������õڶ��ֽ��ͷ���
    ����ʹiterator��ȷ��һ����������
    Ϊ�˱�������ì�ܣ�����������qualified dependent name��ʱ����Ҫ��typename��ָ������һ��
    ������.��: */
    //template <typename T> class Y
    //{
    //    typename T::iterator* iter;
    //    typedef typename T::iterator iterator; //������Y::iterator��������
    //    ...
    //};
    //typename ָ����������ŵ�������һ������
    return 0;

}
int Operation(int x, int y, int (*function)(int, int, int)) {
    int z = x + y;
    int result = function(x, y, z);
    result *= 10;
    return result;
}

int basic_test2() {
    // test lambda expression
    /*  //��Դhttps://www.bilibili.com/video/BV1h441117MX?from=search&seid=18246939578687286039
        �﷨ [capture](){};
        [�����������]��ʾһ��lambda���ʽ�Ŀ�ʼ�������������ֻ��ʹ�ö��嵽lambda���ʽʱ�����ڷ�Χ�ڿɼ��ľֲ��������������this��
        [��]����ʹ���κκ����������
        [=]:���ڷ�Χ�����оֲ�������ֵ����
        [&]: ���ڷ�Χ�����оֲ����������ô���
        [this]:�������ڿ���ʹ��������ĳ�Ա
        [a]:��a��ֵ���ݣ����Ҫ�޸�a����ô()������Ҫ����mutable�ؼ���
        [&a]:��a�����ô���s
        []()->int{};��������ֵ����
    */
    // ����
    []() {
    };
    //����
    auto p = [](int i,int j,int z)  {
        cout << "hello" << endl;return 100;
    };
    int res = Operation(2, 3, p);
    return 0;
}

int basic_test3() {
	cout << "GUARD="<< GUARD << endl;
	return 0;
}

int& func(int &a) {
    a++;
    return a;
}
//������������ambigous����Ϊ���Ǿ�����ͬ��ǩ�� same signature��
//double image(const double& im) {}
double image(const double im) { return 0; }

//����const֮����Թ��棬��ΪconstҲ��signature��һ���֣���Ȼ��ֻ�ܴ��������С�
//double image(const double& im) const {}
//double image(const double im) {}
int basic_test4() {
	cout << "####################  in basic_test 4 ##################" << endl;
	// test reference 
    int b = 2;
	int& a = b;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;//�ײ� a��һ��ָ��(���þ���ָ��)�����Ǳ��������һ������reference�Ĵ�С�뱻reference�Ķ�����ͬ���Ӷ��ﵽ��reference b����a��Ч��

    func(b);
    int& c = func(b);
    cout << b << endl;
    cout << c << endl;
    return 0;
}

int basic_test5() {
	cout << "####################  in basic_test 5 ##################" << endl;
	int b = 40;
	int c = 50;
	const int a = 2; //a = 4; error 
	
	const int * const p = &a;
	//int * const p = &a; error 

	//ָ�뱾���Ƿ����ָ����������
	int * const p2 = &b;
	//p2 = &c;// error 
	
	//ָ����ָ�������Ƿ���Ըı�
	*p2 = 6;
	//*p = 1; error
	return 0;
}
int basic_test6() {
	cout << "####################  in basic_test 6 ##################" << endl;
	// range based for (������ʽ���������� foreach) һ���﷨��
	vector<int> a;
	for (int i : {1, 2, 3, 4}) {
		a.push_back(i);
	}
	for (int i : a) {
		cout << i << endl;
	}
	for (int i : a) {// return by value ,��ԭ��������
		i *= 3;
	}
	for (int i : a) { 
		cout << i << endl;
	}
	for (int& i : a) {// return by reference ,��ԭ��������
		i *= 3;
	}
	for (int i : a) {
		cout << i << endl;
	}
	//�ܽ᣺˵���﷨�ǵ������by reference�����ҳ�����by reference�����������Ƿ��޸����ݵ�����
	return 0;
}
int basic_test7() {
	cout << "####################  in basic_test 7 ##################" << endl;
	// reinterpret_cast  ������c��ǿ��ת����ֱ�ӽ�ָ���ֵ���и��ƣ�������Ը���ǿ�Ƹ��ơ�
	int n = 1;
	//c������
	int*p = (int*)n;
	//C++�еȼ�
	//int *p = reinterpret_cast<int*>(n);

	// ��ʽת�� static_cast
	int m = 5;
	int f = 10.00f;
	f = m;//���ڲ������ε�5ת��Ϊ�����ͣ��������ʽת��
	f = static_cast<float>(n);
	return 0;
}

int basic_test8() {
	cout << "####################  in basic_test 8 ##################" << endl;
	// union test  from https://www.youtube.com/watch?v=6uqU9Y578n4
	struct Union1 {
		union 
		{
			float a;
			int b;
		};
	};
	struct Union2 {
		union
		{
			double a;
			int b;
		};
	};
	Union1 s;
	Union2 s2;
	s.a = 2.0f;
	cout << s.a << ", " << s.b << endl;// ���2, 1073741824�������Ǹ���2�����α�ʾ�����⣬union�����������ģ�������struct����Union�У�����ֱ�ӵ�����Ա��������������Ƕȿ���ͨ�����ַ�ʽ����float��int��
	cout << "Union1 size= " << sizeof(s) << endl;
	cout << "Union2 size= " << sizeof(s2) << endl;// ˵��union������ǳ�Ա��ռ�ڴ���������������

	return 0;
}