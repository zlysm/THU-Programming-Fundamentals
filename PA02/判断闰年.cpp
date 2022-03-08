#include<iostream>
using namespace std;

char is_Leap(int year);

int main(void) {
	int year;
	cin >> year;
	cout << is_Leap(year);
	return 0;
}


char is_Leap(int year) {
	char is_Leap_res;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return is_Leap_res = 'Y';
	}
	else {
		return is_Leap_res = 'N';
	}
}
