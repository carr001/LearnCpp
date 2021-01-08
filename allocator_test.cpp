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
}
