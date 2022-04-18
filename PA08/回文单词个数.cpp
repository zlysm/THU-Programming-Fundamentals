//
//Created by 张益铭 on 4/18/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <cstdio>
#include <cstring>

int number_of_Palindrome(char *array);

bool isPalindrome(char *array);

int main() {
    char ori_input[80];
    scanf("%[^\n]", ori_input);
    int res = number_of_Palindrome(ori_input);
    printf("%d", res);

    return 0;
}

int number_of_Palindrome(char *array) {
    char sep_input[99][99];
    int column = 0, row = 0, count = 0;
    for (int i = 0; i < strlen(array); i++) {  //将单词分开
        if (array[i] != ' ') {
            sep_input[column][row++] = array[i];
        } else {
            sep_input[column][row] = '\0';
            row = 0;
            column++;
        }
    }
    sep_input[column][row] = '\0';

    for (int i = 0; i <= column; i++) {  //判断每个单词是否是回文数
        if (isPalindrome(sep_input[i])) {
            count++;
        }
    }

    return count;
}

bool isPalindrome(char *array) {
    for (int i = 0; i < strlen(array) / 2; i++) {
        if (array[i] != array[strlen(array) - i - 1]) {
            return false;
        }
    }
    return true;
}
