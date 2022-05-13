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

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int status[COLUMN][ROW] = {0};
int xNum[99];
int yNum[99];

bool Search(char *input, int xCoord, int yCoord);

bool SearchNext(const char *input, int xCoord, int yCoord, int number);

int main() {
    char input[10];
    int count = 0;
    scanf("%s", input);

    for (int i = 0; i < COLUMN; ++i) {
        for (int j = 0; j < ROW; ++j) {
            if (WordsList[i][j] == input[0]) {  //与第一个字母相同，开始搜索
                xNum[0] = i;  //防止(0,0)被跳过
                yNum[0] = j;
                while (Search(input, i, j)) {  //找多种情况
                    xNum[0] = i;
                    yNum[0] = j;
                    for (int k = 0; k < strlen(input); ++k) {
                        printf("(%d,%d)", xNum[k] + 1, yNum[k] + 1);
                    }
                    printf("\n");
                    count++;
                    memset(xNum, 0, sizeof(xNum));
                    memset(yNum, 0, sizeof(yNum));
                }
            }
            memset(xNum, 0, sizeof(xNum));
            memset(yNum, 0, sizeof(yNum));
            memset(status, 0, sizeof(status));
        }
    }
    printf("%d", count);

    return 0;
}

bool Search(char *input, int xCoord, int yCoord) {
    int count = 1;

    for (int i = 1; i < strlen(input); ++i) {
        for (int j = 0; j < 8; ++j) {
            if (SearchNext(input, xCoord + dx[j], yCoord + dy[j], i)) {
                if (i == strlen(input) - 1) {  //将正确路线末尾标记
                    status[xCoord + dx[j]][yCoord + dy[j]] = 1;
                }
                //记录坐标
                xNum[i] = xCoord + dx[j];
                yNum[i] = yCoord + dy[j];
                //判断下一个
                xCoord += dx[j];
                yCoord += dy[j];
                count++;
                break;
            }
        }
    }

    if (count == strlen(input)) {
        return true;
    } else {
        return false;
    }
}

bool SearchNext(const char *input, int xCoord, int yCoord, int number) {
    if (xCoord < 0 || xCoord >= COLUMN || yCoord < 0 || yCoord >= ROW || number >= strlen(input)) {  //输入不合法
        return false;
    }

    for (int i = 0; i < number; ++i) {  //防止往回走
        if (xCoord == xNum[i] && yCoord == yNum[i]) {
            return false;
        }
    }

    if (WordsList[xCoord][yCoord] == input[number]) {
        if (number == strlen(input) - 1 && status[xCoord][yCoord] == 1) {
            return false;
        }
        return true;
    } else {
        return false;
    }
}
