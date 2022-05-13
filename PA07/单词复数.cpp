//
//Created by ������ on 4/11/2022.
//Copyright (C) ������ 2022. All Rights Reserved.
//

#include<cstdio>
#include<cstring>

char constantAlphabets[20] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v',
                              'w',
                              'x', 'z'};

char *getRegularPlural(char *arr);

int main() {
    char arr[100];
    scanf("%s", arr);
    printf("%s", getRegularPlural(arr));

    return 0;
}

char *getRegularPlural(char *arr) {
    int len = strlen(arr);
    int flag = 0;
    for (char constantAlphabet: constantAlphabets) {  //�ж�yǰ�Ƿ��и�����ĸ
        if (arr[len - 2] == constantAlphabet) {
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
    return arr;
}
