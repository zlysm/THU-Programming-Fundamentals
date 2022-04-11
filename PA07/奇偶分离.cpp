//
//Created by 张益铭 on 4/11/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>

void CountEvensAndOdds(const int arr[], int length_of_arr, int *length_of_odds, int *length_of_evens);

void Partition(const int arr[], int length_of_arr, int *odds, const int *length_of_odds, int *evens,
               const int *length_of_evens);

int main() {
    int length_of_arr;
    scanf("%d", &length_of_arr);  //输入数组长度
    int arr[length_of_arr];
    for (int i = 0; i < length_of_arr; i++) {  //输入数据
        scanf("%d", &arr[i]);
    }
    //计算奇偶个数
    int length_of_odds, length_of_evens;
    CountEvensAndOdds(arr, length_of_arr, &length_of_odds, &length_of_evens);
    //拆分奇偶数
    int odds[length_of_odds], evens[length_of_evens];
    Partition(arr, length_of_arr, odds, &length_of_odds, evens, &length_of_evens);
    //遍历输出
    for (int i = 0; i < length_of_odds; i++) {
        printf("%d ", odds[i]);
    }
    printf("\n");
    for (int i = 0; i < length_of_evens; i++) {
        printf("%d ", evens[i]);
    }

    return 0;
}

void CountEvensAndOdds(const int arr[], int length_of_arr, int *length_of_odds, int *length_of_evens) {
    *length_of_evens = 0;
    *length_of_odds = 0;
    for (int i = 0; i < length_of_arr; i++) {
        if (arr[i] % 2 == 0) {
            (*length_of_evens)++;
        } else {
            (*length_of_odds)++;
        }
    }
}

void Partition(const int arr[], int length_of_arr, int *odds, const int *length_of_odds, int *evens,
               const int *length_of_evens) {
    int i = 0, j = 0, k = 0;
    while (i < length_of_arr && j < *length_of_odds && k < *length_of_evens) {
        if (arr[i] % 2 == 0) {
            evens[k] = arr[i];
            k++;
        } else {
            odds[j] = arr[i];
            j++;
        }
        i++;
    }
    while (i < length_of_arr) {  //奇数或偶数存完后
        if (arr[i] % 2 == 0) {
            evens[k] = arr[i];
            k++;
        } else {
            odds[j] = arr[i];
            j++;
        }
        i++;
    }
}
