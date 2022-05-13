//
//  Created by 张益铭 on 03/21/22.
//  Copyright ? 2022 张益铭. All Rights Reserved.
//

#include <iostream>
using namespace std;
const int MAX = 1000;
int counter[MAX];

int main(void)
{
	int N, res;
	int flag = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		counter[a]++;
	}
	for (int i = 0; i <= 1000; i++) {
		if (counter[i] > flag) {
			flag = counter[i];
			res = i;
		}
	}
	cout << res << endl;
	return 0;
}
