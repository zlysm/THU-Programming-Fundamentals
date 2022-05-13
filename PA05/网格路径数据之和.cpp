//
//Created by 张益铭 on 3/28/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>

const int m = 8;
const int n = 8;

int matrix[m][n] = {{0, 9, 8, 7, 6, 5, 4, 3},
                    {1, 2, 3, 4, 5, 6, 7, 8},
                    {2, 3, 4, 6, 7, 8, 9, 6},
                    {4, 5, 6, 7, 8, 9, 0, 7},
                    {4, 3, 2, 1, 6, 7, 8, 9},
                    {5, 8, 4, 9, 0, 4, 3, 2},
                    {3, 4, 6, 7, 8, 4, 3, 2},
                    {2, 4, 6, 8, 9, 7, 5, 3}};

int getStepSum(int i1, int j1, int i2, int j2);  //计算每两点之间的和

int main() {
    int num_of_Coord;  //存储坐标个数
    scanf("%d", &num_of_Coord);
    int mCoord[num_of_Coord], nCoord[num_of_Coord];

    for (int i = 0; i < num_of_Coord; i++) {  //存储坐标
        scanf("%d %d", &mCoord[i], &nCoord[i]);
    }

    int sum = 0;
    if (num_of_Coord == 1) {  //一个点的情况
        sum = matrix[mCoord[0] - 1][nCoord[0] - 1];
    }
    for (int i = 0; i < num_of_Coord - 1; i++) {
        sum += getStepSum(mCoord[i], nCoord[i], mCoord[i + 1], nCoord[i + 1]);
    }
    for (int i = 0; i < num_of_Coord - 2; i++) {  //减去重复加的部分
        sum -= matrix[mCoord[i + 1] - 1][nCoord[i + 1] - 1];
    }

    printf("%d", sum);

    return 0;
}

int getStepSum(int i1, int j1, int i2, int j2) {
    int StepSum = 0;
    if (i1 == i2) {  //m坐标相同
        if (j1 < j2) {
            for (int i = j1; i <= j2; i++) {
                StepSum += matrix[i1 - 1][i - 1];
            }
        } else {
            for (int i = j2; i <= j1; i++) {
                StepSum += matrix[i1 - 1][i - 1];
            }
        }
    }

    if (j1 == j2) {  //n坐标相同
        if (i1 < i2) {
            for (int i = i1; i <= i2; i++) {
                StepSum += matrix[i - 1][j1 - 1];
            }
        } else {
            for (int i = i2; i <= i1; i++) {
                StepSum += matrix[i - 1][j1 - 1];
            }
        }
    }

    return StepSum;
}
