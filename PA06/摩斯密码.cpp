//
//Created by 张益铭 on 4/5/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <cstdio>
#include <cstring>

#define LENGTH 100

void print_encode(char *morse);

void get_morse(char *p);

int main() {
    char array[LENGTH] = {0};
    scanf("%[^\r]%*c", array);
    get_morse(array);
    return 0;
}

void get_morse(char *p) {
    char tmp_str[8] = {0};
    int i = 0;
    while (*p != 0 && *p != ' ') {
        tmp_str[i] = *p;
        p++;
        i++;
    }
    if (0 == *p) {
        print_encode(tmp_str);
        return;
    } else if (*p == ' ' && *(p + 1) != ' ') {
        print_encode(tmp_str);
        p += 1;
    } else {
        print_encode(tmp_str);
        printf(" ");
        p += 2;
    }
    get_morse(p);
}

void print_encode(char *morse) {
    if (strcmp(morse, ".-") == 0) printf("A");
    if (strcmp(morse, "-...") == 0) printf("B");
    if (strcmp(morse, "-.-.") == 0) printf("C");
    if (strcmp(morse, "-..") == 0) printf("D");
    if (strcmp(morse, ".") == 0) printf("E");
    if (strcmp(morse, "..-.") == 0) printf("F");
    if (strcmp(morse, "--.") == 0) printf("G");
    if (strcmp(morse, "....") == 0) printf("H");
    if (strcmp(morse, "..") == 0) printf("I");
    if (strcmp(morse, ".---") == 0) printf("J");
    if (strcmp(morse, "-.-") == 0) printf("K");
    if (strcmp(morse, ".-..") == 0) printf("L");
    if (strcmp(morse, "--") == 0) printf("M");
    if (strcmp(morse, "-.") == 0) printf("N");
    if (strcmp(morse, "---") == 0) printf("O");
    if (strcmp(morse, ".--.") == 0) printf("P");
    if (strcmp(morse, "--.-") == 0) printf("Q");
    if (strcmp(morse, ".-.") == 0) printf("R");
    if (strcmp(morse, "...") == 0) printf("S");
    if (strcmp(morse, "-") == 0) printf("T");
    if (strcmp(morse, "..-") == 0) printf("U");
    if (strcmp(morse, "...-") == 0) printf("V");
    if (strcmp(morse, ".--") == 0) printf("W");
    if (strcmp(morse, "-..-") == 0) printf("X");
    if (strcmp(morse, "-.--") == 0) printf("Y");
    if (strcmp(morse, "--..") == 0) printf("Z");
}
