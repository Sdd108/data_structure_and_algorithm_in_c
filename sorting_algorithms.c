//
// Created by Srutadeva das on 2022/12/8.
//

#include "sorting_algorithms.h"


void printArr(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b\n");  // 回退两格，删除句尾的逗号和空格，并换行
}

void insertSort(int *arr, int n) {
    if (n < 1) return;

    int i, j, key;
    for (i = 1; i < n; ++i) {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
//        printArr(arr, n);
    }
}

void swapTwoInteger(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void bubbleSort(int *arr, int n) {
    if (n < 1) return;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i; ++j) {
            if (arr[j + 1] < arr[j]) swapTwoInteger(&arr[j + 1], &arr[j]);
        }
//        printArr(arr, n);
    }
}


void selectionSort(int *arr, int n) {
    if (n < 1) return;

    int idxMax, tmpMax;
    for (int i = 0; i < n - 1; ++i) {
        idxMax = 0;
        tmpMax = arr[0];
        for (int j = 0; j < n - i; ++j) {
            if (arr[j] > tmpMax) {
                idxMax = j;
                tmpMax = arr[j];
            }
        }
        swapTwoInteger(&arr[idxMax], &arr[n - i - 1]);
//        printArr(arr, n);
    }
}


/*
 * 快速排序
 * 时间复杂度：O(nlogn)
 */
int partition(int *arr, int left, int right) {
    int tmp = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= tmp) right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= tmp) left++;
        arr[right] = arr[left];
    }
    arr[left] = tmp;
    return left;
}

void QSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = partition(arr, left, right);
        QSort(arr, left, mid - 1);
        QSort(arr, mid + 1, right);
    }
}

void quickSort(int *arr, int n) {
    QSort(arr, 0, n);
}


void testSortingAlgorithms() {
    // 随机生成整数
    const int n = 200;
    const int MAX_RANGE = 200;
    static unsigned int seq = 0;
    int arr[n];
    srand(time(0) + (seq++));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % MAX_RANGE;
    }
    printArr(arr, n);

    // 排序
//    insertSort(arr, n);
//    bubbleSort(arr, n);
//    selectionSort(arr, n);
    quickSort(arr, n);

    printArr(arr, n);
}