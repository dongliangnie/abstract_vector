#pragma once
#include<iostream>
using namespace std;

template<typename Elem>
class Vec
{
public:
	Vec(int size = 0,const Elem * a = NULL);
	Vec(int size, const Elem& e);
	Vec(const Vec<Elem>& v);
	virtual ~Vec();
	Vec<Elem>& operator=(const Vec<Elem>& v);
	Elem& operator[](int index)const;
	void resize(int size);
	virtual void output(ostream& out) const {
	};
	virtual void input(istream& in) {
	};
protected:
	int num;
	int _size;
	Elem* elems;
};



template<typename Elem>
inline Vec<Elem>::Vec(int size, const Elem* a)
{
	if (size > 0) num = size,_size=size;
	else num = 0,_size=0;
	elems = NULL;
	if (num) {
		elems = new Elem[size];
		if (a != NULL) {
			for (int i = 0; i < size; i++) {
				elems[i] = a[i];
			}
		}
	}
}

template<typename Elem>
inline Vec<Elem>::Vec(int size, const Elem& e)
{
	if (size > 0) num = size, _size = size;
	else num = 0, _size = 0;
	elems = NULL;
	if(size) elems = new Elem[size];
	for (int i = 0; i < num; i++) {
		elems[i] = e;
	}
}

template<typename Elem>
inline Vec<Elem>::Vec(const Vec<Elem>& v)
{
	num = v.num;
	_size = v._size;
	elems = NULL;
	if (num) {
		elems = new Elem[num];
		if (v.elems != NULL) {
			for (int i = 0; i < v.num; i++){
				elems[i] = v.elems[i];
			}
		}
	}
}

template<typename Elem>
inline Vec<Elem>::~Vec()
{
	if (elems != NULL) delete[] elems;
}

template<typename Elem>
inline Vec<Elem>& Vec<Elem>::operator=(const Vec& v)
{
	if (num != v.num) {
		if (elems != NULL) delete[] elems;
		elems = new Elem[v._size];
		num = v.num;
		_size = v._size;
	}
	for (int i = 0; i < num; i++) {
		this->elems[i] = v.elems[i];
	}
	return *this;
}

template<typename Elem>
inline Elem& Vec<Elem>::operator[](int index)const
{
	if (index >= num) throw "overflow";
	return elems[index];
}

template<typename Elem>
inline void Vec<Elem>::resize(int size)
{
	if (size > num) {
		Elem * tmp = new Elem[max(_size, size)];//将数组复制一遍
		for (int i = 0; i <num; i++) {
			tmp[i] = elems[i];
		}
		delete[]elems;
		elems = new Elem[max(_size, size)];
		for (int i = 0; i < num; i++) {
			elems[i] = tmp[i];
		}
		delete[]tmp;
		tmp = nullptr;
		num = size;
	}
	else if (size < num) {
		Elem * tmp = new Elem[_size];
		for (int i = 0; i < size; i++) {
			tmp[i] = elems[i];
		}
		delete[] elems; elems = NULL;
		elems = new Elem[_size];
		for (int i = 0; i < size; i++) {
			elems[i] = tmp[i];
		}
		delete[] tmp;
		tmp = nullptr;
		num = size;
	}
}
template<typename Elem> ostream& operator<<(ostream& out,Vec<Elem> v) {
	v.output(out);
	return out;
}

template<typename Elem> istream& operator>>(istream& in,Vec<Elem> v) {
	v.input(in);
	return in;
}
//#pragma once
//#include<iostream>
//using namespace std;
//
//template<typename Elem>
//class Vec
//{
//public:
//	Vec(int size = 0, const Elem* a = NULL);
//	Vec(int size, const Elem& e);
//	Vec(const Vec<Elem>& v);
//	virtual ~Vec();
//	Vec<Elem>& operator=(const Vec<Elem>& v);
//	Elem& operator[](int index);
//	void resize(int size);
//	virtual void output(ostream& out) const;
//	virtual void input(istream& in);
//protected:
//	int num;
//	int _size;
//	Elem* elems;
//};
//
//
//
//template<typename Elem>
//inline Vec<Elem>::Vec(int size, const Elem* a)
//{
//	if (size > 0) num = size, _size = size;
//	else num = 0, _size = 0;
//	elems = NULL;
//	if (num) {
//		elems = new Elem[size];
//		if (a != NULL) {
//			for (int i = 0; i < size; i++) {
//				elems[i] = a[i];
//			}
//		}
//	}
//}
//
//template<typename Elem>
//inline Vec<Elem>::Vec(int size, const Elem& e)
//{
//	if (size > 0) num = size, _size = size;
//	else num = 0, _size = 0;
//	elems = NULL;
//	if (size) elems = new Elem[size];
//	for (int i = 0; i < num; i++) {
//		elems[i] = e;
//	}
//}
//
//template<typename Elem>
//inline Vec<Elem>::Vec(const Vec<Elem>& v)
//{
//	num = v.num;
//	_size = v._size;
//	elems = NULL;
//	if (num) {
//		elems = new Elem[num];
//		if (v.elems != NULL) {
//			for (int i = 0; i < v.num; i++) {
//				elems[i] = v.elems[i];
//			}
//		}
//	}
//}
//
//template<typename Elem>
//inline Vec<Elem>::~Vec()
//{
//	if (elems != NULL) delete[] elems;
//}
//
//template<typename Elem>
//inline Vec<Elem>& Vec<Elem>::operator=(const Vec& v)
//{
//	if (num != v.num || _size != v._size) {
//		if (elems != NULL) delete[] elems;
//		elems = new Elem[v._size];
//		num = v.num;
//		_size = v._size;
//	}
//	for (int i = 0; i < num; i++) {
//		elems[i] = v.elems[i];
//	}
//	return *this;
//}
//
//template<typename Elem>
//inline Elem& Vec<Elem>::operator[](int index)
//{
//	if (index >= num) throw "overflow";
//	return elems[index];
//}
//
//template<typename Elem>
//inline void Vec<Elem>::resize(int size)
//{
//	if (size > num) {
//		Elem* tmp = new Elem[max(_size, size)];//将数组复制一遍
//		for (int i = 0; i < num; i++) {
//			tmp[i] = elems[i];
//		}
//		delete[]elems;
//		elems = new Elem[max(_size, size)];
//		for (int i = 0; i < num; i++) {
//			elems[i] = tmp[i];
//		}
//		delete[]tmp;
//		tmp = nullptr;
//		num = size;
//		_size = size;
//	}
//	else if (size < num) {
//		Elem* tmp = new Elem[_size];
//		for (int i = 0; i < size; i++) {
//			tmp[i] = elems[i];
//		}
//		delete[] elems; elems = NULL;
//		elems = new Elem[_size];
//		for (int i = 0; i < size; i++) {
//			elems[i] = tmp[i];
//		}
//		delete[] tmp;
//		tmp = nullptr;
//		num = size;
//		_size = size;
//	}
//}
//
//template<typename Elem> ostream& operator<<(ostream& out, Vec<Elem> v) {
//	v.output(out);
//	return out;
//}
//
//template<typename Elem> istream& operator>>(istream& in, Vec<Elem> v) {
//	v.input(in);
//	return in;
//}

