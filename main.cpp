#include"test.h"
#include<iostream>
using namespace std;
void Matrix_Test() {
	while (1) {
		cout << "==============================================������Ժ���====================================================" << endl;
		cout << "***********************************************1.����˷�*****************************************************" << endl;
		cout << "***********************************************2.���������***************************************************" << endl;
		cout << "***********************************************3.�������*****************************************************" << endl;
		cout << "***********************************************4.���������ʽ*************************************************" << endl;
		cout << "***********************************************5.����������������ж�*****************************************" << endl;
		cout << "***********************************************6.���Է��������***********************************************" << endl;
		cout << "***********************************************7.�������*****************************************************" << endl;
		cout << "***********************************************8.�˳�����*****************************************************" << endl;
		int select;
		select = Choice("����������ѡ��", "12345678");
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
		cout << "���������ѡ��([0],[1],[2],[3],[4])" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "��л���ʹ�ã��ټ�~" << endl;
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
