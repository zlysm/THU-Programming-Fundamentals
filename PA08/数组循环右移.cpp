//
//Created by 张益铭 on 4/18/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>

void MoveRight(int move_number, int len, const int *arr);

int main() {
    int move_number, len = 0, num[20];
    scanf("%d", &num[0]);
    while (num[len]) {
        scanf("%d", &num[++len]);
    }
    scanf("%d", &move_number);

    MoveRight(move_number, len, num);

    return 0;
}

void MoveRight(int move_number, int len, const int *arr) {
    move_number %= len;
    int total_array[40];
    int j = 0;
    for (int i = 20 - len; i < 20; i++) {
        total_array[i] = arr[j++];
    }
    j = 0;
    for (int i = 20; i < 20 + len; i++) {
        total_array[i] = arr[j++];
    }
    for (int i = 20 - move_number; i < 20 - move_number + len; i++) {
        if (total_array[i]) {
            printf("%d ", total_array[i]);
        }
    }
}
