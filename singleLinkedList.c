//
// Created by Srutadeva das on 2022/11/9.
//

#include "singleLinkedList.h"

/*
 * 无头、单向、非循环链表的实现
 */

// 初始化链表，需要提供一个初始值
struct ListNode *InitList(int val) {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = val;
    head->next = NULL;
    return head;
}

// 遍历链表并打印
int TraverseLinkedList(struct ListNode *head) {
    for (struct ListNode *cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->val);
    }
    return OK;
}

// 追加值
int LinkedListAppend(struct ListNode *head, int val) {
    struct ListNode *tail = head;
    for (; tail->next != NULL; tail = tail->next);

    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    tail->next = newNode;

    return 0;
}

// 弹出末尾的元素
int LinkedListPop(struct ListNode *head, int *elem) {
    // 0 个元素
    if (!head) return ERROR;

    // 1 个元素
    if (!head->next) {
        *elem = head->val;
        free(head);
        head = NULL;

        return OK;
    }

    // 2个或2个以上元素
    struct ListNode *pre = head->next;
    while (!pre->next->next) pre = pre->next;
    *elem = pre->next->val;
    free(pre->next);
    pre->next = NULL;
    return OK;
}


int TestSingleLinkedList() {
    int val = 0;
    struct ListNode *head = InitList(val);

    for (int i = 1; i < 10; i++) {
        LinkedListAppend(head, i);
    }
    TraverseLinkedList(head);

    return 0;
}
