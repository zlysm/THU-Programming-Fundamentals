//
//Term Project of Programming Fundamentals.
//Created by ������ 2021010552 on 4/13/2022.
//Copyright (C) ������ 2022. All Rights Reserved.
//Encoding with GBK.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>

#define MAX_SIZE 10000

using namespace std;

char postfix[MAX_SIZE] = {0};                               //�洢��׺���ʽ

struct stack {                                                  //�洢long long���͵�ջ
    long long s;
};

bool isModuloZero = false;                                      //�ж��Ƿ��0ȡģ

//��������

int getPriority(char s);                                        //��ȡ��������ȼ�

bool isLegalInput(string ori_infix);                            //�ж������Ƿ�Ϸ�

void Infix2Postfix(string ori_infix);                           //��׺���ʽת��׺���ʽ

long long Calculate();                                          //�����׺���ʽ

void showName();                                                //��ʾ��Ϣ

//���׹���

void MultipleTwoNum(string num1, string num2);                  //ģ����ʽ���㣬ÿλ�������λ

bool isLegalMulInput(string total);                             //�жϳ˷������Ƿ�Ϸ�

int main() {
    showName();

    string whichFunc;

    cout << "Please select a function:\n"
            "1--Basic Function: calculate the expression.\n"
            "2--Advanced Function: multiple two large numbers.\n";
    getline(cin, whichFunc);                              //�ж����ֹ���

    if (whichFunc.length() != 1) {
        cout << "Invalid function type!\n";
    } else {
        switch (whichFunc[0]) {
            case '1': {
                string ori_infix;

                cout << "Basic Func Mode.\n"
                        "Please enter the expression:\n";
                getline(cin, ori_infix);

                if (isLegalInput(ori_infix)) {                  //�������
                    Infix2Postfix(ori_infix);                   //���ʽת��
                    long long res = Calculate();
                    if (!isModuloZero) {
                        cout << "The result is:\n" << res << endl;
                    }
                }
                break;
            }
            case '2': {
                string total;
                string num1, num2;
                bool isNum2 = false;

                cout << "Advanced Func Mode.\n"
                        "Please enter the multiplication expression(e.g. 2 * 3):\n";
                getline(cin, total);

                if (isLegalMulInput(total)) {                   //�������
                    for (char i: total) {
                        if (i == '*' || i == ' ') {             //�ж��Ƿ񵽵ڶ�����
                            isNum2 = true;
                        }
                        if (!isNum2) {
                            num1.push_back(i);
                        } else if (i != '*' && i != ' ') {
                            num2.push_back(i);
                        }
                    }

                    MultipleTwoNum(num1, num2);
                }
                break;
            }
            default:
                cout << "Invalid function type!\n";
        }
    }

    system("pause");
    return 0;
}

//��������

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

bool isLegalInput(string ori_infix) {
    int leftParenNum = 0;                                       //��¼���Ÿ���
    int rightParenNum = 0;

    for (int i = 0; i < ori_infix.length(); ++i) {              //ɾ���ո�
        if (ori_infix[i] == ' ') {
            ori_infix.erase(i, 1);
            --i;
        }
    }

    if (ori_infix.length() == 1 && getPriority(ori_infix[0]) > 0) {  //ֻ�з���
        cout << "Operator missing operand!\n";
        return false;
    }

    for (int i = 0; i < ori_infix.length(); ++i) {
        if (ori_infix[i] < 0) {                                 //����Ƿ���Ӣ��״̬������
            cout << "Please enter expressions in English!\n";
            return false;
        }

        if (ori_infix[i] < '0' || ori_infix[i] > '9') {         //��������
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
            if (i >= 1 && getPriority(ori_infix[i]) >= getPriority(ori_infix[i - 1]) &&
                getPriority(ori_infix[i - 1]) > 1) {
                //��ֹ(-1)�Լ�1+(1+1)+1����Ϊ���Ϸ�
                cout << "Operator missing operand!\n";
                return false;
            }

            if (getPriority(ori_infix[i]) > 0 && ori_infix[i] != '-' && ori_infix[i - 1] == '(') {
                //��ֹ(%1)����Ϊ�Ϸ�
                cout << "Operator missing operand!\n";
                return false;
            }
        }

        if (ori_infix[i] == '(') {                              //�����������
            ++leftParenNum;
        } else if (ori_infix[i] == ')') {
            ++rightParenNum;
        }
    }

    if (leftParenNum != rightParenNum) {
        cout << "Parenthesis DO NOT MATCH!\n";
        return false;
    }

    return true;
}

