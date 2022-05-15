#include "my_function.h"

//�жϻ�����������

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
            if ((getPriority(ori_infix[i]) == 2 || getPriority(ori_infix[i]) == 3) &&
                (getPriority(ori_infix[i - 1]) == 2 || getPriority(ori_infix[i - 1]) == 3)) {
                //�������������
                cout << "Operator missing operand!\n";
                return false;
            }

            if (ori_infix[i - 1] == '(' && getPriority(ori_infix[i]) > 1 && ori_infix[i] != '-') {
                //�����ż����������ȥ(-1)����
                cout << "Operator missing operand!\n";
                return false;
            }

            if (getPriority(ori_infix[i - 1]) > 0 && ori_infix[i - 1] != ')' && ori_infix[i] == ')') {
                //�����ż������
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
        cout << "Parenthesis DO NOT match!\n";
        return false;
    }

    return true;
}

//�жϽ��׹�������

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