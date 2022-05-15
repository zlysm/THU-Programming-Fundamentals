#ifndef TERMPROJECT_MY_FUNCTION_H
#define TERMPROJECT_MY_FUNCTION_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>

#define MAX_SIZE 10000

using namespace std;

//����

void InputData();

//��������

extern bool isModuloZero;                                       //�ж��Ƿ��0ȡģ

int getPriority(char s);                                        //��ȡ��������ȼ�

bool isLegalInput(string ori_infix);                            //�ж������Ƿ�Ϸ�

void Infix2Postfix(string ori_infix);                           //��׺���ʽת��׺���ʽ

long long Calculate();                                          //�����׺���ʽ

void showName();                                                //��ʾ��Ϣ

//���׹���

void MultipleTwoNum(string num1, string num2);                  //ģ����ʽ���㣬ÿλ�������λ

bool isLegalMulInput(string total);                             //�жϳ˷������Ƿ�Ϸ�

#endif
