#include"test.h"
#include<iostream>
using namespace std;
void Matrix_Test() {
	while (1) {
		cout << "==============================================矩阵测试函数====================================================" << endl;
		cout << "***********************************************1.矩阵乘法*****************************************************" << endl;
		cout << "***********************************************2.矩阵快速幂***************************************************" << endl;
		cout << "***********************************************3.矩阵的秩*****************************************************" << endl;
		cout << "***********************************************4.矩阵的行列式*************************************************" << endl;
		cout << "***********************************************5.向量组线性相关性判断*****************************************" << endl;
		cout << "***********************************************6.线性方程组求解***********************************************" << endl;
		cout << "***********************************************7.矩阵的逆*****************************************************" << endl;
		cout << "***********************************************8.退出测试*****************************************************" << endl;
		int select;
		select = Choice("请输入您的选择：", "12345678");
		switch (select) {
		case '1':Test_Matrix_Multipy(); break;
		case '2':Test_Matrix_Qpow(); break;
		case '3':Test_Matrix_Rank(); break;
		case '4':Test_Matrix_Determinant(); break;
		case '5':Test_Determine_linear_correlation(); break;
		case '6':Test_Matrix_Gauss(); break;
		case '7':Test_Matrix_Inversion(); break;
		}
		if (select == '8') break;
		system("pause");
		system("cls");
	}
}
void Code_Test() {
	while (1) {
		menu();
		int choice;
		cout << "请输入你的选择([0],[1],[2],[3],[4])" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "感谢你的使用，再见~" << endl;
			return;
		case 1:
			system("cls");
			fRegister();
			break;
		case 2:
			system("cls");
			fChangeCodeWay();
			break;
		case 3:
			system("cls");
			fLog();
			break;
		case 4:
			system("cls");
			fChangeCodeWay();
			break;
		}
	}
	return;
}

int main() {
	Matrix_Test();
	/*Auto_Test();*/
    /*Code_Test();*/
	return 0;
}
