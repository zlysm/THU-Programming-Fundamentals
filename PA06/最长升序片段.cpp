//
//Created by 张益铭 on 4/5/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <cstdio>

int main() {
    char str[99];
    scanf("%s", str);
    int max = 0, count = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= str[i + 1]) {
            count++;
        } else {
            if (count > max) {
                max = count;
            }
            count = 1;
        }
    }
    if (count > max) {
        max = count;
    }
    printf("%d\n", max);

    return 0;
}
