#include"template_test.h"
#include<iostream>
using namespace std;
int template_test1() {
	cout << "########################### in template_test1 ###################" << endl;
	stone r1(2, 3), r2(3, 3), r3;
	r3 = min(r1, r2);
	return 0;
}
int template_test1() {
	cout << "########################### in template_test2 ###################" << endl;
	cout << hash2<long>()(100);
	vector2<int,int> a();
	vector3<int> b();//×ßclass vector3 {};
	vector3<int*> c();//×ßclass vector3<T*> {};
	return 0;
}


