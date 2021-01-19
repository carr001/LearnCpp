#include"basic_test.h"
#include"basic_test1.h"
#include<iostream>
#include<vector>

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

int& func(int &a) {
    a++;
    return a;
}
//下面两个函数ambigous，因为它们具有相同的签名 same signature。
//double image(const double& im) {}
double image(const double im) { return 0; }

//假设const之后可以共存，因为const也是signature的一部分，当然，只能存在于类中。
//double image(const double& im) const {}
//double image(const double im) {}
int basic_test4() {
	cout << "####################  in basic_test 4 ##################" << endl;
	// test reference 
    int b = 2;
	int& a = b;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;//底层 a是一个指针(引用就是指针)，但是编译器会给一个假象，reference的大小与被reference的对象相同，从而达到用reference b代表a的效果

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

	//指针本身是否可以指向其他内容
	int * const p2 = &b;
	//p2 = &c;// error 
	
	//指针所指的内容是否可以改变
	*p2 = 6;
	//*p = 1; error
	return 0;
}
int basic_test6() {
	cout << "####################  in basic_test 6 ##################" << endl;
	// range based for (其他方式：迭代器、 foreach) 一个语法糖
	vector<int> a;
	for (int i : {1, 2, 3, 4}) {
		a.push_back(i);
	}
	for (int i : a) {
		cout << i << endl;
	}
	for (int i : a) {// return by value ,对原来起不作用
		i *= 3;
	}
	for (int i : a) { 
		cout << i << endl;
	}
	for (int& i : a) {// return by reference ,对原来起作用
		i *= 3;
	}
	for (int i : a) {
		cout << i << endl;
	}
	//总结：说明语法糖的入参是by reference，而且出参是by reference，给调用者是否修改内容的自由
	return 0;
}
int basic_test7() {
	cout << "####################  in basic_test 7 ##################" << endl;
	// reinterpret_cast  类似于c中强制转换（直接将指针的值进行复制），后果自负。强制复制。
	int n = 1;
	//c语言中
	int*p = (int*)n;
	//C++中等价
	//int *p = reinterpret_cast<int*>(n);

	// 隐式转换 static_cast
	int m = 5;
	int f = 10.00f;
	f = m;//在内部将整形的5转化为浮点型，因此是隐式转换
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
	cout << s.a << ", " << s.b << endl;// 输出2, 1073741824，后者是浮点2的整形表示。另外，union常常是匿名的，出现在struct或者Union中，可以直接当作成员变量，但是这个角度可以通过两种方式处理（float和int）
	cout << "Union1 size= " << sizeof(s) << endl;
	cout << "Union2 size= " << sizeof(s2) << endl;// 说明union分配的是成员中占内存最大者所需的容量

	return 0;
}