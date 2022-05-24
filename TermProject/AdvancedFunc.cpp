#include "my_function.h"

void MultipleTwoNum(string num1, string num2) {
    deque<int> result(num1.length() + num2.length());

    for (int i = 0; i < num1.length(); ++i) {                   //每个数位相乘，模拟竖式计算
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

    cout << "The result is:\n";
    for (int i = 0; i < result.size() - 1; ++i) {               //遍历输出结果
        cout << result[i];
    }
    cout << endl;
}
