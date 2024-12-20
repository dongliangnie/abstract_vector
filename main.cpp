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
			fChangeCode();
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
void tst_auto() {
	cout << "请输入需要判断是否为数字的字符串\n";
	String Num;
	cin >> Num;
	if (Num.isNumber()) {
		cout << "是合法的数字" << endl;
	}
	else {
		cout << "输入了不合法的数字" << endl;
	}
}

int main() {
	while (1) {
		cout << "==============================================抽象向量类项目测试====================================================" << endl;
		cout << "***********************************************1.矩阵板块测试*******************************************************" << endl;
		cout << "***********************************************2.加密解密板块测试***************************************************" << endl;
		cout << "***********************************************3.自动机板块测试*****************************************************" << endl;
		cout << "***********************************************4.有限状态自动机*****************************************************" << endl;
		cout << "***********************************************5.退出***************************************************************" << endl;
		int select;
		select = Choice("请输入您的选择：", "12345");
		switch (select) {
		case '1':Matrix_Test(); break;
		case '2':Code_Test(); break;
		case '3':Auto_Test(); break;
		case '4':tst_auto(); break;
		}
		if (select == '5') break;
		system("pause");
		system("cls");
	}
	return 0;
}
