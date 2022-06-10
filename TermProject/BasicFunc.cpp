#include "my_function.h"

bool isModuloZero = false;                                          //�ж��Ƿ��0ȡģ

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

char* Infix2Postfix(string ori_infix) {
	vector<char> op;
	char* postfix = new char[MAX_SIZE];
	int j = 0;

	for (int i = 0; i < ori_infix.length(); ++i) {
		if (ori_infix[i] == ' ') {                                  //ɾ���ո�
			ori_infix.erase(i, 1);
			--i;
		}
	}

	if (ori_infix[0] == '-') {                                      //��һλΪ����
		ori_infix.insert(0, "0");
	}
	if (ori_infix[0] == '+') {                                      //��һλΪ����
		ori_infix.insert(0, "0");
	}

	for (int i = 0; i < ori_infix.length(); ++i) {
		if (ori_infix[i] == '-' && ori_infix[i - 1] == '(') {       //������Ϊ0-����
			ori_infix.insert(i, "0");
			++i;
		}
		if (ori_infix[i] == '+' && ori_infix[i - 1] == '(') {       //������Ϊ0+����
			ori_infix.insert(i, "0");
			++i;
		}
	}

	for (char& i : ori_infix) {
		if (getPriority(i) == 0) {
			postfix[j++] = i;
		}
		else {
			op.push_back(i);
			postfix[j++] = ' ';

			if (op[op.size() - 1] == '(') {                         //��������������
				continue;
			}
			if (op[op.size() - 1] == ')') {                         //���������ţ���������֮ǰȫ����ջ
				op.pop_back();                                      //ɾ��������
				while (op[op.size() - 1] != '(') {
					postfix[j++] = op[op.size() - 1];
					postfix[j++] = ' ';
					op.pop_back();
				}
				op.pop_back();                                      //ɾ��������
			}
			//��������ȼ��ͣ���һ��op��ջ
			while (op.size() > 1 && (getPriority(op[op.size() - 1]) <= getPriority(op[op.size() - 2])) &&
				op[op.size() - 1] != '(' && op[op.size() - 2] != '(') {
				postfix[j++] = op[op.size() - 2];
				postfix[j++] = ' ';
				op.erase(op.end() - 2);
			}
		}
	}

	while (!op.empty()) {                                           //�����������op��ջ
		postfix[j++] = op[op.size() - 1];
		postfix[j++] = ' ';
		op.pop_back();
	}
	postfix[j] = '\0';

	return postfix;
}

long long Calculate(char* postfix) {
	LongLongNum* stack = new LongLongNum[MAX_SIZE];
	long long num = 0;
	int j = 0;
	isModuloZero = false;

	for (int i = 0; i < MAX_SIZE; ++i) stack[i].s = 0;              //��ʼ��

	for (int i = 0; i < strlen(postfix); ++i) {
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			num = num * 10 + postfix[i] - '0';                      //�洢����
		}
		else {
			if (num != 0 || (i >= 1 && postfix[i - 1] == '0')) {    //��ֹ����ǰ�����0������
				stack[j++].s = num;
				num = 0;
			}
			if (j >= 2) {                                           //��ȫ�Կ���
				if (postfix[i] == '+') {
					stack[j - 2].s += stack[j - 1].s;
					--j;
				}
				else if (postfix[i] == '-') {
					stack[j - 2].s -= stack[j - 1].s;
					--j;
				}
				else if (postfix[i] == '*') {
					stack[j - 2].s *= stack[j - 1].s;
					--j;
				}
				else if (postfix[i] == '%') {
					if (stack[j - 1].s != 0) {
						stack[j - 2].s %= stack[j - 1].s;
						--j;
					}
					else {
						cout << "Modulo 0!\n";
						isModuloZero = true;
					}
				}
			}
		}
	}

	if (num != 0) {                                                 //ֻ��һ������
		stack[j].s = num;
	}

	return stack[0].s;
}

void showName() {
	cout << "Term Project of Programming Fundamentals.\n"
		"Created by ������ 2021010552.\n"
		"Copyright (C) ������ 2022. All Rights Reserved.\n"
		"--------------------------------------------------------------------\n\n";
}
