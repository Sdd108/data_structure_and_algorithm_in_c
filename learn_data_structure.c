//
// Created by Srutadeva das on 2022/11/9.
//
#include <stdio.h>
#include <time.h>
#include "learn_data_structure.h"

clock_t start, end;
double duration;

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

/* 数组最大子列和，算法：在线处理
 * "在线"的意思是指每输入一个数据就进行即时处理，在任何一个地方终止输入，算法都能正确给出当前的解。
 * 时间复杂度 O(n)
 */
int maxSubseqSum(int array[], int n) {
    int currentSum, maxSum;
    int i;
    currentSum = maxSum = 0;
    for (i = 0; i < n; ++i) {
        currentSum += array[i];
        if (currentSum > maxSum)
            maxSum = currentSum;
        else if (currentSum < 0)
            currentSum = 0;
    }
    return maxSum;
}



void test_data_structures() {
//    start = clock();
//    printN2(100000);
//    end = clock();
//    duration = ((double) (end - start)) / CLOCKS_PER_SEC;
//    printf("The time used: %fs\n", duration);

    int n = 10;
    int array[10] = {10, 3, 4 - 3, 6, 0, -13, 10, 4, 2, 1};
    int maxSum = maxSubseqSum(array, n);
    printf("The max sum is %d.\n", maxSum);


}

