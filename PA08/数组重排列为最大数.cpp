//
//Created by 张益铭 on 4/18/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>

int getMaxReverse(int ori_num);

int getMax(int *array, int len);

int main() {
    int ori_num;
    scanf("%d", &ori_num);

    printf("%d", getMaxReverse(ori_num));

    return 0;
}

int getMaxReverse(int ori_num) {
    int sep_num[5], len = 0;
    for (int i = 0; ori_num != 0; i++) {  //把每位数字分开
        sep_num[i] = ori_num % 10;
        ori_num /= 10;
        len++;
    }
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = res * 10 + getMax(sep_num, len);
    }

    return res;
}

int getMax(int *array, int len) {  //找到最大的并归零
    int flag, max = array[0];
    for (int i = 0; i < len; i++) {
        if (array[i] >= max) {
            max = array[i];
            flag = i;
        }
    }
    array[flag] = 0;

    return max;
}
