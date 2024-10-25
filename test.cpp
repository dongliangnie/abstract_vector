#pragma once
#include"test.h"
#include<conio.h>
#include<Code.h>
#include <cstring>
using namespace std;
int Pos(char ch, const char* str)			// 返回指定字符ch在字符串str中的下标。不存在时返回-1
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return i;
	return -1;
}
int Choice(const char* prompt, const char* options)		// 函数定义。输出提示信息prompt，输入选择的字符并返回。
{
	int key;
	cout << prompt << "[";
	for (int i = 0; options[i] != '\0'; i++)
	{
		if (' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// 选项options中的可打印字符
			cout << options[i] << ' ';
		else														// 选项options中的部分控制字符
		{
			switch (options[i])
			{
			case '\t':   cout << "[Tab] ";   break;					// 选项中的Tab字符'\t'（即ASCII编码9）
			case '\x1b': cout << "[Esc] ";   break;					// 选项中的Esc字符'\x1b'（即ASCII编码27）
			case ' ':    cout << "[Space] "; break;					// 选项中的空格字符' '（即ASCII编码32）
			}
		}
	}
	cout << "\b]: ";					// '\b'退格。先退一格，在输出右花括号
	do
	{
		key = getch();
	} while (options[0] != '\0' && Pos(key, options) < 0); // 若options为空长度为0的字符串，则输入无限制；否则输入项应该在optins中。
	cout << endl;
	return key;
}
void Test_Determine_linear_correlation() {
	cout << "-------------------------------------向量组线性相关性判断测试----------------------------------------" << endl;
	cout << "请输入测试模式" << endl;
	cout << "1.我要手动输入" << endl;
	cout << "2.我要随机生成" << endl;
	int select;
	select = Choice("请输入您的选择", "12");
	cout << "请输入您所要判断是否线性相关的向量组中向量的个数" << endl;
	int vector_num; cin >> vector_num;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >> vector_num;      //重新输入
	}
	cout << "请输入您所要判断是否线性相关的向量组中向量的维数" << endl;
	int vector_dim; cin >> vector_dim;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >> vector_dim;      //重新输入
	}
	if (select == '1') {
		Matrix mtx(vector_num, vector_dim);
		cout << "请输入向量组" << endl;
		mtx.input();
		if (mtx.Get_Rank() == vector_num) {
			cout << "向量组线性无关" << endl;
		}
		else {
			cout << "向量组线性相关" << endl;
		}
	}
	else if (select == '2') {
		Matrix mtx(vector_num, vector_dim);
		for (int i = 0; i < vector_num; i++) {
			Vector<int> vec(vector_dim);
			vec.get_random();
			mtx[i] = vec;
		}
		cout << "随机生成的向量组" << endl;
		cout << mtx;
		if (mtx.Get_Rank() == vector_num) {
			cout << "向量组线性无关" << endl;
		}
		else {
			cout << "向量组线性相关" << endl;
		}
	}
}
void Test_Matrix_Qpow() {
	cout << "-------------------------------------矩阵快速幂测试----------------------------------------" << endl;
	cout << "                                 温馨提示：只有方阵才有幂                              " << endl;
	cout << "请输入测试模式" << endl;
	cout << "1.我要手动输入" << endl;
	cout << "2.我要随机生成" << endl;
	int select;
	select = Choice("请输入您的选择", "12");
	int siz;
	cout << "请输入方阵的大小:" << endl;
	cin >>siz;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >> siz;      //重新输入
	}
	int p;
	cout << "请输入幂指数" << endl;
	cin >> p;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >> p;      //重新输入
	}
	Matrix mtx(siz, siz);
	if (select == '1') {
		cout << "请输入方阵：" << endl;
		mtx.input();
		cout << "矩阵快速幂算法输出：" << endl;
		cout << qpow(mtx, p);
		cout << "矩阵幂的校验值：" << endl;
		Matrix Ans(siz,siz);
		Ans.unitizate(siz);
		for (int i = 0; i < p; i++) {
			Ans *= mtx;
		}
		cout << Ans;
	}
	else {
		mtx.get_random();
		cout << "随机生成的方阵：" << endl;
		cout << mtx;
		cout << "矩阵快速幂算法输出：" << endl;
		cout << qpow(mtx, p);
		cout << "矩阵幂的校验值：" << endl;
		Matrix Ans(siz, siz);
		Ans.unitizate(siz);
		for (int i = 0; i < p; i++) {
			Ans *= mtx;
		}
		cout << Ans;
	}
}
void Test_Matrix_Determinant() {
	cout << "-------------------------------------行列式求解测试----------------------------------------" << endl;
	cout << "                               温馨提示：只有方阵才有行列式                             " << endl;
	cout << "请输入测试模式" << endl;
	cout << "1.我要手动输入" << endl;
	cout << "2.我要随机生成" << endl;
	int select;
	select = Choice("请输入您的选择", "12");
	int siz;
	cout << "请输入方阵的大小:" << endl;
	cin >> siz;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >> siz;      //重新输入
	}
	Matrix mtx(siz, siz);
	if (select == '1') {
		cout << "请输入方阵：" << endl;
		mtx.input();
		cout << "方阵行列式的值：" << endl;
		cout << mtx.Get_Determinant() << endl;
	}
	else {
		mtx.get_random();
		cout << "随机生成的方阵：" << endl;
		cout << mtx;
		cout << "方阵行列式的值：" << endl;
		cout << mtx.Get_Determinant() << endl;
	}
}
void Test_Matrix_Rank() {
	cout << "-------------------------------------矩阵的秩求解测试----------------------------------------" << endl;
	cout << "请输入测试模式" << endl;
	cout << "1.我要手动输入" << endl;
	cout << "2.我要随机生成" << endl;
	int select;
	select = Choice("请输入您的选择", "12");
	cout << "请输入矩阵的规模row,col:" << endl;
	int rr, cc;
	cin >> rr;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >>rr;      //重新输入
	}
	cin >> cc;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >> cc;      //重新输入
	}
	Matrix mtx(rr, cc);
	if (select == '1') {
		cout << "请输入矩阵：" << endl;
		mtx.input();
		cout << "矩阵的秩：" << endl;
		cout << mtx.Get_Rank() << endl;
	}
	else {
		mtx.get_random();
		cout << "随机生成的矩阵：" << endl;
		cout << mtx;
		cout << "矩阵的秩：" << endl;
		cout << mtx.Get_Rank() << endl;
	}
}
void Test_Matrix_Gauss() {
	cout << "-------------------------------------线性方程组Ax=b求解测试----------------------------------------" << endl;
	cout << "请输入测试模式" << endl;
	cout << "1.我要手动输入" << endl;
	cout << "2.我要随机生成" << endl;
	int select;
	select = Choice("请输入您的选择", "12");
	cout << "请输入系数矩阵A的规模row,col:" << endl;
	int rr, cc;
	cin >> rr;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >> rr;      //重新输入
	}
	cin >> cc;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >> cc;      //重新输入
	}
	Matrix mtx(rr, cc);
	Vector<int> b(rr);
	if (select == '1') {
		cout << "请输入b向量：" << endl;
		b.input(cin);
		while(b.Size() != rr) {
			cout << "输入不合法，无法求解线性方程组！请再次输入" << endl;
			b.input(cin);
		}
		cout << "请输入矩阵系数矩阵A：" << endl;
		mtx.input();
		Vector<double> ans=mtx.Gauss(b);
		cout << "解向量：" << endl;
		ans.output(cout);
	}
	else {
		mtx.get_random();
		cout << "随机生成的系数矩阵A：" << endl;
		cout << mtx;
		cout << "随机生成的向量b：" << endl;
		b.get_random();
		b.output(cout);
		cout << "解向量：" << endl;
		mtx.Gauss(b).output(cout);
	}
}
void Test_Matrix_Multipy() {
	cout << "======================================矩阵乘法测试========================================" << endl;
	cout << "请输入测试模式" << endl;
	cout << "1.我要手动输入" << endl;
	cout << "2.我要随机生成" << endl;
	int select;
	select = Choice("请输入您的选择", "12");
	if (select == '1') {
		cout << "-------------------------------------向量乘矩阵测试---------------------------------------" << endl;
		cout << "请输入待乘向量" << endl;
		Vector<int> vec;
		vec.input(cin);
		cout << "请输入待乘矩阵的维数row,col" << endl;
		int r1, c1; cin >> r1;
		while (cin.fail()) { //返回cin的状态
			cin.clear();     //清除cin的错误状态
			cin.ignore();    //忽略缓冲区的内容，直到EOF
			cout << "输入错误，请重新输入" << endl;
			cin >> r1;      //重新输入
		}
		cin >> c1;
		while (cin.fail()) { //返回cin的状态
			cin.clear();     //清除cin的错误状态
			cin.ignore();    //忽略缓冲区的内容，直到EOF
			cout << "输入错误，请重新输入" << endl;
			cin >> c1;      //重新输入
		}
		Matrix mtx1(r1, c1);
		if (vec.Size()!= r1 && vec.Size() != c1) {
			cout << "维数不匹配，无效！" << endl;
		}
		else {
			cout << "请输入待乘矩阵" << endl;
			mtx1.input();
			cout << "向量乘矩阵的结果为：" << endl;
			cout << mtx1 * vec;
		}
		cout << "-------------------------------------矩阵乘矩阵测试---------------------------------------" << endl;
		cout << "请输入第一个待乘矩阵的row,col" << endl;
		int r2, c2, r3, c3;
		cin >> r2 >> c2;
		cout << "请输入第二个待乘矩阵的row,col" << endl;
		cin >> r3 >> c3;
		Matrix mtx2(r2,c2), mtx3(r3,c3);
		if (c2 != r3 && c3 != r2) {
			cout << "维数不匹配，无效！" << endl;
		}
		else if(c2 == r3){
			cout << "请输入第一个待乘矩阵：" << endl;
			mtx2.input();
			cout << "请输入第二个待乘矩阵：" << endl;
			mtx3.input();
			cout << "矩阵1*矩阵2的结果：" << endl;
			cout << (mtx2 * mtx3);
		}
		else if (c3 == r2) {
			cout << "请输入第一个待乘矩阵：" << endl;
			mtx2.input();
			cout << "请输入第二个待乘矩阵：" << endl;
			mtx3.input();
			cout << "矩阵2*矩阵1的结果：" << endl;
			cout << (mtx3 * mtx2);
		}
	}
	else {
		cout << "-------------------------------------向量乘矩阵测试---------------------------------------" << endl;
		cout << "请输入待乘向量的维数：" << endl;
		int vec_dim; cin >> vec_dim;
		Vector<int> vec(vec_dim);
		vec.get_random();
		cout << "随机生成的待乘向量：" << endl;
		cout << vec;
		cout << "请输入待乘矩阵的维数row,col" << endl;
		int r1, c1; cin >> r1;
		while (cin.fail()) { //返回cin的状态
			cin.clear();     //清除cin的错误状态
			cin.ignore();    //忽略缓冲区的内容，直到EOF
			cout << "输入错误，请重新输入" << endl;
			cin >> r1;      //重新输入
		}
		cin >> c1;
		while (cin.fail()) { //返回cin的状态
			cin.clear();     //清除cin的错误状态
			cin.ignore();    //忽略缓冲区的内容，直到EOF
			cout << "输入错误，请重新输入" << endl;
			cin >> c1;      //重新输入
		}
		Matrix mtx1(r1, c1);
		if (vec.Size() != r1 && vec.Size() != c1) {
			cout << "维数不匹配，无效！" << endl;
		}
		else {
			cout << "随机生成的待乘矩阵：" << endl;
			mtx1.get_random();
			cout << mtx1;
			cout << "向量乘矩阵的结果为：" << endl;
			cout << mtx1 * vec;
		}
		cout << "-------------------------------------矩阵乘矩阵测试---------------------------------------" << endl;
		cout << "请输入第一个待乘矩阵的row,col" << endl;
		int r2, c2, r3, c3;
		cin >> r2 >> c2;
		cout << "请输入第二个待乘矩阵的row,col" << endl;
		cin >> r3 >> c3;
		Matrix mtx2(r2, c2), mtx3(r3, c3);
		if (c2 != r3 && c3 != r2) {
			cout << "维数不匹配，无效！" << endl;
		}
		else if (c2 == r3) {
			cout << "随机生成的第一个待乘矩阵：" << endl;
			mtx2.get_random();
			cout << mtx2;
			cout << "随机生成的第二个待乘矩阵：" << endl;
			mtx3.get_random();
			cout << mtx3;
			cout << "矩阵1*矩阵2的结果：" << endl;
			cout << (mtx2 * mtx3);
		}
		else if (c3 == r2) {
			cout << "随机生成的第一个待乘矩阵：" << endl;
			mtx2.get_random();
			cout << mtx2;
			cout << "随机生成的第二个待乘矩阵：" << endl;
			mtx3.get_random();
			cout << mtx3;
			cout << "矩阵2*矩阵1的结果：" << endl;
			cout << (mtx3 * mtx2);
		}
	}
}
void Test_Matrix_Inversion() {
	cout << "======================================矩阵求逆测试========================================" << endl;
	cout << "请输入测试模式" << endl;
	cout << "1.我要手动输入" << endl;
	cout << "2.我要随机生成" << endl;
	int select;
	select = Choice("请输入您的选择", "12");
	cout << "请输入待求逆方阵的维数row=col:" << endl;
	int siz;
	cin >> siz;
	while (cin.fail()) { //返回cin的状态
		cin.clear();     //清除cin的错误状态
		cin.ignore();    //忽略缓冲区的内容，直到EOF
		cout << "输入错误，请重新输入" << endl;
		cin >>siz;      //重新输入
	}
	Matrix mtx(siz, siz);
	if (select == '1') {
		cout << "请输入" << siz << "行" << siz << "列的方阵" << endl;
		mtx.input();
		cout << "方阵的逆阵为：" << endl;
		try {
			cout << mtx.Get_Inversion();
		}
		catch (invalid_argument) {
			cerr << "矩阵非满秩，矩阵的逆不存在" << std::endl;
		}
	}
	else {
		cout << "随机生成的方阵如下：" << endl;
		mtx.get_random();
		cout << mtx;
		cout << "方阵的逆阵为：" << endl;
		try {
			cout << mtx.Get_Inversion();
		}
		catch (invalid_argument) {
			cerr <<"矩阵非满秩，矩阵的逆不存在"<< std::endl;
		}
	}
}
void Auto_Test() {
	while (true) {
		int op;
		cout << "是否进行自动机功能检测，请输入您的选择（0表示退出）：";
		cin >> op;
		if (op == 0)
			break;
		cout << "关键词功能" << endl;
		ACauto();
		cout << endl;
		cout << "回文检测功能" << endl;
		Manacher();
	}
}


