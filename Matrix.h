#pragma once
#include"Vector.h"
class Matrix
{
public:
	friend Matrix qpow(Matrix mt, long long p);//矩阵快速幂，p是幂指数
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
	void unitizate(int n);//生成单位阵
	void clear();
	Matrix& Reverse();
	Matrix& Get_Hadamard(const Matrix& mt);//求矩阵的Hadamard积
	Matrix Get_Inversion();//矩阵求逆
	int Get_Rank();//矩阵求秩
	Vector<double> Gauss(Vector<int> &vec);
	long long Get_Determinant();//求方阵的行列式
private:
	int row, col;
	Vector<Vector<int>> data;
};
long long qpow(long long b, long long p);
const long long mod = 1e9 + 7;
const double eps = 1e-6;

