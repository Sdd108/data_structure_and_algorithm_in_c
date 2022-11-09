//
// Created by Srutadeva das on 2022/11/9.
//
#include <stdio.h>
#include "learn_data_structure.h"

void test_data_structures() {
    printN2(100000);
}

// 顺序打印 1 到 n 的正整数，方法一
void printN1(int n) {
    for (int i = 1; i <= n; ++i)
        printf("%d\n", i);
}

// 顺序打印 1 到 n 的正整数，递归法
void printN2(int n) {  // 当 n = 100000 时已经跑不出来了，空间占用过大
    if (n) {
        printN2(n - 1);
        printf("%d\n", n);
    }
    return;
}
