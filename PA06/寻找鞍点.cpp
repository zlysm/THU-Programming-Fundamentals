//
//Created by ������ on 4/4/2022.
//Copyright (C) ������ 2022. All Rights Reserved.
//

#include<cstdio>

const int COLUMN = 2;
const int ROW = 3;

void getSaddlePoint();

int main() {
    getSaddlePoint();
    return 0;
}

void getSaddlePoint() {
    int input[ROW][COLUMN];
    for (int row = 0; row < ROW; row++) {  //�洢����
        for (int column = 0; column < COLUMN; column++) {
            scanf("%d", &input[row][column]);
        }
    }

    //�ҵ�һ�е����ֵλ��
    int max = 0, temp1 = 0;
    int flag1;
    for (int j = 0; j < ROW; j++) {
        if (input[j][0] > max) {
            max = input[j][0];
            flag1 = j;
        }
        if (flag1 != j && input[j][0] == max) {
            temp1++;
        }
    }

    //�ҵڶ��е����ֵλ��
    max = 0;
    int flag2, temp2 = 0;
    for (int j = 0; j < ROW; j++) {
        if (input[j][1] > max) {
            max = input[j][1];
            flag2 = j;
        }
        if (flag2 != j && input[j][1] == max) {
            temp2++;
        }
    }

    int res[3] = {0, 0, 0};
    if (input[flag1][0] > input[flag1][1]) {
        res[flag1] = input[flag1][0];
    }
    if (input[flag2][1] > input[flag2][0]) {
        res[flag2] = input[flag2][1];
    }
    //�ж��Ƿ����ظ�����
    if (res[flag1] == res[flag2]) {
        if (flag1 > flag2) {
            res[flag2] = 0;
        } else if (flag1 < flag2) {
            res[flag1] = 0;
        }
    }
    //�ж�һ���Ƿ����ظ����ֵ
    if (temp1 != 0) {
        res[flag1] = 0;
    }
    if (temp2 != 0) {
        res[flag2] = 0;
    }
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        if (res[i] != 0) {
            printf("%d ", res[i]);
        } else {
            flag++;
        }
    }
    if (flag == 3) {
        printf("none");
    }
}
