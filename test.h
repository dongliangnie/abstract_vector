#pragma once
#include"Vector.h"
#include"String.h"
#include"Matrix.h"
//输入控制
int Pos(char ch, const char* str);
int Choice(const char* prompt, const char* options);
//==============================================矩阵测试函数====================================================
//向量组线性相关性测试函数
void Test_Determine_linear_correlation();
//矩阵快速幂测试函数
void Test_Matrix_Qpow();
//矩阵乘法测试函数
void Test_Matrix_Multipy();
//行列式测试函数
void Test_Matrix_Determinant();
//高斯消元求解线性方程组测试函数
void Test_Matrix_Gauss();
//矩阵的秩测试函数
void Test_Matrix_Rank();
//模1000000007意义下矩阵的逆测试函数
void Test_Matrix_Inversion();
void Auto_Test();
/*
测试案例（复制输入即可）
1
6
beta
alpha
haha
delta
dede
tata
dedeltalphahahahototatalpha
aabbaabbabbabb

1
6
beta
alpha
haha
delta
dede
tata
dedaltblphahbhahototatolqha
HelloWorld
*/