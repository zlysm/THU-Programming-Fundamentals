//
//Created by 张益铭 on 4/25/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <iostream>

using namespace std;

string sort(string s);

int main() {
    string input;
    cin >> input;
    cout << sort(input);

    return 0;
}

string sort(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        for (int j = 0; j < s.length() - i - 1; j++) {
            if (s[j] < s[j + 1]) {
                char temp;
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    return s;
}
