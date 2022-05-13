//
//  Created by 张益铭 on 03/21/22.
//  Copyright ? 2022 张益铭. All Rights Reserved.
//

#include <iostream>
using namespace std;

int main(void)
{
	long unsigned int num;
	cin >> num;

	int flag;
	int prod = 1;
	while (num != 0) {
		if (num % 10 == 0) {
			num /= 10;
		}
		else {
			flag = num % 10;
			num /= 10;
			prod *= flag;
		}
		if (num == 0 && prod / 10 != 0) {
			num = prod;
			prod = 1;
		}
	}

	cout << prod << endl;
	return 0;
}
