//
//Created by 张益铭 on 4/18/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>

void Reverse(int *array, int p, int q);

void RightShift(int *array, int n, int k);

int main() {
    int move_number, len = 0, num[20];
    scanf("%d", &num[0]);
    while (num[len]) {
        scanf("%d", &num[++len]);
    }
    scanf("%d", &move_number);

    RightShift(num, len, move_number);
    for (int i = 0; i < len; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}

void Reverse(int *array, int p, int q) {
    for (; p < q; p++, q--) {
        int temp = array[q];
        array[q] = array[p];
        array[p] = temp;
    }
}

void RightShift(int *array, int n, int k) {
    k %= n;
    Reverse(array, 0, n - k - 1);
    Reverse(array, n - k, n - 1);
    Reverse(array, 0, n - 1);
}
