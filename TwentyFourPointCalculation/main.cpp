// 计算二十四点 (TwentyFourPointCalculation)
// 源码: https://github.com/BlazeSnow/CppWorkspace
// 作者: BlazeSnow

#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int number[4] = {0};
const char Symbol[4] = {'+', '-', '*', '/'};
int times = 0;

void input() {
    while (true) {
        int error = 0;
        printf("请输入四个数字（以空格隔开）：\n");
        for (auto &i : number) {
            scanf("%d", &i);
            if (!(0 < i && i <= 13)) {
                error++;
            }
        }
        if (error == 0) {
            break;
        } else {
            fprintf(stderr, "ERROR:数字范围应当为1~13\n");
        }
    }
}

static int operation(int a, int b, char cul) {
    if (cul == '+') {
        return a + b;
    } else if (cul == '-') {
        return a - b;
    } else if (cul == '*') {
        return a * b;
    } else if ((cul == '/') && (a % b == 0)) {
        return a / b;
    } else {
        return -1000;
    }
}

static int parenthesis1(int num[], char cul[]) {
    int temp = operation(num[0], num[1], cul[0]);
    temp = operation(temp, num[2], cul[1]);
    return operation(temp, num[3], cul[2]);
}

static int parenthesis2(int num[], char cul[]) {
    int step1 = operation(num[0], num[1], cul[0]);
    int step2 = operation(num[2], num[3], cul[2]);
    return operation(step1, step2, cul[1]);
}

int main() {
    system("chcp 65001");
    system("cls");
    printf("Copyright (C) 2024-2026 BlazeSnow. 保留所有权利。\n");
    printf("当前程序版本号：v1.2.7\n");
    printf("https://github.com/BlazeSnow/CppWorkspace\n\n");

    input();
    printf("有以下结果:\n");
    sort(number, number + 4);
    do {
        for (char i : Symbol) {
            for (char j : Symbol) {
                for (char k : Symbol) {
                    char cul[3] = {i, j, k};
                    if (parenthesis1(number, cul) == 24) {
                        printf("((%d%c%d) %c%d )%c%d = 24\n", number[0], cul[0], number[1], cul[1], number[2], cul[2],
                               number[3]);
                        times++;
                    }
                    if (parenthesis2(number, cul) == 24) {
                        printf("(%d%c%d) %c (%d%c%d) = 24\n", number[0], cul[0], number[1], cul[1], number[2], cul[2],
                               number[3]);
                        times++;
                    }
                }
            }
        }
    } while (next_permutation(number, number + 4));
    printf("共有%d个答案\n", times);
    system("pause");
    return 0;
}
