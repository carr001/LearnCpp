#ifndef __TEMPLETE_TEST__
#define __TEMPLETE_TEST__
class stone
{
public:
	stone() {}
	stone(int w, int h, int we=0)
		:_w(w), _h(h), _weight(we) {
	}
	bool operator< (const stone& rhs) const {
		return _weight < rhs._weight;
	}
private:
	int _w, _h, _weight;
};
template <class T>
inline
const T& min(const T& a, const T& b) {
	return b < a ? b : a;//stone 必须override stone >
}
/**************** member template **************/
// 暂时略过

/**************** specialization **************/
//声明一个类模板
template<class Key>
struct hash2 {};

template<>
struct hash2<char> {
	int operator()(char x) const { return x; }
};
template<>
struct hash2<int> {
	int operator()(int x) const { return x; }
};
template<>
struct hash2<long> {
	int operator()(long x) const { return x; }
};
/**************** partial specialization *****************/
//不管偏特化还是特化，都要先声明模板参数个数
template<typename T,typename Alloc>
class vector2 {};

template<typename Alloc>//个数的偏，如果是这中情况，那么进行特殊处理
class vector2<bool,Alloc> {};

template<typename T>
class vector3 {};

template<typename T>//范围的偏，
class vector3<T*> {};


#endif // !__TEMPLETE_TEST__



