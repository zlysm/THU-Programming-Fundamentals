#ifndef TERMPROJECT_MY_FUNCTION_H
#define TERMPROJECT_MY_FUNCTION_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

#define MAX_SIZE 1000000

struct LongLongNum {                                                 //存储long long类型
    long long s;
};

//输入

void Input();

//基本功能

extern bool isModuloZero;                                            //判断是否对0取余

int getPriority(char s);                                             //获取运算符优先级

bool isLegalInput(string ori_infix);                                 //判断输入是否合法

char *Infix2Postfix(string ori_infix);                               //中缀表达式转后缀表达式

long long Calculate(char *postfix);                                  //计算后缀表达式

void showName();                                                     //显示信息

//进阶功能

int Str2Int(string num, LongLongNum *arr);                           //将数据倒序四位一组转化

void MultipleTwoNum(LongLongNum *num1, LongLongNum *num2, int num1_len, int num2_len);  //乘法运算并输出

int getLen(long long num);                                           //获取数字长度

bool isLegalMulInput(string total);                                  //判断乘法输入是否合法

#endif
