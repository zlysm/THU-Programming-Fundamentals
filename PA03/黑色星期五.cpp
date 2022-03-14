#include<iostream>
using namespace std;

int is_Leap(int year);
int num_of_leap(int year);
int day_number(int year, int i);

int main(void) {
	int year, week;
	int counter = 0;
	cin >> year;
	week = ((year - 1998) * 365 + num_of_leap(year) + 4) % 7;  //该年周一是星期几
	for (int i = 1; i <= 365 + is_Leap(year); i++) {
		if (day_number(year, i) == 13 && (i - is_Leap(year) - 1 + week) % 7 == 5) {
			counter++;
		}
	}
	cout << counter << endl;
	return 0;
}

int is_Leap(int year) {  //判断是否是闰年
	int is_Leap_res;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return is_Leap_res = 1;
	}
	else {
		return is_Leap_res = 0;
	}
}

int num_of_leap(int year) {  //判断该年到1998年之间闰年数量
	int num_of_leap_res = 0;
	for (year; year >= 1998; year--) {
		if (is_Leap(year)) {
			num_of_leap_res++;
		}
	}
	return num_of_leap_res;
}

int day_number(int year, int i) {  //判断该年第几天是几号
	int day_ARRAY[12] = { 31, (is_Leap(year) == 1) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (i <= 31) {
		return i;
	}
	else {
		int j = 0;
		while (i > 0) {
			i -= day_ARRAY[j];
			j++;
		}
		i += day_ARRAY[j - 1];
		return i;
	}
}
