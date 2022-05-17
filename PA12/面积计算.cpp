//
//Created by 张益铭 on 5/16/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include <cstdio>
#include <cmath>

double area(double type, double length);

double area(double type, double length, double width);

double area(double type, double length, double width, double height);

int main() {
    double type;
    double length, width, height;
    double res = 0;

    scanf("%lf", &type);

    if (type == 0 || type == 3) {
        scanf("%lf", &length);
        res = area(type, length);
    } else if (type == 1) {
        scanf("%lf %lf", &length, &width);
        res = area(type, length, width);
    } else if (type == 2) {
        scanf("%lf %lf %lf", &length, &width, &height);
        res = area(type, length, width, height);
    }

    printf("%.2lf", res);

    return 0;
}

double area(double type, double length) {
    if (type == 0) {
        return length * length;
    } else {
        return M_PI * length * length;
    }
}

double area(double type, double length, double width) {
    return length * width;
}

double area(double type, double length, double width, double height) {
    double s = (length + width + height) / 2;
    return sqrt(s * (s - length) * (s - width) * (s - height));
}
