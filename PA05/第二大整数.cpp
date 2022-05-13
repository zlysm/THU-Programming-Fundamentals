//
//Created by 张益铭 on 3/28/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>
#include<climits>

const int MAX = 20;

int num[MAX];

int getSecMax(const int array[], int counter);

int main() {
    int input = 1, counter = 0;
    while (input) {
        scanf("%d", &input);
        num[counter] = input;
        counter++;
    }
    printf("%d", getSecMax(num, counter));

    return 0;
}

int getSecMax(const int array[], int counter) {
    int max = array[0];
    int second = INT_MIN;
    for (int i = 0; i < counter - 1; i++) {
        if (array[i] > max) {
            second = max;
            max = array[i];
        } else if (array[i] > second && array[i] < max) {
            second = array[i];
        }
    }

    return second;
}
