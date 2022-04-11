//
//Created by 张益铭 on 4/11/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>
#include<cstring>

char constantAlphabets[20] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v',
                              'w',
                              'x', 'z'};

void getRegularPlural(char *arr);

int main() {
    char arr[100];
    scanf("%s", arr);
    getRegularPlural(arr);

    return 0;
}

void getRegularPlural(char *arr) {
    int len = strlen(arr);
    int flag = 0;
    for (int i = 0; i < 20; i++) {  //判断y前是否有辅音字母
        if (arr[len - 2] == constantAlphabets[i]) {
            flag = 1;
        }
    }
    if (arr[len - 1] == 's' || arr[len - 1] == 'x' || arr[len - 1] == 'z' ||
        (arr[len - 2] == 'c' || arr[len - 2] == 's') && arr[len - 1] == 'h') {
        arr[len] = 'e';
        arr[len + 1] = 's';
        arr[len + 2] = '\0';
    } else if (flag == 1 && arr[len - 1] == 'y') {
        arr[len - 1] = 'i';
        arr[len] = 'e';
        arr[len + 1] = 's';
        arr[len + 2] = '\0';
    } else {
        arr[len] = 's';
        arr[len + 1] = '\0';
    }

    printf("%s", arr);
}
