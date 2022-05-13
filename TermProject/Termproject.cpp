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

//��������
int getPriority(char s);                                        //��ȡ��������ȼ�

bool isLegalInput(string ori_infix);                            //�ж������Ƿ�Ϸ�

void Infix2Postfix(string ori_infix);                           //��׺���ʽת��׺���ʽ

long long Calculate();                                          //�����׺���ʽ

void showName();                                                //��ʾ��Ϣ

//���׹���
void MultipleTwoNum(string num1, string num2);                  //ģ����ʽ���㣬ÿλ�������λ

int main() {
    showName();

    int whichFunc;

    cout << "Please select a function:\n"
            "1--Basic Function: calculate the expression.\n"
            "2--Advanced Function: multiple two large numbers." << endl;
    cin >> whichFunc;                                           //�ж����ֹ���
    cin.ignore();

    switch (whichFunc) {
        case 1: {
            string ori_infix;

            cout << "Please enter the expression:" << endl;
            getline(cin, ori_infix);

//            if (isLegalInput(ori_infix)) {
            Infix2Postfix(ori_infix);                           //���ʽת��
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
                if (i == '*' || i == ' ') {                     //�ж��Ƿ񵽵ڶ�����
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

void Infix2Postfix(string ori_infix) {
    vector<char> op;
    int j = 0;

    for (int i = 0; i < ori_infix.length(); ++i) {              //ɾ���ո�
        if (ori_infix[i] == ' ') {
            ori_infix.erase(i, 1);
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
                op.pop_back();                                   //ɾ��������
                while (getPriority(op[op.size() - 1]) != 1) {
                    postfix[j++] = op[op.size() - 1];
                    postfix[j++] = ' ';
                    op.pop_back();
                }
                op.pop_back();                                   //ɾ��������
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
            if (num != 0 || postfix[i - 1] == '0') {            //��ֹ����ǰ�����0������
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
    cout << "Created by ������ 2021010552.\n";
    cout << "Copyright (C) ������ 2022. All Rights Reserved.\n";
    cout << "-----------------------------------------------------------------------------\n\n";
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

    cout << "The result is:" << endl;
    for (int i = 0; i < result.size() - 1; ++i) {               //����������
        cout << result[i];
    }
    cout << endl;
}
