#pragma once
#ifndef _CODE_H
#define _CODE_H
#include "String.h"
extern int CodeNum1;                               //加密方式1或2
extern int flag1;                                  //注册成功或更改密码成功
extern int CodeNum2;                               //栅栏密码中字符串长度为2的倍数还是为3的倍数
using namespace std;
void Code(String PreStr, int CodeNum1);            //对输入字符串进行加密
String EnCode(int CodeNum1);                       //对文档中字符串进行解密
bool JudgeCode(String& Strin);                     //判断输入字符串与文档中字符串是否相同，相同则输出1，不同则输出0
void Save(String& LatStr);                         //保存字符串到文档中
String Load();                                     //返回从文档中读取的加密后字符串
void JudgeisCorrect(String Strin);                 //判断输入的字符串与文档中字符串解密后是否相同            
void changeCode(String& Strin);                    //更改字符串，如果与原字符串不同，对其进行加密并存到文档中；如果相同，则返回
String FenceCode(String& Strin, int& CodeNum2);    //栅栏密码加密
String FenceEncode(String Strtxt, int& CodeNum2);  //栅栏密码解密
#endif
