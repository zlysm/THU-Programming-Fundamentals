//
//Created by ������ on 4/25/2022.
//Copyright (C) ������ 2022. All Rights Reserved.
//

#include<cstdio>

void GetTwoInts(int *num1, int *num2);

int main() {
    int num1, num2;
    GetTwoInts(&num1, &num2);
    printf("%d", num1 + num2);

    return 0;
}

void GetTwoInts(int *num1, int *num2) {
    scanf("%d %d", num1, num2);
}
