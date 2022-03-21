//
//  Created by 张益铭 on 03/19/22.
//  Copyright © 2022 张益铭. All Rights Reserved.
//

#include <iostream>
using namespace std;
int getMax(int array[]);
int getMin(int array[]);

int main(void)
{
	int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;
	cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9 >> num10;

	double sum = 0, avg;
	int num[10] = { num1, num2, num3, num4, num5, num6, num7, num8, num9, num10 };
	for (int i = 0; i < 10; i++) {
		sum += num[i];
	}
	avg = (sum - getMax(num) - getMin(num)) / 8;

	cout << (int)(avg + 0.5) << endl;
	return 0;
}

int getMax(int array[]) {
	int max = array[0];
	for (int i = 0; i < 10; i++) {
		if (max < array[i]) {
			max = array[i];
		}
	}
	return max;
}

int getMin(int array[]) {
	int min = array[0];
	for (int i = 0; i < 10; i++) {
		if (min > array[i]) {
			min = array[i];
		}
	}
	return min;
}
