//
//Created by 张益铭 on 4/26/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <cstdio>
#include <cstring>

void FindKeyWords(char *keywords, char *ori_input);

bool isKeyWords(const char *keywords, const char *input);

int main() {
    char keywords[99], ori_input[99];
    scanf("%[^\n]", keywords);
    getchar();
    scanf("%[^\n]", ori_input);
    getchar();

    FindKeyWords(keywords, ori_input);

    return 0;
}

void FindKeyWords(char *keywords, char *ori_input) {
    char sep_input[99][99], sep_keywords[99][99];

    int column1 = 0, row1 = 0;
    for (int i = 0; i < strlen(ori_input); i++) {  //将要判断的单词分开
        if (ori_input[i] != ' ') {
            sep_input[column1][row1++] = ori_input[i];
        } else {
            sep_input[column1++][row1] = '\0';
            row1 = 0;
        }
    }
    sep_input[column1][row1] = '\0';

    int column2 = 0, row2 = 0;
    for (int i = 0; i < strlen(keywords); i++) {  //将关键词分开
        if (keywords[i] != ' ') {
            sep_keywords[column2][row2++] = keywords[i];
        } else {
            sep_keywords[column2++][row2] = '\0';
            row2 = 0;
        }
    }
    sep_keywords[column2][row2] = '\0';

    for (int i = 0; i < column1 + 1; i++) {  //输出结果
        for (int j = 0; j < column2 + 1; j++) {
            if (isKeyWords(sep_keywords[j], sep_input[i])) {
                printf("%s ", sep_keywords[j]);
            }
        }
    }
}

bool isKeyWords(const char *keywords, const char *input) {
    unsigned int len1 = strlen(keywords);
    unsigned int len2 = strlen(input);
    int count = 0;

    char input_cpy[99];
    for (int i = 0; i < len2; i++) {
        input_cpy[i] = input[i];
        input_cpy[i + 1] = '\0';
    }

    if (len1 == len2) {
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (keywords[i] == input_cpy[j]) {
                    count++;
                    input_cpy[j] = 0;
                    break;
                }
            }
        }
        if (count == len1 && count != 0) {
            return true;
        }
    }
    return false;
}
