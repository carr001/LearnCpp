#include"basic_test.h"
#include<iostream>

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