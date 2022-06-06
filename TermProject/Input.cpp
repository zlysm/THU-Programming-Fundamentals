#include "my_function.h"

void Input() {
	string whichFunc;                                               //判断哪种功能

	cout << "Please select a function:\n"
		"1--Basic Function: calculate the expression.\n"
		"2--Advanced Function: multiple two large numbers.\n";
	getline(cin, whichFunc);

	if (whichFunc.length() != 1) {
		cout << "Invalid function type!\n";
	}
	else {
		switch (whichFunc[0]) {
		case '1': {
			string ori_infix;

			cout << "Basic Func Mode.\n"
				"Please enter the expression:\n";
			getline(cin, ori_infix);

			if (isLegalInput(ori_infix)) {                          //检查输入
				//表达式转换并计算
				long long res = Calculate(Infix2Postfix(ori_infix));
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

			for (int i = 0; i < total.length(); ++i) {              //删除空格
				if (total[i] == ' ') {
					total.erase(i, 1);
					--i;
				}
			}

			if (isLegalMulInput(total)) {                           //检查输入
				for (char i : total) {
					if (i == '*') {                                 //判断是否到第二个数
						isNum2 = true;
					}
					if (!isNum2) {
						num1.push_back(i);
					}
					else if (i != '*') {
						num2.push_back(i);
					}
				}

				LongLongNum* num1_arr = new LongLongNum[MAX_SIZE];
				LongLongNum* num2_arr = new LongLongNum[MAX_SIZE];

				for (int i = 0; i < MAX_SIZE; ++i) {                //初始化
					num1_arr[i].s = 0;
					num2_arr[i].s = 0;
				}

				int num1_len = Str2Int(num1, num1_arr);             //获取倒序后最高位数字位置
				int num2_len = Str2Int(num2, num2_arr);

				MultipleTwoNum(num1_arr, num2_arr, num1_len, num2_len);

				delete[]num1_arr;
				delete[]num2_arr;
			}
			break;
		}
		default:
			cout << "Invalid function type!\n";
		}
	}
}
