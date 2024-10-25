#pragma once
#include"test.h"
#include<conio.h>
#include<Code.h>
#include <cstring>
using namespace std;
int Pos(char ch, const char* str)			// ����ָ���ַ�ch���ַ���str�е��±ꡣ������ʱ����-1
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return i;
	return -1;
}
int Choice(const char* prompt, const char* options)		// �������塣�����ʾ��Ϣprompt������ѡ����ַ������ء�
{
	int key;
	cout << prompt << "[";
	for (int i = 0; options[i] != '\0'; i++)
	{
		if (' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// ѡ��options�еĿɴ�ӡ�ַ�
			cout << options[i] << ' ';
		else														// ѡ��options�еĲ��ֿ����ַ�
		{
			switch (options[i])
			{
			case '\t':   cout << "[Tab] ";   break;					// ѡ���е�Tab�ַ�'\t'����ASCII����9��
			case '\x1b': cout << "[Esc] ";   break;					// ѡ���е�Esc�ַ�'\x1b'����ASCII����27��
			case ' ':    cout << "[Space] "; break;					// ѡ���еĿո��ַ�' '����ASCII����32��
			}
		}
	}
	cout << "\b]: ";					// '\b'�˸�����һ��������һ�����
	do
	{
		key = getch();
	} while (options[0] != '\0' && Pos(key, options) < 0); // ��optionsΪ�ճ���Ϊ0���ַ����������������ƣ�����������Ӧ����optins�С�
	cout << endl;
	return key;
}
void Test_Determine_linear_correlation() {
	cout << "-------------------------------------����������������жϲ���----------------------------------------" << endl;
	cout << "���������ģʽ" << endl;
	cout << "1.��Ҫ�ֶ�����" << endl;
	cout << "2.��Ҫ�������" << endl;
	int select;
	select = Choice("����������ѡ��", "12");
	cout << "����������Ҫ�ж��Ƿ�������ص��������������ĸ���" << endl;
	int vector_num; cin >> vector_num;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >> vector_num;      //��������
	}
	cout << "����������Ҫ�ж��Ƿ�������ص���������������ά��" << endl;
	int vector_dim; cin >> vector_dim;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >> vector_dim;      //��������
	}
	if (select == '1') {
		Matrix mtx(vector_num, vector_dim);
		cout << "������������" << endl;
		mtx.input();
		if (mtx.Get_Rank() == vector_num) {
			cout << "�����������޹�" << endl;
		}
		else {
			cout << "�������������" << endl;
		}
	}
	else if (select == '2') {
		Matrix mtx(vector_num, vector_dim);
		for (int i = 0; i < vector_num; i++) {
			Vector<int> vec(vector_dim);
			vec.get_random();
			mtx[i] = vec;
		}
		cout << "������ɵ�������" << endl;
		cout << mtx;
		if (mtx.Get_Rank() == vector_num) {
			cout << "�����������޹�" << endl;
		}
		else {
			cout << "�������������" << endl;
		}
	}
}
void Test_Matrix_Qpow() {
	cout << "-------------------------------------��������ݲ���----------------------------------------" << endl;
	cout << "                                 ��ܰ��ʾ��ֻ�з��������                              " << endl;
	cout << "���������ģʽ" << endl;
	cout << "1.��Ҫ�ֶ�����" << endl;
	cout << "2.��Ҫ�������" << endl;
	int select;
	select = Choice("����������ѡ��", "12");
	int siz;
	cout << "�����뷽��Ĵ�С:" << endl;
	cin >>siz;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >> siz;      //��������
	}
	int p;
	cout << "��������ָ��" << endl;
	cin >> p;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >> p;      //��������
	}
	Matrix mtx(siz, siz);
	if (select == '1') {
		cout << "�����뷽��" << endl;
		mtx.input();
		cout << "����������㷨�����" << endl;
		cout << qpow(mtx, p);
		cout << "�����ݵ�У��ֵ��" << endl;
		Matrix Ans(siz,siz);
		Ans.unitizate(siz);
		for (int i = 0; i < p; i++) {
			Ans *= mtx;
		}
		cout << Ans;
	}
	else {
		mtx.get_random();
		cout << "������ɵķ���" << endl;
		cout << mtx;
		cout << "����������㷨�����" << endl;
		cout << qpow(mtx, p);
		cout << "�����ݵ�У��ֵ��" << endl;
		Matrix Ans(siz, siz);
		Ans.unitizate(siz);
		for (int i = 0; i < p; i++) {
			Ans *= mtx;
		}
		cout << Ans;
	}
}
void Test_Matrix_Determinant() {
	cout << "-------------------------------------����ʽ������----------------------------------------" << endl;
	cout << "                               ��ܰ��ʾ��ֻ�з����������ʽ                             " << endl;
	cout << "���������ģʽ" << endl;
	cout << "1.��Ҫ�ֶ�����" << endl;
	cout << "2.��Ҫ�������" << endl;
	int select;
	select = Choice("����������ѡ��", "12");
	int siz;
	cout << "�����뷽��Ĵ�С:" << endl;
	cin >> siz;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >> siz;      //��������
	}
	Matrix mtx(siz, siz);
	if (select == '1') {
		cout << "�����뷽��" << endl;
		mtx.input();
		cout << "��������ʽ��ֵ��" << endl;
		cout << mtx.Get_Determinant() << endl;
	}
	else {
		mtx.get_random();
		cout << "������ɵķ���" << endl;
		cout << mtx;
		cout << "��������ʽ��ֵ��" << endl;
		cout << mtx.Get_Determinant() << endl;
	}
}
void Test_Matrix_Rank() {
	cout << "-------------------------------------�������������----------------------------------------" << endl;
	cout << "���������ģʽ" << endl;
	cout << "1.��Ҫ�ֶ�����" << endl;
	cout << "2.��Ҫ�������" << endl;
	int select;
	select = Choice("����������ѡ��", "12");
	cout << "���������Ĺ�ģrow,col:" << endl;
	int rr, cc;
	cin >> rr;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >>rr;      //��������
	}
	cin >> cc;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >> cc;      //��������
	}
	Matrix mtx(rr, cc);
	if (select == '1') {
		cout << "���������" << endl;
		mtx.input();
		cout << "������ȣ�" << endl;
		cout << mtx.Get_Rank() << endl;
	}
	else {
		mtx.get_random();
		cout << "������ɵľ���" << endl;
		cout << mtx;
		cout << "������ȣ�" << endl;
		cout << mtx.Get_Rank() << endl;
	}
}
void Test_Matrix_Gauss() {
	cout << "-------------------------------------���Է�����Ax=b������----------------------------------------" << endl;
	cout << "���������ģʽ" << endl;
	cout << "1.��Ҫ�ֶ�����" << endl;
	cout << "2.��Ҫ�������" << endl;
	int select;
	select = Choice("����������ѡ��", "12");
	cout << "������ϵ������A�Ĺ�ģrow,col:" << endl;
	int rr, cc;
	cin >> rr;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >> rr;      //��������
	}
	cin >> cc;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >> cc;      //��������
	}
	Matrix mtx(rr, cc);
	Vector<int> b(rr);
	if (select == '1') {
		cout << "������b������" << endl;
		b.input(cin);
		while(b.Size() != rr) {
			cout << "���벻�Ϸ����޷�������Է����飡���ٴ�����" << endl;
			b.input(cin);
		}
		cout << "���������ϵ������A��" << endl;
		mtx.input();
		Vector<double> ans=mtx.Gauss(b);
		cout << "��������" << endl;
		ans.output(cout);
	}
	else {
		mtx.get_random();
		cout << "������ɵ�ϵ������A��" << endl;
		cout << mtx;
		cout << "������ɵ�����b��" << endl;
		b.get_random();
		b.output(cout);
		cout << "��������" << endl;
		mtx.Gauss(b).output(cout);
	}
}
void Test_Matrix_Multipy() {
	cout << "======================================����˷�����========================================" << endl;
	cout << "���������ģʽ" << endl;
	cout << "1.��Ҫ�ֶ�����" << endl;
	cout << "2.��Ҫ�������" << endl;
	int select;
	select = Choice("����������ѡ��", "12");
	if (select == '1') {
		cout << "-------------------------------------�����˾������---------------------------------------" << endl;
		cout << "�������������" << endl;
		Vector<int> vec;
		vec.input(cin);
		cout << "��������˾����ά��row,col" << endl;
		int r1, c1; cin >> r1;
		while (cin.fail()) { //����cin��״̬
			cin.clear();     //���cin�Ĵ���״̬
			cin.ignore();    //���Ի����������ݣ�ֱ��EOF
			cout << "�����������������" << endl;
			cin >> r1;      //��������
		}
		cin >> c1;
		while (cin.fail()) { //����cin��״̬
			cin.clear();     //���cin�Ĵ���״̬
			cin.ignore();    //���Ի����������ݣ�ֱ��EOF
			cout << "�����������������" << endl;
			cin >> c1;      //��������
		}
		Matrix mtx1(r1, c1);
		if (vec.Size()!= r1 && vec.Size() != c1) {
			cout << "ά����ƥ�䣬��Ч��" << endl;
		}
		else {
			cout << "��������˾���" << endl;
			mtx1.input();
			cout << "�����˾���Ľ��Ϊ��" << endl;
			cout << mtx1 * vec;
		}
		cout << "-------------------------------------����˾������---------------------------------------" << endl;
		cout << "�������һ�����˾����row,col" << endl;
		int r2, c2, r3, c3;
		cin >> r2 >> c2;
		cout << "������ڶ������˾����row,col" << endl;
		cin >> r3 >> c3;
		Matrix mtx2(r2,c2), mtx3(r3,c3);
		if (c2 != r3 && c3 != r2) {
			cout << "ά����ƥ�䣬��Ч��" << endl;
		}
		else if(c2 == r3){
			cout << "�������һ�����˾���" << endl;
			mtx2.input();
			cout << "������ڶ������˾���" << endl;
			mtx3.input();
			cout << "����1*����2�Ľ����" << endl;
			cout << (mtx2 * mtx3);
		}
		else if (c3 == r2) {
			cout << "�������һ�����˾���" << endl;
			mtx2.input();
			cout << "������ڶ������˾���" << endl;
			mtx3.input();
			cout << "����2*����1�Ľ����" << endl;
			cout << (mtx3 * mtx2);
		}
	}
	else {
		cout << "-------------------------------------�����˾������---------------------------------------" << endl;
		cout << "���������������ά����" << endl;
		int vec_dim; cin >> vec_dim;
		Vector<int> vec(vec_dim);
		vec.get_random();
		cout << "������ɵĴ���������" << endl;
		cout << vec;
		cout << "��������˾����ά��row,col" << endl;
		int r1, c1; cin >> r1;
		while (cin.fail()) { //����cin��״̬
			cin.clear();     //���cin�Ĵ���״̬
			cin.ignore();    //���Ի����������ݣ�ֱ��EOF
			cout << "�����������������" << endl;
			cin >> r1;      //��������
		}
		cin >> c1;
		while (cin.fail()) { //����cin��״̬
			cin.clear();     //���cin�Ĵ���״̬
			cin.ignore();    //���Ի����������ݣ�ֱ��EOF
			cout << "�����������������" << endl;
			cin >> c1;      //��������
		}
		Matrix mtx1(r1, c1);
		if (vec.Size() != r1 && vec.Size() != c1) {
			cout << "ά����ƥ�䣬��Ч��" << endl;
		}
		else {
			cout << "������ɵĴ��˾���" << endl;
			mtx1.get_random();
			cout << mtx1;
			cout << "�����˾���Ľ��Ϊ��" << endl;
			cout << mtx1 * vec;
		}
		cout << "-------------------------------------����˾������---------------------------------------" << endl;
		cout << "�������һ�����˾����row,col" << endl;
		int r2, c2, r3, c3;
		cin >> r2 >> c2;
		cout << "������ڶ������˾����row,col" << endl;
		cin >> r3 >> c3;
		Matrix mtx2(r2, c2), mtx3(r3, c3);
		if (c2 != r3 && c3 != r2) {
			cout << "ά����ƥ�䣬��Ч��" << endl;
		}
		else if (c2 == r3) {
			cout << "������ɵĵ�һ�����˾���" << endl;
			mtx2.get_random();
			cout << mtx2;
			cout << "������ɵĵڶ������˾���" << endl;
			mtx3.get_random();
			cout << mtx3;
			cout << "����1*����2�Ľ����" << endl;
			cout << (mtx2 * mtx3);
		}
		else if (c3 == r2) {
			cout << "������ɵĵ�һ�����˾���" << endl;
			mtx2.get_random();
			cout << mtx2;
			cout << "������ɵĵڶ������˾���" << endl;
			mtx3.get_random();
			cout << mtx3;
			cout << "����2*����1�Ľ����" << endl;
			cout << (mtx3 * mtx2);
		}
	}
}
void Test_Matrix_Inversion() {
	cout << "======================================�����������========================================" << endl;
	cout << "���������ģʽ" << endl;
	cout << "1.��Ҫ�ֶ�����" << endl;
	cout << "2.��Ҫ�������" << endl;
	int select;
	select = Choice("����������ѡ��", "12");
	cout << "����������淽���ά��row=col:" << endl;
	int siz;
	cin >> siz;
	while (cin.fail()) { //����cin��״̬
		cin.clear();     //���cin�Ĵ���״̬
		cin.ignore();    //���Ի����������ݣ�ֱ��EOF
		cout << "�����������������" << endl;
		cin >>siz;      //��������
	}
	Matrix mtx(siz, siz);
	if (select == '1') {
		cout << "������" << siz << "��" << siz << "�еķ���" << endl;
		mtx.input();
		cout << "���������Ϊ��" << endl;
		try {
			cout << mtx.Get_Inversion();
		}
		catch (invalid_argument) {
			cerr << "��������ȣ�������治����" << std::endl;
		}
	}
	else {
		cout << "������ɵķ������£�" << endl;
		mtx.get_random();
		cout << mtx;
		cout << "���������Ϊ��" << endl;
		try {
			cout << mtx.Get_Inversion();
		}
		catch (invalid_argument) {
			cerr <<"��������ȣ�������治����"<< std::endl;
		}
	}
}
void Auto_Test() {
	while (true) {
		int op;
		cout << "�Ƿ�����Զ������ܼ�⣬����������ѡ��0��ʾ�˳�����";
		cin >> op;
		if (op == 0)
			break;
		cout << "�ؼ��ʹ���" << endl;
		ACauto();
		cout << endl;
		cout << "���ļ�⹦��" << endl;
		Manacher();
	}
}


