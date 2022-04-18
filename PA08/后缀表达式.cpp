//
//Created by 张益铭 on 4/18/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <cstdio>
#include <cstring>

int Calculator(char *array);

int main() {
    char input[99];
    scanf("%[^\n]", input);
    int res = Calculator(input);
    printf("%d", res);

    return 0;
}

int Calculator(char *array) {
    int num, j = 0;
    int stack[99];
    for (int i = 0; i < strlen(array); i++) {
        if (array[i] >= '0' && array[i] <= '9') {
            num = array[i] - '0';
        } else {
            if (num != 0) {
                stack[j++] = num;
                num = 0;
            }
            if (array[i] == '+') {
                stack[j - 2] += stack[j - 1];
                j--;
            } else if (array[i] == '-') {
                stack[j - 2] -= stack[j - 1];
                j--;
            } else if (array[i] == '*') {
                stack[j - 2] *= stack[j - 1];
                j--;
            } else if (array[i] == '/') {
                stack[j - 2] /= stack[j - 1];
                j--;
            }
        }
    }

    int res = stack[0];
    return res;
}
