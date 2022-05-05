//
//Created by 张益铭 on 5/2/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <cstdio>
#include <cstring>

#define COLUMN 9
#define ROW 7

const char WordsList[COLUMN][ROW] = {{'T', 'R', 'E', 'A', 'M', 'I', 'N'},
                                     {'E', 'T', 'S', 'R', 'A', 'M', 'S'},
                                     {'M', 'I', 'T', 'S', 'E', 'A', 'T'},
                                     {'A', 'E', 'M', 'T', 'A', 'I', 'N'},
                                     {'T', 'M', 'E', 'A', 'T', 'M', 'E'},
                                     {'M', 'E', 'A', 'T', 'I', 'E', 'T'},
                                     {'S', 'M', 'T', 'E', 'I', 'A', 'M'},
                                     {'E', 'I', 'M', 'A', 'S', 'E', 'I'},
                                     {'A', 'E', 'T', 'M', 'T', 'A', 'R'}};
int Coord[99];
int count = 0;

void find(char *input, int xCoord, int yCoord, int p, int n);

int main() {
    char input[10];
    scanf("%s", input);

    for (int i = 0; i < COLUMN; ++i) {
        for (int j = 0; j < ROW; ++j) {
            find(input, i, j, 0, 0);
        }
    }

    printf("%d", count);
    return 0;
}

void find(char *input, int xCoord, int yCoord, int p, int n) {
    //判断输入是否合法
    if (xCoord < 0 || xCoord >= COLUMN) return;
    if (yCoord < 0 || yCoord >= ROW) return;
    //字符不相等直接返回
    if (input[n] != WordsList[xCoord][yCoord]) return;

    for (int i = 0; i < n; ++i) {  //防止往回走
        if (Coord[i] == 10 * xCoord + yCoord) {
            return;
        }
    }

    Coord[n] = 10 * xCoord + yCoord;  //eg:用32来表示(3,2)
    if (n == strlen(input) - 1) {  //判断长度是否是字符串长度，即有没有判断到最后一位
        for (int i = 0; i <= n; ++i) {
            printf("(%d,%d)", Coord[i] / 10 + 1, Coord[i] % 10 + 1);
        }
        printf("\n");
        count++;  //记录个数
        return;  //最后一位，终止
    }
    //排序"x"坐标优先，顺序应为14627358
    if (p != 1) {  //对"祖父"而言，父亲不在1，儿子就可能在1，对儿子而言找父亲是否在8
        find(input, xCoord - 1, yCoord - 1, 8, n + 1);
    }
    if (p != 4) {
        find(input, xCoord - 1, yCoord, 5, n + 1);
    }
    if (p != 6) {
        find(input, xCoord - 1, yCoord + 1, 3, n + 1);
    }
    if (p != 2) {
        find(input, xCoord, yCoord - 1, 7, n + 1);
    }
    if (p != 7) {
        find(input, xCoord, yCoord + 1, 2, n + 1);
    }
    if (p != 3) {
        find(input, xCoord + 1, yCoord - 1, 6, n + 1);
    }
    if (p != 5) {
        find(input, xCoord + 1, yCoord, 4, n + 1);
    }
    if (p != 8) {
        find(input, xCoord + 1, yCoord + 1, 1, n + 1);
    }
}
