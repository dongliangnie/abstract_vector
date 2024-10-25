#pragma once
#ifndef _CODE_H
#define _CODE_H
#include "String.h"
extern int CodeNum1;
extern int flag1;
extern int CodeNum2;
using namespace std;
void Code(String PreStr, int CodeNum1);         //对输入字符串进行加密
String EnCode(int CodeNum1);                      //对文档中字符串进行解密
bool JudgeCode(String& Strin);             //判断输入字符串与文档中字符串是否相同，相同则输出1，不同则输出0
void Save(String& LatStr);               //保存字符串到文档中
String Load();
void JudgeisCorrect(String Strin);
void changeCode(String& Strin);
String FenceCode(String& Strin, int& CodeNum2);
String FenceEncode(String Strtxt, int& CodeNum2);
#endif
