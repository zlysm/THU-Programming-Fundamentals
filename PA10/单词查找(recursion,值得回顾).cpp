//
//Created by ������ on 5/2/2022.
//Copyright (C) ������ 2022. All Rights Reserved.
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
    //�ж������Ƿ�Ϸ�
    if (xCoord < 0 || xCoord >= COLUMN) return;
    if (yCoord < 0 || yCoord >= ROW) return;
    //�ַ������ֱ�ӷ���
    if (input[n] != WordsList[xCoord][yCoord]) return;

    for (int i = 0; i < n; ++i) {  //��ֹ������
        if (Coord[i] == 10 * xCoord + yCoord) {
            return;
        }
    }

    Coord[n] = 10 * xCoord + yCoord;  //eg:��32����ʾ(3,2)
    if (n == strlen(input) - 1) {  //�жϳ����Ƿ����ַ������ȣ�����û���жϵ����һλ
        for (int i = 0; i <= n; ++i) {
            printf("(%d,%d)", Coord[i] / 10 + 1, Coord[i] % 10 + 1);
        }
        printf("\n");
        count++;  //��¼����
        return;  //���һλ����ֹ
    }
    //����"x"�������ȣ�˳��ӦΪ14627358
    if (p != 1) {  //��"�游"���ԣ����ײ���1�����ӾͿ�����1���Զ��Ӷ����Ҹ����Ƿ���8
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
