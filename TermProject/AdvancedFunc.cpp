#include "my_function.h"

int Str2Int(string num, LongLongNum* arr) {
	int i = num.length() - 1;
	int j = 0;

	while (i > 7) {                                                 //九位一组，倒序存入arr
		if (i >= 8) {
			arr[j++].s = (num[i - 8] - '0') * 100000000 + (num[i - 7] - '0') * 10000000 + (num[i - 6] - '0') * 1000000 +
				(num[i - 5] - '0') * 100000 + (num[i - 4] - '0') * 10000 + (num[i - 3] - '0') * 1000 +
				(num[i - 2] - '0') * 100 + (num[i - 1] - '0') * 10 + (num[i] - '0');
		}
		i -= 9;
	}

	switch (i) {                                                    //处理不足九位的情况
	case 0:
		arr[j++].s = (num[i] - '0');
		break;
	case 1:
		arr[j++].s = (num[i - 1] - '0') * 10 + (num[i] - '0');
		break;
	case 2:
		arr[j++].s = (num[i - 2] - '0') * 100 + (num[i - 1] - '0') * 10 + (num[i] - '0');
		break;
	case 3:
		arr[j++].s =
			(num[i - 3] - '0') * 1000 + (num[i - 2] - '0') * 100 + (num[i - 1] - '0') * 10 + (num[i] - '0');
		break;
	case 4:
		arr[j++].s = (num[i - 4] - '0') * 10000 + (num[i - 3] - '0') * 1000 + (num[i - 2] - '0') * 100 +
			(num[i - 1] - '0') * 10 + (num[i] - '0');
		break;
	case 5:
		arr[j++].s = (num[i - 5] - '0') * 100000 + (num[i - 4] - '0') * 10000 + (num[i - 3] - '0') * 1000 +
			(num[i - 2] - '0') * 100 + (num[i - 1] - '0') * 10 + (num[i] - '0');
		break;
	case 6:
		arr[j++].s = (num[i - 6] - '0') * 1000000 + (num[i - 5] - '0') * 100000 + (num[i - 4] - '0') * 10000 +
			(num[i - 3] - '0') * 1000 + (num[i - 2] - '0') * 100 + (num[i - 1] - '0') * 10 +
			(num[i] - '0');
		break;
	case 7:
		arr[j++].s = (num[i - 7] - '0') * 10000000 + (num[i - 6] - '0') * 1000000 + (num[i - 5] - '0') * 100000 +
			(num[i - 4] - '0') * 10000 + (num[i - 3] - '0') * 1000 + (num[i - 2] - '0') * 100 +
			(num[i - 1] - '0') * 10 + (num[i] - '0');
		break;
	default:
		break;
	}

	while (j > 0 && arr[j - 1].s == 0) {                            //去除首位的0
		--j;
	}

	return j;
}

void MultipleTwoNum(LongLongNum* num1, LongLongNum* num2, int num1_len, int num2_len) {
	LongLongNum* res = new LongLongNum[MAX_SIZE];                   //存储结果
	int num3_begin;                                                 //倒序的结果的起始位置
	int carry = 0;

	for (int i = 0; i < MAX_SIZE; ++i) res[i].s = 0;                //初始化

	if (num1_len == 0 || num2_len == 0) {                           //有一个数为0，则结果为0
		cout << "0" << endl;
		return;
	}
	else {
		for (int i = 0; i < num1_len; ++i) {
			carry = i;
			for (int j = 0; j < num2_len; ++j) {
				res[carry].s += num1[i].s * num2[j].s;              //模拟竖式运算，各个数位交叉相乘
				if (res[carry].s >= 1000000000) {
					res[carry + 1].s += res[carry].s / 1000000000;
					res[carry].s %= 1000000000;                     //结果超过十亿，进位
				}
				++carry;
			}
		}
	}

	if (res[carry].s != 0) {                                        //获取结果的起始位置
		num3_begin = carry;
	}
	else {
		num3_begin = carry - 1;
	}

	cout << res[num3_begin].s;
	for (int i = num3_begin - 1; i >= 0; --i) {                     //处理中间项，补0
		switch (getLen(res[i].s)) {
		case 8:
			cout << "0" << res[i].s;
			break;
		case 7:
			cout << "00" << res[i].s;
			break;
		case 6:
			cout << "000" << res[i].s;
			break;
		case 5:
			cout << "0000" << res[i].s;
			break;
		case 4:
			cout << "00000" << res[i].s;
			break;
		case 3:
			cout << "000000" << res[i].s;
			break;
		case 2:
			cout << "0000000" << res[i].s;
			break;
		case 1:
			cout << "00000000" << res[i].s;
			break;
		case 0:
			cout << "000000000";
			break;
		default:
			cout << res[i].s;
			break;
		}
	}
	cout << endl;

	delete[]res;
}

int getLen(long long num) {                                         //获取每组数的位数
	int len = 0;
	while (num > 0) {
		num /= 10;
		++len;
	}
	return len;
}