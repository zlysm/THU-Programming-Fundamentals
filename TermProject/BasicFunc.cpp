#include "my_function.h"

char postfix[MAX_SIZE] = {0};                               //存储后缀表达式

struct stack {                                                  //存储long long类型的栈
    long long s;
};

bool isModuloZero = false;                                      //判断是否对0取模

int getPriority(char s) {
    switch (s) {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '%':
            return 3;
        case ')':
            return 4;
        default:
            return 0;
    }
}

void Infix2Postfix(string ori_infix) {
    vector<char> op;
    int j = 0;

    for (int i = 0; i < ori_infix.length(); ++i) {
        if (ori_infix[i] == ' ') {                              //删除空格
            ori_infix.erase(i, 1);
            --i;
        }
        if (ori_infix[i] == '-' && ori_infix[i - 1] == '(') {   //负数变为0-正数
            ori_infix.insert(i, "0");
            ++i;
        }
    }

    for (char &i: ori_infix) {
        if (getPriority(i) == 0) {
            postfix[j++] = i;
        } else {
            op.push_back(i);
            postfix[j++] = ' ';

            if (getPriority(op[op.size() - 1]) == 1) {        //遇到左括号跳过
                continue;
            }
            if (getPriority(op[op.size() - 1]) == 4) {        //遇到右括号，将左括号之前全部出栈
                op.pop_back();                                  //删除右括号
                while (getPriority(op[op.size() - 1]) != 1) {
                    postfix[j++] = op[op.size() - 1];
                    postfix[j++] = ' ';
                    op.pop_back();
                }
                op.pop_back();                                  //删除左括号
            }
            //运算符优先级低，上一个op出栈
            while (op.size() > 1 && (getPriority(op[op.size() - 1]) <= getPriority(op[op.size() - 2])) &&
                   op[op.size() - 2] != '(') {
                postfix[j++] = op[op.size() - 2];
                postfix[j++] = ' ';
                op.erase(op.end() - 2);
            }
        }
    }

    for (int i = op.size() - 1; i >= 0; --i) {                  //遍历完成所有op出栈
        postfix[j++] = ' ';
        postfix[j++] = op[i];
    }
    postfix[j] = '\0';
}

long long Calculate() {
    stack stack[100] = {0};
    int num = 0;
    int j = 0;
    isModuloZero = false;

    for (int i = 0; i < strlen(postfix); ++i) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            num = num * 10 + postfix[i] - '0';                  //存储数字
        } else {
            if (num != 0 || (i >= 1 && postfix[i - 1] == '0')) {//防止负号前补充的0被忽略
                stack[j++].s = num;
                num = 0;
            }
            if (j >= 2) {                                       //安全性考虑
                if (postfix[i] == '+') {
                    stack[j - 2].s += stack[j - 1].s;
                    --j;
                } else if (postfix[i] == '-') {
                    stack[j - 2].s -= stack[j - 1].s;
                    --j;
                } else if (postfix[i] == '*') {
                    stack[j - 2].s *= stack[j - 1].s;
                    --j;
                } else if (postfix[i] == '%') {
                    if (stack[j - 1].s != 0) {
                        stack[j - 2].s %= stack[j - 1].s;
                        --j;
                    } else {
                        cout << "Modulo 0!\n";
                        isModuloZero = true;
                    }
                }
            }
        }
    }

    return stack[0].s;
}

void showName() {
    cout << "Term Project of Programming Fundamentals.\n"
            "Created by 张益铭 2021010552.\n"
            "Copyright (C) 张益铭 2022. All Rights Reserved.\n"
            "--------------------------------------------------------------------\n\n";
}
