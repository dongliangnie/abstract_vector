#pragma once
#include "Matrix.h"
#include<iomanip>
Vector<int>& Matrix:: operator[](const int pos) const {
	if (row < 0 || pos >= this->row) {
		throw out_of_range("Row index is out of range");
	}
	return data[pos];
}
void Matrix::input() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> data[i][j];
		}
	}
}
ostream& operator<<(ostream& out, const Matrix& m) {
	for (int i = 0; i < m.GetRow(); i++) {
		out <<"["<<setw(6)<<m.data[i][0];
		for (int j = 1; j < m.GetCol(); j++) {
			out << "," << setw(6) << m.data[i][j];
		}
		out << "]"<<endl;
	}
	return out;
}
//���������
Vector<int> Matrix::operator *(const Vector<int>& v)const {
	if (GetRow() != v.Size()&&GetCol()!=v.Size()) {
		throw invalid_argument("Matrix column count does not match vector size.");
	}
	//��ƥ��
	//������*����
	if (GetRow() == v.Size()) {
		Vector<int> result(GetCol());
		// �Ծ����ÿһ��ִ�е������
		for (int i = 0; i < GetCol(); ++i) {
			int sum = 0;
			for (int j = 0; j < GetRow(); ++j) {
				sum += data[j][i] * v[j];
			}
			result[i] = sum;
		}
		return result;
	}
	//�����*������
	else {
		Vector<int> result(GetRow());
		// �Ծ����ÿһ��ִ�е������
		for (int i = 0; i <GetRow(); ++i) {
			int sum = 0;
			for (int j = 0; j < GetCol(); ++j) {
				sum += data[i][j] * v[j];
			}
			result[i] = sum;
		}
		return result;
	}
}
//�ҳ˾���mt
Matrix Matrix::operator *(const Matrix& mt) {
	if (this->GetCol() != mt.GetRow()) {
		throw invalid_argument("Matrixs does not match .");
	}
	Matrix result(this->row, mt.col);
	for (int i = 0; i < this->row; i++) {
		result[i] = mt * data[i];
	}
	return result;
}
Matrix& Matrix::operator *=(const Matrix& mt) {
	if (GetCol() != mt.GetRow()) {
		throw invalid_argument("Matrixs does not match .");
	}
	Matrix result(this->row, mt.col);
	for (int i = 0; i < this->row; i++) {
		result[i] = mt * data[i];
	}
	*this = result;
	return *this;
}
Matrix Matrix::operator +(const Matrix mt) {
	if (GetCol() != mt.GetCol() || GetRow() != mt.GetRow()) {
		throw invalid_argument("Matrixs does not match .");
	}
	Matrix result(row, col);
	for (int i = 0; i < this->row; i++) {
		result[i] = mt[i] + data[i];
	}
	return result;
}
Matrix& Matrix::operator +=(const Matrix mt) {
	if (GetCol() != mt.GetCol() || GetRow() != mt.GetRow()) {
		throw invalid_argument("Matrixs does not match .");
	}
	for (int i = 0; i < this->row; i++) {
		data[i]+= mt[i];
	}
	return *this;
}
Matrix::Matrix(int Row, int Col) :row(Row), col(Col)
{
	Vector<Vector<int>> temp(row,col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temp[i][j] = 0;
		}
	}
	data = temp;
}
Matrix::Matrix(const Vector<Vector<int>> vec) :row(vec.Size()), col(vec[0].Size())
{
	data.resize(row);
	for (int i = 0; i < row; i++) {
		data[i].resize(col);
		data[i] = vec[i];
	}
}
Matrix::Matrix(const Matrix& mat) :row(mat.row), col(mat.col)
{
	data.resize(row);
	for (int i = 0; i < row; i++) {
		data[i].resize(col);
		data[i] = mat[i];
	}
}
Matrix& Matrix :: operator=(const Matrix& mat)
{
	if (&mat == this)
		return *this;
	if (mat.row <= 0 || mat.col == 0)
	{
		row = col = 0;
		return *this;
	}
	row = mat.row;
	col = mat.col;
	data.resize(row);
	for (int i = 0; i < row; i++) {
		data[i].resize(col);
		data[i] = mat.data[i];
	}
	return *this;
}
Matrix& Matrix::operator =(const Vector<Vector<int>> m) {

	row = m.Size();
	col = m[0].Size();
	data.resize(row);
	for (int i = 0; i < row; i++) {
		data[i].resize(col);
		data[i] = m[i];
	}
	return *this;
}
Matrix::~Matrix()
{

}
int Matrix::GetCol()const
{
	return col;
}
int Matrix::GetRow()const
{
	return row;
}
void Matrix::Show()const
{
	cout << *this;
}
void Matrix::clear() {
	for (int i = 0; i < row; i++)
		data[i].clear();
}
void Matrix::get_random() {
	Vector<int> temp(col);
	srand((unsigned)time(NULL));
	for (int i = 0; i < row; i++) {
		srand((unsigned)time(NULL) + i);
		temp.get_random();
		this->data[i] = temp;
	}
}
//���ɵ�λ��
void Matrix::unitizate(int n) {
	clear();
	row = n, col = n;
	Vector<int> temp(n);
	for (int i = 0; i < row; i++) {	
		for (int i = 0; i < row; i++)
			temp[i] = 0;
		temp[i] = 1;
		this->data[i] = temp;
	}
}
Matrix& Matrix::Reverse() {
	Matrix transposed(col, row);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			transposed[j][i] = data[i][j];
		}
	}
	std::swap(row, col); // �����к��е�����
	data = transposed.data; // ��ת�õľ����滻��ǰ���������
	return *this;
}
Matrix qpow(Matrix mt, long long p) {
	Matrix Ans(mt.GetRow(), mt.GetRow());
	Ans.unitizate(mt.GetRow());
	//cout << Ans << endl;
	while (p) {
		if (p & 1) Ans *= mt;
		mt *= mt;
		p >>= 1;
	}
	return Ans;
}
long long qpow(long long b, long long p) {
	long long Ans = 1;
	while (p) {
		if (p & 1) Ans =(long long)Ans * b%mod;
		b = (long long)b*b%mod;
		p >>= 1;
	}
	return Ans;
}
Matrix& Matrix::Get_Hadamard(const Matrix& mt) {
	if (row != mt.row || col != mt.col) {
		throw invalid_argument("Matrix does not match .");
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			data[i][j] *= mt[i][j];
	}
	return *this;
}
Matrix Matrix::Get_Inversion() {
	long long** A = new long long* [110];
	for (int i = 0; i < 110; i++)
		A[i] = new long long[110];
	//long long A[110][110];
	for (int i = 0; i < 110; ++i) {
		for (int j = 0; j < 110; ++j) {
			A[i][j] = 0;
		}
	}
	//memset(A, 0, sizeof A);
	//for (int i = 0; i < 110; ++i) {
	//	for (int j = 0; j < 110; ++j) {
	//		cout<<A[i][j]<<' ';
	//	}
	//	cout << endl;
	//}
	if (row != col) throw("���󣬷Ƿ��󲻴�������");
	for (int i = 1; i <=row; i++) {
		for (int j = 1; j <= col; j++) {
			A[i][j] = data[i-1][j-1];
			/*cout << A[i][j] << ' ';*/
		}
		for (int j = row + 1; j <= 2 * row; j++) {
			if (i + row == j) A[i][j] = 1;
			else A[i][j] = 0;
		}
	}
	int r, c;
	for (c = 1, r = 1; c <= row; c++) {
		int t = r;
		for (int i = r; i <= row; i++)
			if (abs(A[i][c]) > abs(A[t][c])) t = i;
		if (abs(A[t][c]) == 0) continue;
		for (int i = c; i <= 2 * row; i++)	swap(A[r][i], A[t][i]);
		long long temp1 = qpow(A[r][c], mod - 2);
		for (int i = 2 * row; i >= c; i--) A[r][i] = A[r][i] * temp1 % mod;
		for (int i = r + 1; i <= row; i++) {
			if (abs(A[i][c])) {
				for (int j = 2 * row; j >= c; j--)
					A[i][j] = (A[i][j] - A[i][c] * A[r][j] % mod) % mod;
			}
		}
		r++;
	}
	if (r < row + 1) {
		throw invalid_argument("��������ȣ�������治����");
		for (int i = 0; i < 110; i++)                                  // �ͷ��ڴ�
		{
			delete[] A[i];
		}
		delete[] A;
	}
	else {
		for (int i = row - 1; i >= 1; i--)
			for (int j = i + 1; j <=2 * row; j++) {
				for (int k = row + 1; k <= 2 * row; k++)
					A[i][k] = (A[i][k] - A[i][j] * A[j][k] % mod) % mod;
			}
	/*	for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				cout << A[i][j] << ' ';
			}
			for (int j = row + 1; j <= 2 * row; j++) {
				cout << A[i][j] << ' ';
			}
			cout << endl;
		}*/
		Matrix res(row,row);
		res.data.resize(row);
		for (int i = 1; i <=row; i++) {
			for (int j = row+1; j < 2*row+1; j++) {
				res.data[i-1].resize(row);
				res[i-1][j-row-1] = (A[i][j] + mod) % mod;
			}
		}
		for (int i = 0; i < 110; i++)                                  // �ͷ��ڴ�
		{
			delete[] A[i];
		}
		delete[] A;
		return res;
	}
}
int Matrix::Get_Rank() {
	long long** A = new long long* [110];
	for (int i = 0; i < 110; i++)
		A[i] = new long long[110];
	memset(A, 0, sizeof A);
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			A[i][j] = data[i - 1][j - 1];
		}
	}
	int r, c;
	for (c = 1, r = 1; c <= row; c++) {
		int t = r;
		for (int i = r; i <= row; i++)
			if (abs(A[i][c]) > abs(A[t][c])) t = i;
		if (abs(A[t][c]) == 0) continue;
		for (int i = c; i <= 2 * row; i++)	swap(A[r][i], A[t][i]);
		long long temp1 = qpow(A[r][c], mod - 2);
		for (int i = 2 * row; i >= c; i--) A[r][i] = A[r][i] * temp1 % mod;
		for (int i = r + 1; i <= row; i++) {
			if (abs(A[i][c])) {
				for (int j = 2 * row; j >= c; j--)
					A[i][j] = (A[i][j] - A[i][c] * A[r][j] % mod) % mod;
			}
		}
		r++;
	}
	for (int i = 0; i < 110; i++)                                  // �ͷ��ڴ�
	{
		delete[] A[i];
	}
	delete[] A;
	return r-1;
}
Vector<double> Matrix::Gauss(Vector<int>& vec) {
	Vector<double> res(col);
	double** A = new double* [110];
	for (int i = 0; i < 110; i++)
		A[i] = new double[110];
	if (vec.Size() != row) throw invalid_argument("invalid parament!");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			A[i][j] = data[i][j];
		}
		A[i][col] = vec[i];
	}
	int r, c;
	for (c = 0, r = 0; c < col; c++) {
		//���ҵ�c�о���ֵ���������ڵ���
		int t = r;
		for (int i = r; i < row; i++)
			if (fabs(A[i][c]) > fabs(A[t][c])) t = i;
		//���ĳ��ȫ�㣬����Ҫִ������Ĺ�һ����Ԫ��
		if (fabs(A[t][c]) < eps) continue;
		//����c�о���ֵ���������ڵ��н�������r��
		for (int i = c; i <= col; i++)	swap(A[r][i], A[t][i]);
		//����c�о���ֵ���������ڵ��еĵ�һ������Ԫ��һ��
		for (int i = col; i >= c; i--) A[r][i] /= A[r][c];
		//����c��r�����µ����������㡣
		for (int i = r + 1; i < row; i++) {
			if (fabs(A[i][c]) > eps) {
				for (int j = col; j >= c; j--)
					A[i][j] = A[i][j] - A[i][c] * A[r][j];
			}
		}
		r++;
	}
	if (r < row) {
		throw ("�޽������������");
	}
	else {
		for (int i = row - 1; i >= 0; i--)
			for (int j = i + 1; j < col; j++)
				A[i][col] -= A[i][j] * A[j][col];
		for (int i = 0; i < row; i++) {
			res[i] = A[i][col];
		}
	}
	for (int i = 0; i < 110; i++)                                  // �ͷ��ڴ�
	{
		delete[] A[i];
	}
	delete[] A;
	return res;
}
long long Matrix::Get_Determinant() {
	if (row != col) throw("�Ƿ��󲻴�������ʽ��");
	long long** A = new long long* [110];
	for (int i = 0; i < 110; i++)
		A[i] = new long long[110];
	int flag = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			A[i][j] = data[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = i + 1; j < row; j++) {
			while (A[i][i]) {
				int div = A[j][i] / A[i][i];
				for (int k = i; k < row; k++) {
					A[j][k] = A[j][k] - (long long)A[i][k] * div;
				}
				swap(A[i], A[j]); flag = -flag;
			}
			swap(A[i], A[j]); flag = -flag;
		}
	}
	long long ans=1;
	for (int i = 0; i < row; i++) {
		ans = (long long)ans * A[i][i];
	}
	for (int i = 0;i<110;i++)                                  // �ͷ��ڴ�
	{
		delete[] A[i];
	}
	delete[] A;
	return flag*ans;
}

