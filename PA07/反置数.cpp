//
//Created by ������ on 4/11/2022.
//Copyright (C) ������ 2022. All Rights Reserved.
//

#include<cstdio>

int getReverseNum(int num);

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%d", getReverseNum(getReverseNum(num1) + getReverseNum(num2)));

    return 0;
}

int getReverseNum(int num) {
    int reverse_num = 0;
    if (num % 10 == 0) {  //ȥ��ĩβ��0
        for (int j = 0;num % 10 != 0; j++) {
            num /= 10;
        }
    }
    for (int i = 0; num != 0; i++) {  //����
        reverse_num = reverse_num * 10 + num % 10;
        num /= 10;
    }
    return reverse_num;
}