void Infix2Postfix(string ori_infix) {
    vector<char> op;
    int j = 0;

    for (int i = 0; i < ori_infix.length(); ++i) {
        if (ori_infix[i] == ' ') {                              //ɾ���ո�
            ori_infix.erase(i, 1);
            --i;
        }
        if (ori_infix[i] == '-' && ori_infix[i - 1] == '(') {   //������Ϊ0-����
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

            if (getPriority(op[op.size() - 1]) == 1) {        //��������������
                continue;
            }
            if (getPriority(op[op.size() - 1]) == 4) {        //���������ţ���������֮ǰȫ����ջ
                op.pop_back();                                  //ɾ��������
                while (getPriority(op[op.size() - 1]) != 1) {
                    postfix[j++] = op[op.size() - 1];
                    postfix[j++] = ' ';
                    op.pop_back();
                }
                op.pop_back();                                  //ɾ��������
            }
            //��������ȼ��ͣ���һ��op��ջ
            while (op.size() > 1 && (getPriority(op[op.size() - 1]) <= getPriority(op[op.size() - 2]))) {
                postfix[j++] = op[op.size() - 2];
                postfix[j++] = ' ';
                op.erase(op.end() - 2);
            }
        }
    }

    for (int i = op.size() - 1; i >= 0; --i) {                  //�����������op��ջ
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
            num = num * 10 + postfix[i] - '0';                  //�洢����
        } else {
            if (num != 0 || (i >= 1 && postfix[i - 1] == '0')) {//��ֹ����ǰ�����0������
                stack[j++].s = num;
                num = 0;
            }
            if (j >= 2) {                                       //��ȫ�Կ���
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
                        cout << "modulo 0!\n";
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
            "Created by ������ 2021010552.\n"
            "Copyright (C) ������ 2022. All Rights Reserved.\n"
            "--------------------------------------------------------------------\n\n";
}

//���׹���

void MultipleTwoNum(string num1, string num2) {
    deque<int> result(num1.length() + num2.length());

    for (int i = 0; i < num1.length(); ++i) {                   //ÿ����λ���
        for (int j = 0; j < num2.length(); ++j) {
            result[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    int carry = 0;                                              //�����λ
    for (int i = result.size() - 1; i >= 0; --i) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }

    while (result[0] == 0 && result.size() > 1) {               //������λΪ0����ȥ��
        result.pop_front();
    }

    while (carry != 0) {                                        //������λ�н�λ������λ������һλ
        int temp = carry % 10;
        result.push_front(temp);
        carry /= 10;
    }

    cout << "The result is:\n";
    for (int i = 0; i < result.size() - 1; ++i) {               //����������
        cout << result[i];
    }
    cout << endl;
}

bool isLegalMulInput(string total) {
    int mulNum = 0;                                             //�˺Ÿ���

    for (int i = 0; i < total.length(); ++i) {                  //ɾ���ո�
        if (total[i] == ' ') {
            total.erase(i, 1);
            --i;
        }
    }

    if (total[0] == '*') {                                      //�Ƿ������һ������
        cout << "Please enter the first multiplier!\n";
        return false;
    }

    if (total[total.length() - 1] == '*') {                     //�Ƿ�����ڶ�������
        cout << "Please enter the second multiplier!\n";
        return false;
    }

    for (char i: total) {
        if (i < '0' || i > '9') {                               //��������
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