void fRegister() {
	cout << "***������һ��ż��λ��λ��Ϊ3�ı���������****" << endl;
	String  Strreg;
	while (1) {
		cin >> Strreg;
		if (Strreg.size() % 2 == 0) {
			CodeNum2 = 2;
			break;
		}
		else if (Strreg.size() % 3 == 0)
		{
			CodeNum2 = 3;
			break;
		}
		else
		{
			cout << "*******��������벻�Ϸ������������룡*******" << endl;
		}
		//cout << Strreg << endl;
	}
	Code(Strreg, CodeNum1);
	system("pause");
	system("cls");
}
void fChangeCode() {
	cout << "*************��������ĺ������*************" << endl;
	String Strin;
	cin >> Strin;
	changeCode(Strin);
	system("pause");
	system("cls");
}
void fLog() {
	cout << "**************��������������****************" << endl;
	String  Strlog;
	cin >> Strlog;
	JudgeisCorrect(Strlog);
	system("pause");
	system("cls");
}
void fChangeCodeWay() {
	cout << "*********������1��2�Ը��ļ��ܷ�ʽ***********" << endl;
	cin >> CodeNum1;
	cout << "CodeNum1= " << CodeNum1 << endl;
	cout << "******************�������!*****************" << endl;
	system("pause");
	system("cls");
}
void menu() {
	cout << "********************************************" << endl;
	cout << "************  ��ӭʹ��xxxϵͳ��*************" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.ע��          *************" << endl;
	cout << "*************  2.��������      *************" << endl;
	cout << "*************  3.��½          *************" << endl;
	cout << "*************  4.ѡ����ܷ�ʽ  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
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
	return ;
}

