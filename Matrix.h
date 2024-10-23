#pragma once
#include"Vector.h"
class Matrix
{
public:
	friend Matrix qpow(Matrix mt, long long p);//��������ݣ�p����ָ��
	friend ostream& operator<<(ostream& out, const Matrix& m);
	void input();
	Matrix(int Row = 0, int Col = 0);
	Matrix(const Vector<Vector<int>> vec);
	Matrix(const Matrix& mat);
	Matrix& operator =(const Matrix& mat);
	Matrix& operator =(const Vector<Vector<int>> m);
	Vector<int>& operator [](const int pos) const;
	Matrix operator *(const Matrix& mt);
	Matrix& operator *=(const Matrix& mt);
	Vector<int> operator *(const Vector<int>& v) const;
	Matrix operator +(const Matrix mt);
	Matrix& operator +=(const Matrix mt);
	virtual ~Matrix();
	int GetRow()const, GetCol()const;
	void Show() const;
	void get_random();
	void unitizate(int n);//���ɵ�λ��
	void clear();
	Matrix& Reverse();
	Matrix& Get_Hadamard(const Matrix& mt);//������Hadamard��
	Matrix Get_Inversion();//��������
	int Get_Rank();//��������
	Vector<double> Gauss(Vector<int> &vec);
	long long Get_Determinant();//���������ʽ
private:
	int row, col;
	Vector<Vector<int>> data;
};
long long qpow(long long b, long long p);
const long long mod = 1e9 + 7;
const double eps = 1e-6;

