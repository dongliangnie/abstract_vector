#pragma once
#ifndef _CODE_H
#define _CODE_H
#include "String.h"
extern int CodeNum1;
extern int flag1;
extern int CodeNum2;
using namespace std;
void Code(String PreStr, int CodeNum1);         //�������ַ������м���
String EnCode(int CodeNum1);                      //���ĵ����ַ������н���
bool JudgeCode(String& Strin);             //�ж������ַ������ĵ����ַ����Ƿ���ͬ����ͬ�����1����ͬ�����0
void Save(String& LatStr);               //�����ַ������ĵ���
String Load();
void JudgeisCorrect(String Strin);
void changeCode(String& Strin);
String FenceCode(String& Strin, int& CodeNum2);
String FenceEncode(String Strtxt, int& CodeNum2);
#endif