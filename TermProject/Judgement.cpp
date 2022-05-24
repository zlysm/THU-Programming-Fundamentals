#include "my_function.h"

//判断基本功能输入

bool isLegalInput(string ori_infix) {
    int leftParenNum = 0;                                       //记录括号个数
    int rightParenNum = 0;

    for (int i = 0; i < ori_infix.length(); ++i) {              //删除空格
        if (ori_infix[i] == ' ') {
            ori_infix.erase(i, 1);
            --i;
        }
    }

    if (getPriority(ori_infix[0]) > 0 && ori_infix.length() == 1) {  //第一位只有一个符号
        cout << "Operator missing operand!\n";
        return false;
    }

    if (ori_infix[0] == '+' || ori_infix[0] == '*' || ori_infix[0] == '%') {  //第一位是符号但不是减号
        cout << "Operator missing operand!\n";
        return false;
    }

    for (int i = 0; i < ori_infix.length(); ++i) {
        if (ori_infix[i] < 0) {                                 //检查是否是英文状态下输入
            cout << "Please enter expressions in English!\n";
            return false;
        }

        if (ori_infix[i] < '0' || ori_infix[i] > '9') {         //检查运算符
            switch (ori_infix[i]) {
                case '(':
                case ')':
                case '+':
                case '-':
                case '*':
                case '%':
                    break;
                default:
                    cout << "Invalid operator!\n";
                    return false;
            }
        }

        if (i >= 1) {
            if ((getPriority(ori_infix[i]) == 2 || getPriority(ori_infix[i]) == 3) &&
                (getPriority(ori_infix[i - 1]) == 2 || getPriority(ori_infix[i - 1]) == 3)) {
                //连续两个运算符
                cout << "Operator missing operand!\n";
                return false;
            }

            if (ori_infix[i - 1] == '(' && getPriority(ori_infix[i]) > 1 && ori_infix[i] != '-') {
                //左括号加运算符，除去(-1)类型
                cout << "Operator missing operand!\n";
                return false;
            }

            if (getPriority(ori_infix[i - 1]) > 0 && ori_infix[i - 1] != ')' && ori_infix[i] == ')') {
                //运算符加右括号
                cout << "Operator missing operand!\n";
                return false;
            }
        }

        if (ori_infix[i] == '(') {                              //检查括号数量
            ++leftParenNum;
        } else if (ori_infix[i] == ')') {
            ++rightParenNum;
        }
    }

    if (leftParenNum != rightParenNum) {
        cout << "Parenthesis DO NOT match!\n";
        return false;
    }

    return true;
}

//判断进阶功能输入

bool isLegalMulInput(string total) {
    int mulNum = 0;                                             //乘号个数

    for (int i = 0; i < total.length(); ++i) {                  //删除空格
        if (total[i] == ' ') {
            total.erase(i, 1);
            --i;
        }
    }

    if (total[0] == '*') {                                      //是否输入第一个乘数
        cout << "Please enter the first multiplier!\n";
        return false;
    }

    if (total[total.length() - 1] == '*') {                     //是否输入第二个乘数
        cout << "Please enter the second multiplier!\n";
        return false;
    }

    for (char i: total) {
        if (i < '0' || i > '9') {                               //检查运算符
            if (i == '*') {
                ++mulNum;
            } else {
                cout << "You can ONLY enter multiplication signs or numbers!\n";
                return false;
            }
        }
    }

    if (mulNum != 1) {
        cout << "You can ONLY multiply two numbers!\n";
        return false;
    }

    return true;
}
