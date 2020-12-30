#include"para_test.h"

int testjob() {
#pragma omp parallel for num_threads(8)
	//#pragma omp parallel for is cheaper than omp parallel,and can archieve better performance
	for (int i = 0;i < 1000000000;i++) {
		i * i*i*i*i*i*i*i;
	}
	return 0;
}
int testjob2() {
	for (int i = 0;i < 1000000000;i++) {
		i * i*i*i*i*i*i*i;
	}
	return 0;
}
int para_test1() {
	cout << 2 << endl;
	clock_t s, e;
	s = clock();
	testjob();
	cout << "runing time is:" << (double)(clock() - s) / CLOCKS_PER_SEC << endl;
	s = clock();
	testjob2();
	cout << "runing time is:" << (double)(clock() - s) / CLOCKS_PER_SEC << endl;
	return 0;
}