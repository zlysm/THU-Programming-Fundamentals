//基本功能

#ifndef TERMPROJECT_BASICFUNC_H
#define TERMPROJECT_BASICFUNC_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

extern bool isModuloZero;                                       //判断是否对0取模

int getPriority(char s);                                        //获取运算符优先级

bool isLegalInput(string ori_infix);                            //判断输入是否合法

void Infix2Postfix(string ori_infix);                           //中缀表达式转后缀表达式

long long Calculate();                                          //计算后缀表达式

void showName();                                                //显示信息

#endif
