//
//Term Project of Programming Fundamentals.
//Created by 张益铭 2021010552 on 4/13/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//Encoding with GBK.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>

#define MAX_SIZE 10000

using namespace std;

char postfix[MAX_SIZE] = {0};                               //存储后缀表达式

struct stack {                                                  //存储long long类型的栈
    long long s;
};

//基本功能
int getPriority(char s);                                        //获取运算符优先级

bool isLegalInput(string ori_infix);                            //判断输入是否合法

void Infix2Postfix(string ori_infix);                           //中缀表达式转后缀表达式

long long Calculate();                                          //计算后缀表达式

void showName();                                                //显示信息

//进阶功能
void MultipleTwoNum(string num1, string num2);                  //模拟竖式计算，每位相乘最后进位

int main() {
    showName();

    int whichFunc;

    cout << "Please select a function:\n"
            "1--Basic Function: calculate the expression.\n"
            "2--Advanced Function: multiple two large numbers." << endl;
    cin >> whichFunc;                                           //判断哪种功能
    cin.ignore();

    switch (whichFunc) {
        case 1: {
            string ori_infix;

            cout << "Please enter the expression:" << endl;
            getline(cin, ori_infix);

//            if (isLegalInput(ori_infix)) {
            Infix2Postfix(ori_infix);                           //表达式转换
            long long res = Calculate();
            cout << "The result is:" << endl << res << endl;
//            }
            break;
        }
        case 2: {
            string total, num1, num2;
            bool isNum2 = false;

            cout << "Please enter the multiplication expression(e.g. 2 * 3):" << endl;
            getline(cin, total);

            for (char i: total) {
                if (i == '*' || i == ' ') {                     //判断是否到第二个数
                    isNum2 = true;
                }
                if (!isNum2) {
                    num1.push_back(i);
                } else if (i != '*' && i != ' ') {
                    num2.push_back(i);
                }
            }

            MultipleTwoNum(num1, num2);
            break;
        }
        default:
            cout << "Please enter a LEGAL function type!" << endl;
    }

    system("pause");
    return 0;
}

//基础功能

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

    for (int i = 0; i < ori_infix.length(); ++i) {              //删除空格
        if (ori_infix[i] == ' ') {
            ori_infix.erase(i, 1);
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
                op.pop_back();                                   //删除右括号
                while (getPriority(op[op.size() - 1]) != 1) {
                    postfix[j++] = op[op.size() - 1];
                    postfix[j++] = ' ';
                    op.pop_back();
                }
                op.pop_back();                                   //删除左括号
            }
            //运算符优先级低，上一个op出栈
            while (op.size() > 1 && (getPriority(op[op.size() - 1]) <= getPriority(op[op.size() - 2]))) {
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

    for (int i = 0; i < strlen(postfix); ++i) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            num = num * 10 + postfix[i] - '0';                  //存储数字
        } else {
            if (num != 0 || postfix[i - 1] == '0') {            //防止负号前补充的0被忽略
                stack[j++].s = num;
                num = 0;
            }
            if (postfix[i] == '+') {
                stack[j - 2].s += stack[j - 1].s;
                j--;
            } else if (postfix[i] == '-') {
                stack[j - 2].s -= stack[j - 1].s;
                j--;
            } else if (postfix[i] == '*') {
                stack[j - 2].s *= stack[j - 1].s;
                j--;
            } else if (postfix[i] == '%') {
                stack[j - 2].s %= stack[j - 1].s;
                j--;
            }
        }
    }

    return stack[0].s;
}

void showName() {
    cout << "Term Project of Programming Fundamentals.\n";
    cout << "Created by 张益铭 2021010552.\n";
    cout << "Copyright (C) 张益铭 2022. All Rights Reserved.\n";
    cout << "-----------------------------------------------------------------------------\n\n";
}

//进阶功能
void MultipleTwoNum(string num1, string num2) {
    deque<int> result(num1.length() + num2.length());

    for (int i = 0; i < num1.length(); ++i) {                   //每个数位相乘
        for (int j = 0; j < num2.length(); ++j) {
            result[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    int carry = 0;                                              //处理进位
    for (int i = result.size() - 1; i >= 0; --i) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }

    while (result[0] == 0 && result.size() > 1) {               //如果最高位为0，则去掉
        result.pop_front();
    }

    while (carry != 0) {                                        //如果最高位有进位，将进位移至第一位
        int temp = carry % 10;
        result.push_front(temp);
        carry /= 10;
    }

    cout << "The result is:" << endl;
    for (int i = 0; i < result.size() - 1; ++i) {               //遍历输出结果
        cout << result[i];
    }
    cout << endl;
}
