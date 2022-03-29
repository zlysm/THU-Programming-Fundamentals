//
//Created by 张益铭 on 3/28/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>

int main() {
    int M = 0, N = 0, a[200] = {0}, b = 0;
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M + N; i++) {
        scanf("%d", &b);
        a[b + 100] = 1;
    }
    for (int i = 0; i < 199; i++) {
        if (a[i] != 0) {
            printf("%d ", i - 100);
        }
    }
    return 0;
}
