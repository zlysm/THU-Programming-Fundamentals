//��������

#ifndef TERMPROJECT_BASICFUNC_H
#define TERMPROJECT_BASICFUNC_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

extern bool isModuloZero;                                       //�ж��Ƿ��0ȡģ

int getPriority(char s);                                        //��ȡ��������ȼ�

bool isLegalInput(string ori_infix);                            //�ж������Ƿ�Ϸ�

void Infix2Postfix(string ori_infix);                           //��׺���ʽת��׺���ʽ

long long Calculate();                                          //�����׺���ʽ

void showName();                                                //��ʾ��Ϣ

#endif
