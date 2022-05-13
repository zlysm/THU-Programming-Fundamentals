//
//Created by 张益铭 on 5/8/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool SpellChecker(const string &input, string *List, int ListNum);

int getMax(int num1, int num2);

int main() {
    string input, List[100];
    int ListNum;

    cin >> input;
    cin >> ListNum;
    for (int i = 0; i < ListNum; ++i) {
        cin >> List[i];
    }

    if (!SpellChecker(input, List, ListNum)) {
        cout << "NOANSWER";
    }

    return 0;
}

bool SpellChecker(const string &input, string *List, int ListNum) {
    for (int i = 0; i < ListNum; ++i) {
        if (input == List[i]) {  //输入正确
            cout << input;
            return true;
        }

        for (int j = 0; j < getMax(List[i].length(), input.length()); ++j) {
            string input_cpy = input;
            string List_cpy = List[i];

            if (List[i].length() > input.length()) {  //少输
                List_cpy.erase(j, 1);
            } else if (List[i].length() < input.length()) {  //多输
                input_cpy.erase(j, 1);
            } else {  //输错
                List_cpy.erase(j, 1);
                input_cpy.erase(j, 1);
            }

            if (input == List_cpy || List[i] == input_cpy || input_cpy == List_cpy) {
                cout << List[i];
                return true;
            }
        }
    }

    return false;
}

int getMax(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}
