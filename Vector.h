#pragma once
#include"Vec.h"
using namespace std;
template<typename Elem>
class Vector :
	public Vec<Elem>
{
public:
	template<typename Elem> friend ostream& operator<<(ostream& out, const Vector<Elem>& vec);
	template<typename Elem> friend istream& operator>>(ostream& in, const Vector<Elem>& vec);
	Vector(int size = 0, const Elem *x = NULL) :Vec<Elem>(size, x) {}
	Vector(int size,const Elem& e):Vec<Elem>(size,e){}
	void output(ostream& out)const ;
	void input(istream& in);
	void get_random();
	Vector<Elem> operator + (const Vector<Elem> vec);
	Vector<Elem>& operator += (const Vector<Elem> vec);
	Vector<Elem> operator - (const Vector<Elem> vec);
	Vector<Elem>& operator -= (const Vector<Elem> vec);
	void push_back(const Elem& e);
	void pop_back();
	void insert(int index,const Elem& e);
	void erase(int index);
	void erase(int l, int r);
	void clear();
	int Size()const;
	int capacity()const;
};
template<typename Elem>
inline void Vector<Elem>::output(ostream& out) const
{
	if (this->num == 0) {
		out << 0 << endl;
	}
	else {
		cerr << "向量维数：" << endl;
		out << this->num << endl;
		out << this->elems[0];
		for (int i = 1; i < this->num; i++) {
			out << " " << this->elems[i];
		}out << endl;
	}
}
template<typename Elem> 
ostream& operator<<(ostream& out, const Vector<Elem>& vec) {
	out << "(" << vec[0];
	for (int i = 1; i < vec.Size(); i++) {
		out << "," << vec[i];
	}out << ")"<<endl;
	return out;
}
template<typename Elem> 
istream& operator>>(ostream& in, const Vector<Elem>& vec) {
	for (int i = 0; i < vec.Size(); i++) {
		in >> e;
		vec[i] = e;
	}
	return in;
}
template<typename Elem>
inline void Vector<Elem>::get_random() {
	for (int i = 0; i < Size(); i++) {
		elems[i] = rand() % 201 - 100;//生成[-100,100]范围的随机数
	}
}
template<typename Elem>
inline void Vector<Elem>::input(istream& in)
{
	int nm;
	cerr << "请输入向量维数：" << endl;
	in >> nm;
	Elem e;
	__super::resize(nm);
	cerr << "请输入向量：" << endl;
	for (int i = 0; i < this->num; i++) {
		in >> e;
		this->elems[i] = e;
	}
}
template<typename Elem>
Vector<Elem> Vector<Elem>::operator + (const Vector<Elem> vec) {
	if (vec.Size() != this->Size()) {
		throw invalid_argument("Vectors does not match .");
	}
	else {
		Vector<int> result(vec.Size());
		for (int i = 0; i < vec.Size(); i++)
			result[i] = this->elems[i]+vec[i];
		return result;
	}
}
template<typename Elem>
Vector<Elem>& Vector<Elem>::operator += (const Vector<Elem> vec) {
	if (vec.Size() != this->Size()) {
		throw invalid_argument("Vectors does not match .");
	}
	else {
		for (int i = 0; i < vec.Size(); i++)
			this->elems[i]+=vec[i];
	}
	return *this;
}
template<typename Elem>
Vector<Elem> Vector<Elem>::operator - (const Vector<Elem> vec) {
	if (vec.Size() != this->Size()) {
		throw invalid_argument("Vectors does not match .");
	}
	else {
		Vector<int> result(vec.Size());
		for (int i = 0; i < vec.Size(); i++)
			result[i] = this->elems[i] - vec[i];
		return result;
	}
}
template<typename Elem>
Vector<Elem>& Vector<Elem>:: operator -= (const Vector<Elem> vec) {
	if (vec.Size() != this->Size()) {
		throw invalid_argument("Vectors does not match .");
	}
	else {
		for (int i = 0; i < vec.Size(); i++)
			this->elems[i] -= vec[i];
	}
	return *this;
}
template<typename Elem>
inline void Vector<Elem>::push_back(const Elem& e)
{
	if (this->num < this->_size) {
		this->elems[this->num] = e;
		this->num++;
	}else {
		this->resize(this->_size + this->_size / 2+1);
		this->elems[this->num] = e;
		this->num++;
	}
}

template<typename Elem>
inline void Vector<Elem>::pop_back()
{
	if (this->num == 0) return;
	this->num--;
}

template<typename Elem>
inline void Vector<Elem>::insert(int index, const Elem& e)
{
	if (this->num == this->_size) {
		this->resize(this->_size + this->_size / 2 + 1);
	}
	if (index<0 || index>__super::num) throw "invalid";
	for (int i = this->num; i >= index; i--) {
		__super::elems[i + 1] =this->elems[i];
	}
	this->elems[index] = e;
	this->num++;
}

template<typename Elem>
inline void Vector<Elem>::erase(int index)
{
	if (index<0 || index>this->num - 1) throw "invalid";
	for (int i = index; i < this->num - 1; i++) {
		this->elems[i] = this->elems[i + 1];
	}
}
template<typename Elem>
inline void Vector<Elem>::erase(int l,int r)
{
	if (l<0 || r<0 || l>this->num - 1||r>this->num-1) throw invalid_argument("l or r is invalid .");
	for (int i = l; i <= r; i++) {
		erase(i);
	}
}
template<typename Elem>
inline void Vector<Elem>::clear() {
	erase(0, Size() - 1);
}
template<typename Elem>
inline int Vector<Elem>::Size() const
{
	return this->num;
}

template<typename Elem>
inline int Vector<Elem>::capacity() const
{
	return this->_size;
}
