#pragma once
#include"Vector.h"
#include"String.h"
#include"Matrix.h"
//�������
int Pos(char ch, const char* str);
int Choice(const char* prompt, const char* options);
//==============================================������Ժ���====================================================
//��������������Բ��Ժ���
void Test_Determine_linear_correlation();
//��������ݲ��Ժ���
void Test_Matrix_Qpow();
//����˷����Ժ���
void Test_Matrix_Multipy();
//����ʽ���Ժ���
void Test_Matrix_Determinant();
//��˹��Ԫ������Է�������Ժ���
void Test_Matrix_Gauss();
//������Ȳ��Ժ���
void Test_Matrix_Rank();
//ģ1000000007�����¾��������Ժ���
void Test_Matrix_Inversion();
void Auto_Test();
/*
���԰������������뼴�ɣ�
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