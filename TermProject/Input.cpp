#include "my_function.h"

void InputData() {
    string whichFunc;                                          //判断哪种功能

    cout << "Please select a function:\n"
            "1--Basic Function: calculate the expression.\n"
            "2--Advanced Function: multiple two large numbers.\n";
    getline(cin, whichFunc);

    if (whichFunc.length() != 1) {
        cout << "Invalid function type!\n";
    } else {
        switch (whichFunc[0]) {
            case '1': {
                string ori_infix;

                cout << "Basic Func Mode.\n"
                        "Please enter the expression:\n";
                getline(cin, ori_infix);

                if (isLegalInput(ori_infix)) {                  //检查输入
                    Infix2Postfix(ori_infix);                   //表达式转换
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

                if (isLegalMulInput(total)) {                   //检查输入
                    for (char i: total) {
                        if (i == '*' || i == ' ') {             //判断是否到第二个数
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
}