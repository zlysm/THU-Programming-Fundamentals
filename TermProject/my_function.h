#ifndef TERMPROJECT_MY_FUNCTION_H
#define TERMPROJECT_MY_FUNCTION_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>

#define MAX_SIZE 10000

using namespace std;

//输入

void InputData();

//基本功能

extern bool isModuloZero;                                       //判断是否对0取模

int getPriority(char s);                                        //获取运算符优先级

bool isLegalInput(string ori_infix);                            //判断输入是否合法

void Infix2Postfix(string ori_infix);                           //中缀表达式转后缀表达式

long long Calculate();                                          //计算后缀表达式

void showName();                                                //显示信息

//进阶功能

void MultipleTwoNum(string num1, string num2);                  //模拟竖式计算，每位相乘最后进位

bool isLegalMulInput(string total);                             //判断乘法输入是否合法

#endif
