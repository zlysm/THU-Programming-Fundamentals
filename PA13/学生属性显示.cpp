//
//Created by 张益铭 on 5/24/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <cstdio>
#include <cstring>

class Student {
public:
    char Name[99];
    char Age[99];
    char Type[99];
};

class Undergraduate : public Student {
public:
    char Specialty[99];
};

class Graduate : public Student {
public:
    char Direction[99];
};

int main() {
    int N;
    char name[99], age[99], type[99], specialty[99];
    scanf("%d", &N);

    auto *undergraduate = new Undergraduate[N];
    auto *graduate = new Graduate[N];
    int j = 0, k = 0;

    for (int i = 0; i < N; ++i) {
        scanf("%s %s %s %s", name, age, type, specialty);
        if (strcmp(type, "Undergraduate") == 0) {
            strcpy(undergraduate[j].Name, name);
            strcpy(undergraduate[j].Age, age);
            strcpy(undergraduate[j].Type, type);
            strcpy(undergraduate[j].Specialty, specialty);
            j++;
        } else {
            strcpy(graduate[k].Name, name);
            strcpy(graduate[k].Age, age);
            strcpy(graduate[k].Type, type);
            strcpy(graduate[k].Direction, specialty);
            k++;
        }
    }

    int M;
    char name_output[99][99], type_output[99][99];

    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%s %s", name_output[i], type_output[i]);
    }

    for (int i = 0; i < M; ++i) {
        bool isFind = false;
        for (int p = 0; p < j; ++p) {
            if (strcmp(undergraduate[p].Name, name_output[i]) == 0) {  // 判断是否是本科生
                if (strcmp(type_output[i], "Age") == 0) {
                    printf("%s\n", undergraduate[p].Age);
                    isFind = true;
                } else if (strcmp(type_output[i], "Type") == 0) {
                    printf("%s\n", undergraduate[p].Type);
                    isFind = true;
                } else if (strcmp(type_output[i], "Specialty") == 0) {
                    printf("%s\n", undergraduate[p].Specialty);
                    isFind = true;
                }
            }
        }

        for (int p = 0; p < k; ++p) {
            if (strcmp(graduate[p].Name, name_output[i]) == 0) {  // 判断是否是研究生
                if (strcmp(type_output[i], "Age") == 0) {
                    printf("%s\n", graduate[p].Age);
                    isFind = true;
                } else if (strcmp(type_output[i], "Type") == 0) {
                    printf("%s\n", graduate[p].Type);
                    isFind = true;
                } else if (strcmp(type_output[i], "Direction") == 0) {
                    printf("%s\n", graduate[p].Direction);
                    isFind = true;
                }
            }
        }

        if (!isFind) {
            printf("none\n");
        }
    }

    return 0;
}