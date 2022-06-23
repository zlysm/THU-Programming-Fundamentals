#ifndef TERMPROJECT_MY_FUNCTION_H
#define TERMPROJECT_MY_FUNCTION_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

#define MAX_SIZE 1000000

struct LongLongNum {                                                 //�洢long long����
    long long s;
};

//����

void Input();

//��������

extern bool isModuloZero;                                            //�ж��Ƿ��0ȡ��

int getPriority(char s);                                             //��ȡ��������ȼ�

bool isLegalInput(string ori_infix);                                 //�ж������Ƿ�Ϸ�

char *Infix2Postfix(string ori_infix);                               //��׺���ʽת��׺���ʽ

long long Calculate(char *postfix);                                  //�����׺���ʽ

void showName();                                                     //��ʾ��Ϣ

//���׹���

int Str2Int(string num, LongLongNum *arr);                           //�����ݵ�����λһ��ת��

void MultipleTwoNum(LongLongNum *num1, LongLongNum *num2, int num1_len, int num2_len);  //�˷����㲢���

int getLen(long long num);                                           //��ȡ���ֳ���

bool isLegalMulInput(string total);                                  //�жϳ˷������Ƿ�Ϸ�

#endif
