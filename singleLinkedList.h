//
// Created by Srutadeva das on 2022/11/9.
//

#ifndef HELLO_C_SINGLELINKEDLIST_H
#define HELLO_C_SINGLELINKEDLIST_H

#endif //HELLO_C_SINGLELINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define OK 1;
#define ERROR 0;

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *InitList(int val);

int TestSingleLinkedList();
