#include <iostream>
#include <fstream>
using namespace std;
#include "Code.h"
#include "string"
int CodeNum1;
int flag1;
int CodeNum2;
void Code(String PreStr, int sum) {
	//String LatStr(PreStr);
	cout << "sum=" << sum << endl;
	String LatStr;
	/*cout << LatStr.size() << " " << PreStr.size() << endl;*/
	LatStr.resize(PreStr.size());
	flag1 = 1;
	/*cout << LatStr.size() << " " << PreStr.size() << endl;*/
	switch (sum) {
	case 1: //编码方式为偏移量为2的凯撒密码
		int i;
		for (i = 0; i < PreStr.size(); i++) {
			LatStr[i] = PreStr[i] + 2;
		}
		/*cout << "密码加密后为:LatStr:" << LatStr << endl;*/
		Save(LatStr);
		break;
	case 2:
		LatStr = FenceCode(PreStr, CodeNum2);
		Save(LatStr);
		break;
	case 3:
		break;
	}
}
String FenceCode(String& Strin, int& CodeNum2) {
	if (CodeNum2 == 2) {
		String StrCoded;
		StrCoded.resize(Strin.size());
		for (int i = 0; i < StrCoded.size() / 2; i++)
			StrCoded[i] = Strin[2 * i];
		for (int i = StrCoded.size() / 2; i < StrCoded.size(); i++)
			StrCoded[i] = Strin[2 * (i - StrCoded.size() / 2) + 1];
		//cout << "StrCoded=" << StrCoded << endl;
		return StrCoded;
	}
	else if (CodeNum2 == 3) {
		String StrCoded;
		StrCoded.resize(Strin.size());
		for (int i = 0; i < StrCoded.size() / 3; i++)
			StrCoded[i] = Strin[3 * i];
		for (int i = StrCoded.size() / 3; i < StrCoded.size() / 3 * 2; i++)
			StrCoded[i] = Strin[3 * (i - StrCoded.size() / 3) + 1];
		for (int i = StrCoded.size() / 3 * 2; i < StrCoded.size(); i++)
			StrCoded[i] = Strin[3 * (i - StrCoded.size() / 3 * 2) + 2];
		/*cout << "StrCoded=" << StrCoded << endl;*/
		return StrCoded;
	}
}
void JudgeisCorrect(String Strin) {
	int mistake = 0;
	/*cout << Strin << endl;*/
	while (1) {
		if (Strin.size() % CodeNum2 != 0 || JudgeCode(Strin) == 0) {
			mistake++;
			if (mistake == 3)
			{
				cout << "*******密码输入错误次数已达3次，请稍后再试*******" << endl;
				break;
			}
			cout << "*密码输入有误，是否重新输入？(0重新输入,1退回至菜单界面)*" << endl;
			int choice;
			cin >> choice;
			if (choice == 1)
				break;
			else if (choice == 0)
			{
				cout << "**************请再次输入密码：**************" << endl;
				cin >> Strin;
			}
		}
		else {
			cout << "******************密码验证成功******************" << endl;
			cout << "*******************登陆成功~~~******************" << endl;
			break;
		}
	}
}

String EnCode(int sum) {
	String Strtxt;
	Strtxt = Load();
	/*cout << "Strtxt=" << Strtxt << endl;*/
	switch (sum) {
	case 1:
		for (int i = 0; i < Strtxt.size(); i++)
			Strtxt[i] = Strtxt[i] - 2;
		return Strtxt;
		/*cout << Strtxt << endl;*/
		break;
	case 2:
		String StrEncoded;
		StrEncoded = FenceEncode(Strtxt, CodeNum2);
		/*cout << StrEncoded;*/
		return StrEncoded;
		break;
	}
}

String FenceEncode(String Strtxt, int& CodeNum2) {
	String StrEncoded;
	StrEncoded.resize(Strtxt.size());
	int j = 0;
	int k = 0;
	for (int i = 0; i < Strtxt.size(); i++)
	{
		StrEncoded[i] = Strtxt[j];
		j = (j + Strtxt.size() / CodeNum2 + (i % CodeNum2 + k) / CodeNum2) % (Strtxt.size());
		k++;
		k = k % CodeNum2;
	}
	/*cout << "StrEncoded=" << StrEncoded << endl;*/
	return StrEncoded;
}
bool JudgeCode(String& Strin) {
	if (Strin == EnCode(CodeNum1) && (Strin.size() == EnCode(CodeNum1).size()))
		return 1;
	return 0;
}

void Save(String& LatStr) //将加密后的字符串保存到文档中
{
	ofstream file;
	file.open("Code.txt", ios::out | ios::trunc);
	for (int i = 0; i < LatStr.size(); i++) {
		file << LatStr[i];
	}
	file.close();
	if (flag1 == 1) {
		cout << "****************恭喜你，注册成功！****************" << endl;
	}
	else if (flag1 == 0)
		cout << "**************恭喜你，更改密码成功！**************" << endl;
}


String Load() {

	ifstream File("Code.txt");
	string str1;
	String Str;
	// 读取文件中的内容到字符串中
	getline(File, str1);
	int len = str1.length();
	/*cout << "长度为" << len << endl;*/
	Str.resize(len);
	// 输出读取的字符串
	File.close();       // 关闭文件
	for (int i = 0; i < len; i++) {
		Str[i] = str1[i];
	}
	return Str;
}

void changeCode(String& Strin) {
	String StrRead;
	StrRead = EnCode(CodeNum1);
	flag1 = 0;
	if (StrRead == Strin && (StrRead.size() == Strin.size()))
		cout << "*******更改后的密码与原密码相同，更改失败！*******" << endl;
	else
	{
		if (CodeNum1 == 1)
		{
			String StrChange;
			StrChange.resize(Strin.size());
			for (int i = 0; i < Strin.size(); i++)
			{
				StrChange[i] = Strin[i] + 2;
			}
			Save(StrChange);
		}
		else {
			String Strchange;
			Strchange = FenceCode(Strin, CodeNum2);
			Save(Strchange);
		}
	}

}