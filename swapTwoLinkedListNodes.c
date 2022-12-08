//
// Created by Srutadeva das on 2022/11/18.
//

#include "swapTwoLinkedListNodes.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int Score;
    struct node *Next;
} Node, *List;

void Insert(List *L, Node e) {
    List temp = *L;
    List n = (List) malloc(sizeof(Node));
    n->Score = e.Score;
    if (temp == NULL) {
        *L = n;
    } else {
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = n;
    }
    n->Next = NULL;
}

void Swap(List *L, int i, int j) {
    List temp = *L;
    List t1;
    List t2;
    List t3;
    List t4;
    List t5;
    int m;
    /*i和j为1时情况比较特殊，需要让表头重新指向交换后的那个节点*/
    if (i == 1) {
        t1 = *L;
        for (m = 1; temp->Next != NULL; m++, temp = temp->Next) {
            if (m + 1 == j) {
                *L = temp->Next;
                t2 = temp->Next->Next;
                temp->Next->Next = t1->Next;
                t1->Next = t2;
                temp->Next = t1;
            }
        }
    }
    if (j == 1) {
        t1 = *L;
        for (m = 1; temp->Next != NULL; m++, temp = temp->Next) {
            if (m + 1 == i) {
                *L = temp->Next;
                t2 = temp->Next->Next;
                temp->Next->Next = t1->Next;
                t1->Next = t2;
                temp->Next = t1;
            }
        }
    }
        /*相邻节点之间交换和非相邻结点之间交换不一样*/
    else {
        if ((i - j) != 1 && (j - i) != 1) {//非相邻结点之间交换
            for (m = 1; temp->Next != NULL; m++, temp = temp->Next) {
                if (m + 1 == i) {
                    t1 = temp;
                }
                if (m + 1 == j) {
                    t2 = temp;
                }
            }
            t5 = t1->Next->Next;
            t3 = t1->Next;
            t4 = t2->Next;
            t1->Next = t4;
            t2->Next = t3;
            t3->Next = t4->Next;
            t4->Next = t5;
        } else if (i < j) {//相邻节点之间交换
            for (m = 1; temp != NULL; m++, temp = temp->Next) {
                if (m + 1 == i) {
                    t1 = temp;
                }
                if (m == j) {
                    t2 = temp;
                }
            }
            temp = t2->Next;
            t3 = t1->Next;
            t1->Next = t2;
            t3->Next = temp;
            t2->Next = t3;
        } else if (i > j) {
            for (m = 1; temp != NULL; m++, temp = temp->Next) {
                if (m + 1 == j) {
                    t1 = temp;
                }
                if (m == i) {
                    t2 = temp;
                }
            }
            temp = t2->Next;
            t3 = t1->Next;
            t1->Next = t2;
            t3->Next = temp;
            t2->Next = t3;
        }
    }
}

void printflist(List list) {
    List temp;
    for (temp = list; temp != NULL; temp = temp->Next) {
        printf("%d\n", temp->Score);
    }
}

void freelist(List *list) {
    List temp = *list, del;
    while (temp != NULL) {
        del = temp;
        temp = temp->Next;
        free(del);
    }
}

int testSwapTwoLinkedListNodes() {
    List list = NULL;
    Node n1, n2, n3, n4, e;//定义5个节点
    e.Score = 5;
    n1.Score = 1;
    n2.Score = 2;
    n3.Score = 3;
    n4.Score = 4;
    Insert(&list, n1);
    Insert(&list, n2);
    Insert(&list, n3);
    Insert(&list, n4);
    Insert(&list, e);
    // dellist(&list, 8);
    Swap(&list, 5, 4);
    printflist(list);
    freelist(&list);
    return 0;
}