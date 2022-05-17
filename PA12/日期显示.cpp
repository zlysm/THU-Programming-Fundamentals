//
//Created by 张益铭 on 5/16/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <iostream>
#include <string>

using namespace std;

const char Month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                            "October", "November", "December"};

class Date {
public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    Date(const string &m, int d, int y);

    explicit Date(const string &date);

    void print(int type) const;

private:
    int month{};
    int day{};
    int year{};
};

Date::Date(const string &m, int d, int y) {
    if (m == "January") {
        month = 1;
    } else if (m == "February") {
        month = 2;
    } else if (m == "March") {
        month = 3;
    } else if (m == "April") {
        month = 4;
    } else if (m == "May") {
        month = 5;
    } else if (m == "June") {
        month = 6;
    } else if (m == "July") {
        month = 7;
    } else if (m == "August") {
        month = 8;
    } else if (m == "September") {
        month = 9;
    } else if (m == "October") {
        month = 10;
    } else if (m == "November") {
        month = 11;
    } else if (m == "December") {
        month = 12;
    }
    day = d;
    year = y;
}

Date::Date(const string &date) {
    sscanf(date.c_str(), "%d年%d月%d日", &year, &month, &day);
}

void Date::print(int type) const {
    if (type == 1) {
        if (month < 10) {
            cout << 0;
        }
        cout << month << "/";
        if (day < 10) {
            cout << 0;
        }
        cout << day << "/" << year;
    } else if (type == 2) {
        cout << Month[month - 1] << ' ';
        if (day < 10) {
            cout << 0;
        }
        cout << day << ", " << year;
    } else {
        cout << year << "年" << month << "月" << day << "日";
    }
}

int main() {
    int inputType, outputType;
    cin >> inputType;

    if (inputType == 1) {
        int m, d, y;

        cin >> m >> d >> y;
        Date date(m, d, y);

        cin >> outputType;
        date.print(outputType);
    } else if (inputType == 2) {
        std::string month;
        int d, y;

        cin >> month >> d >> y;
        Date date(month, d, y);

        cin >> outputType;
        date.print(outputType);
    } else {
        std::string t;

        cin >> t;
        Date date(t);

        cin >> outputType;
        date.print(outputType);
    }

    return 0;
}