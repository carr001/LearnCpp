#include<vector>
#include<iostream>
#include<queue>
using namespace std;
void std_test1() {
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	for (vector<int>::iterator i = a.begin();i < a.end();i++)
		cout << *i;
}
int std_test2() {
	int i = 0;
	int* j = &i;
	int& k = i;
	int& p = i;
	return 0;
}
int std_test3() {
	priority_queue<int> pq;
	for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
		pq.push(n);
	//cout << pq[1] << endl;//std中的heap不支持random access
	return 0;
}
int std_test4() {
	vector<int> a{ 1, 2, 3,4};
	swap(a[0],a[3]);
	for (auto i : a) {
		cout << i << endl;
	}
	return 0;
}