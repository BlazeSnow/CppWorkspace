/*
 * 移位密码 (displacement-cipher)
 *
 * 一种最简单的字符级加密算法。每个字符按其ASCII码值向后偏移固定距离
 * (PASSWORD=5) 实现加密，向前偏移实现解密。例如输入 "abc" → 编码为 "fgh"，
 * 将 "fgh" 解码还原为 "abc"。偏移距离可修改源码中的 PASSWORD 宏调整。
 *
 * 注意: 仅支持char范围的ASCII字符，超出范围的字符(如中文)偏移后可能
 * 变成不可打印字符。这是一个教学性质的古典密码实现，不具备实际安全性。
 *
 * 源码: https://github.com/BlazeSnow/CppWorkspace
 * 原始仓库: https://github.com/BlazeSnow/displacement-cipher
 * 作者: BlazeSnow (2023-2026)
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

// 定义密码偏移量
#define PASSWORD 5

// 定义数组
vector<char> p;

// 编码密码
void bianma() {
    for (auto i : p) {
        printf("%c", (char)((int)i + PASSWORD));
    }
}

// 解码密码
void jiema() {
    for (auto i : p) {
        printf("%c", (char)((int)i - PASSWORD));
    }
}

int main() {
    system("chcp 65001");
    system("cls");
    printf("Copyright (C) 2024-2026 BlazeSnow. 保留所有权利。\n");
    printf("当前程序版本号：v1.0.3\n");
    printf("https://github.com/BlazeSnow/CppWorkspace\n\n");
    // 输入
    printf("移位密码移位距离：%d\n", PASSWORD);
    printf("请输入内容：\n");
    char input[1024];
    scanf(" %[^\n]", input);
    p = vector<char>(input, input + strlen(input));
    // 输出PASSWORD的值
    printf("\n");
    printf("移位密码移位距离：%d\n\n", PASSWORD);
    // 编码
    printf("编码的结果为:\n");
    bianma();
    printf("\n\n");
    // 解码
    printf("解码的结果为:\n");
    jiema();
    printf("\n\n");
    // 结束前暂停
    system("pause");
    return 0;
}
