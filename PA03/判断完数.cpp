#include<iostream>
using namespace std;

char is_Perfect(int num);

int main(void) {
	int num;
	cin >> num;
	cout << is_Perfect(num) << endl;
	return 0;
}

char is_Perfect(int num) {
	int res, sum = 0;
	for (int i = 1; i < num; i++) {
		res = num % i;
		if (res == 0) {  //������������֮��
			sum += i;
		}
	}
	if (sum == num) {  //�ж��Ƿ�������
		return 'Y';
	}
	else {
		return 'N';
	}
}
