#include"allocator_test.h"


int allocator_test1() {
	cout << "####################  in allocator_test 1 ##################" << endl;
	cout << sizeof(Screen) << endl;
	size_t const N = 100;
	Screen*p[N];
	for (int i = 0;i < N;++i) {
		p[i] = new Screen(i);
	}
	for (int i = 0;i < 10;++i) {
		cout<<p[i]<<endl;
	}
	for (int i = 0;i < N;++i) {
		delete p[i];
	}
	return 0;
}
int allocator_test2() {
	cout << "####################  in allocator_test 2 ##################" << endl;
	// allocator with union

	cout << "sizeof(Airplane)" << sizeof(Airplane) << endl;
	size_t const N = 100;
	Airplane* p[N];

	for (int i = 0; i < N; ++i) {
		p[i] = new Airplane;
	}

	p[1]->set(1000, 'A');
	p[5]->set(2000, 'B');
	p[9]->set(500000, 'C');

	for (int i = 0; i < 10; ++i) {
		cout << p[i] << endl;
	}

	cout << p[1]->getType() << " " << p[1]->getMiles() << endl;
	for (int i = 0; i < N; ++i) {
		delete p[i];
		p[i] = NULL;
	}
	return 0;
}
int allocator_test3() {
	cout << "####################  in allocator_test 2 ##################" << endl;
	// static allocator

	Foo* pFoo[100];
	for (int i = 0; i < 100; ++i) {
		pFoo[i] = new Foo(i);
	}

	cout << "sizeof(long) = " << sizeof(long) << endl;	//4
	cout << "sizeof(string) = " << sizeof(string) << endl;	//28
	cout << "sizeof(Foo) = " << sizeof(Foo) << endl;	//32

	for (int i = 0; i < 20; ++i)	//打印20个指针地址
	{
		cout << pFoo[i] << endl;
	}

	for (int i = 0; i < 100; ++i) {
		delete pFoo[i];
	}

	//Goo 类似测试，代码省略
	//...

	system("pause");
	return 0;
}
