#include"basic_test.h"
#include<iostream>

using namespace std;
int basic_test1() {
	//type name 在C++中的用法 https://www.cnblogs.com/wuchanming/p/3765345.html
    /*但是还有一个关键的用法。首先是两个概念：
   1). qualified name
       例如:std::cout, std::endl;这样含有作用域符号(::)的就是限定名，
       当我们用using声明将cout,endl引入到当前作用域之后就可以直接使用
       这两个名称，这个时候cout，endl就不是限定名了。
   2). dependent name
       dependent name是依赖于模板参数的类型,例如：*/
 /*   template <typename T> class X
    {
        int i;
        std::vector<int> ivec;
        std::vector<int>::iterator iter;

        T type;
        std::vector<T> tvec;
        std::vector<T>::iterator titer;
    };*/
    /* 前3个成员变量是不依赖于模板参数,所以是non-dependent name,后3个是dependent name
    ,直到实例化该模板的时候才会知道到底是什么类型。*/

    //下面来讨论typename的第二种用法。现在假设我们有一个类如下：
  /*  template <typename T> class Y
    {
        T::iterator* iter;
        ...
    };*/
    /* 我们可能本意是想定义一个迭代器对象，例如我们如果用vector<int>来实例化这个模板，那么iter
    则应该是一个迭代器指针，但是，如果我们用下面这个类来实例化这个模板：*/
 /*   class cType
    {
        static int iterator;
    };*/
    /* 那么T::iterator *iter会被编译器解释为两个数相乘。事实上，C++编译器会采用第二种解释方法
    ，即使iterator的确是一个类型名。
    为了避免这种矛盾，当我们适用qualified dependent name的时候，需要用typename来指出这是一个
    类型名.即: */
    //template <typename T> class Y
    //{
    //    typename T::iterator* iter;
    //    typedef typename T::iterator iterator; //定义了Y::iterator类型名称
    //    ...
    //};
    //typename 指出下面紧跟着的名称是一个类型
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
    /*  //来源https://www.bilibili.com/video/BV1h441117MX?from=search&seid=18246939578687286039
        语法 [capture](){};
        [函数对象参数]表示一个lambda表达式的开始，函数对象参数只能使用定义到lambda表达式时，所在范围内可见的局部变量，包括类的this。
        [空]：不使用任何函数对象参数
        [=]:所在范围内所有局部变量，值传递
        [&]: 所在范围内所有局部变量，引用传递
        [this]:函数体内可以使用所在类的成员
        [a]:对a按值传递，如果要修改a，那么()后面需要声明mutable关键字
        [&a]:对a按引用传递s
        []()->int{};声明返回值类型
    */
    // 声明
    []() {
    };
    //运行
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