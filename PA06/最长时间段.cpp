//
//Created by 张益铭 on 4/4/2022.
//Copyright (C) 张益铭 2022. All Rights Reserved.
//

#include<cstdio>

void getMaxTimeSpan();

int main() {
    getMaxTimeSpan();
    return 0;
}

void getMaxTimeSpan() {
    int num_of_events;
    scanf("%d", &num_of_events);
    int hour[num_of_events], min[num_of_events], sec[num_of_events];

    //输入时间
    for (int i = 0; i < num_of_events; i++) {
        scanf("%d:%d:%d", &hour[i], &min[i], &sec[i]);
    }

    //计算时间间隔
    int span[num_of_events - 1];
    for (int i = 0; i < num_of_events - 1; i++) {
        span[i] = (hour[i + 1] - hour[i]) * 3600 + (min[i + 1] - min[i]) * 60 + (sec[i + 1] - sec[i]);
    }

    //比较
    int flag, max = 0;
    for (int i = 0; i < num_of_events - 1; i++) {
        if (span[i] > max) {
            max = span[i];
            flag = i;
        }
    }

    int ans[3];
    if (sec[flag + 1] - sec[flag] < 0) {
        ans[2] = sec[flag + 1] - sec[flag] + 60;
        min[flag + 1] -= 1;
    } else {
        ans[2] = sec[flag + 1] - sec[flag];
    }
    if (min[flag + 1] - min[flag] < 0) {
        ans[1] = min[flag + 1] - min[flag] + 60;
        hour[flag + 1] -= 1;
    } else {
        ans[1] = min[flag + 1] - min[flag];
    }
    ans[0] = hour[flag + 1] - hour[flag];

    printf("%d:%d:%d", ans[0], ans[1], ans[2]);
}
