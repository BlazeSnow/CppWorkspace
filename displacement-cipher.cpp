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
 * 作者: BlazeSnow (2023-2025)
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 定义密码偏移量
#define PASSWORD 5

// 定义数组
vector<char> p;

// 编码密码
void bianma() {
  for (auto i : p) {
    cout << (char)((int)i + PASSWORD);
  }
}

// 解码密码
void jiema() {
  for (auto i : p) {
    cout << (char)((int)i - PASSWORD);
  }
}

int main() {
  system("chcp 65001");
  system("cls");
  cout << "Copyright (C) 2024-2025 BlazeSnow. 保留所有权利。" << endl;
  cout << "当前程序版本号：v1.0.2" << endl;
  cout << "https://github.com/BlazeSnow/displacement-cipher" << endl << endl;
  // 输入
  cout << "移位密码移位距离：" << PASSWORD << endl;
  cout << "请输入内容：" << endl;
  string input;
  getline(cin, input);
  p = vector<char>(input.begin(), input.end());
  // 输出PASSWORD的值
  cout << endl;
  cout << "移位密码移位距离：" << PASSWORD << endl << endl;
  // 编码
  cout << "编码的结果为:" << endl;
  bianma();
  cout << endl << endl;
  // 解码
  cout << "解码的结果为:" << endl;
  jiema();
  cout << endl << endl;
  // 结束前暂停
  system("pause");
  return 0;
}
