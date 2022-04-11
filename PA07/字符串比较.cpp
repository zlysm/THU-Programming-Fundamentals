//
//Created by 张益铭 on 4/11/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>
#include<cstring>

void my_strcmp(const char *arr1, const char *arr2);

int main() {
    char arr1[20], arr2[20];
    scanf("%[^\n]", arr1);
    getchar();
    scanf("%[^\n]", arr2);
    my_strcmp(arr1, arr2);

    return 0;
}

void my_strcmp(const char *arr1, const char *arr2) {
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    if (len1 < len2) len1 = len2;
    int count = 0;
    for (int i = 0; i < len1; i++) {
        if (arr1[i] > arr2[i]) {
            printf("大于");
            break;
        } else if (arr1[i] < arr2[i]) {
            printf("小于");
            break;
        }
        count++;
    }
    if (count == len1) {
        printf("等于");
    }
}
