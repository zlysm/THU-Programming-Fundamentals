//
//Created by 张益铭 on 4/5/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <iostream>
#include<cstring>

using namespace std;

int main() {
    char str[99];
    cin.getline(str, 99);
    int length = strlen(str);
    
    int max = 0, count = 1;
    for (int i = 0; i < length - 1; i++) {
        if (str[i] <= str[i + 1]) {
            count++;
        } else {  //重置
            if (count > max) {
                max = count;
            }
            count = 1;
        }
    }
    if (count > max) {
        max = count;
    }
    cout << max << endl;

    return 0;
}
