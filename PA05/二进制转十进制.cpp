//
//Created by 张益铭 on 3/28/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>

double bin2dec(int num);

int main() {
    int binary;
    scanf("%d", &binary);
    printf("%.f", bin2dec(binary));

    return 0;
}

double bin2dec(int num) {
    int flag;
    double sum = 0;
    for (int i = 0; num != 0; i++) {
        flag = num % 10;
        num /= 10;
        if (flag) {
            int temp = 1;
            for (int j = 0; j < i; j++) {
                temp *= 2;
            }
            sum += temp;
        }
    }

    return sum;
}
