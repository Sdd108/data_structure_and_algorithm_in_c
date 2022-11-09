//
// Created by Srutadeva das on 2022/11/9.
//

#include "singleLinkedList.h"

/*
 * 链表的实现
 */

// 初始化一个节点
void SListInitNode(SListNode **plist, SLDataType x) {
    assert(plist);
    *plist = (SListNode *) malloc(sizeof(SListNode));
    assert(*plist);
    (*plist)->data = x;
    (*plist)->next = NULL;
}

// 头插
void SListPushFront(SListNode **plist, SLDataType x) {
    assert(plist);
    SListNode *ptr = *plist;
    SListInitNode(plist, x);
    (*plist)->next = ptr;
}

// 头删
void SListPopFront(SListNode **plist) {
    assert(*plist);
    assert(plist);
    SListNode *ptr = (*plist)->next;
    free(*plist);
    *plist = ptr;
}

// 尾插
void SListPushBack(SListNode **plist, SLDataType x) {
    assert(plist);
    if (*plist == NULL) {
        SListInitNode(plist, x);
    } else {
        SListNode *ptr = *plist;
        while (ptr->next) {
            ptr = ptr->next;
        }
        SListInitNode(&(ptr->next), x);
    }
}

// 在pos位置之后插入
void SListInsertAfter(SListNode *pos, SLDataType x) {
    assert(pos);
    SListNode *ptr = NULL;
    ptr = (SListNode *) malloc(sizeof(SListNode));
    assert(ptr);
    ptr->data = x;
    ptr->next = pos->next;
    pos->next = ptr;
}

// 尾删
void SListPopBack(SListNode **plist) {
    assert(plist);
    assert(*plist);
    if ((*plist)->next == NULL) {
        free(*plist);
        *plist = NULL;
    } else {
        SListNode *ptr = *plist;
        while (ptr->next->next) {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
}

// 在pos位置之后删除
void SListEraseAfter(SListNode *pos) {
    assert(pos);
    assert(pos->next);
    SListNode *ptr = pos->next;
    pos->next = pos->next->next;
    free(ptr);
    ptr = NULL;
}

// 单链表的查找
SListNode *SListFind(SListNode *plist, SLDataType x) {
    assert(plist);
    while (plist) {
        if (plist->data == x)
            return plist;
        plist = plist->next;
    }
    return NULL;
}

// 测试链表
void testSingleLinkedList() {

}