void fRegister() {
	cout << "***请输入一个偶数位或位数为3的倍数的密码****" << endl;
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
			cout << "*******输入的密码不合法，请重新输入！*******" << endl;
		}
		//cout << Strreg << endl;
	}
	Code(Strreg, CodeNum1);
	system("pause");
	system("cls");
}
void fChangeCode() {
	cout << "*************请输入更改后的密码*************" << endl;
	String Strin;
	cin >> Strin;
	changeCode(Strin);
	system("pause");
	system("cls");
}
void fLog() {
	cout << "**************请输入您的密码****************" << endl;
	String  Strlog;
	cin >> Strlog;
	JudgeisCorrect(Strlog);
	system("pause");
	system("cls");
}
void fChangeCodeWay() {
	cout << "*********请输入1或2以更改加密方式***********" << endl;
	cin >> CodeNum1;
	cout << "CodeNum1= " << CodeNum1 << endl;
	cout << "******************更改完成!*****************" << endl;
	system("pause");
	system("cls");
}
void menu() {
	cout << "********************************************" << endl;
	cout << "************  欢迎使用xxx系统！*************" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.注册          *************" << endl;
	cout << "*************  2.更改密码      *************" << endl;
	cout << "*************  3.登陆          *************" << endl;
	cout << "*************  4.选择加密方式  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
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
	return ;
}

