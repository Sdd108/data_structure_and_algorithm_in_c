//
// Created by Srutadeva das on 2022/11/9.
//

#ifndef HELLO_C_SINGLELINKEDLIST_H
#define HELLO_C_SINGLELINKEDLIST_H

#endif //HELLO_C_SINGLELINKEDLIST_H

// 定义节点结构体
typedef int SLDataType;
typedef struct SListNode {
    SLDataType data;
    struct SListNode *next;
} SListNode;

// 初始化一个节点
void SListInitNode(SListNode **plist, SLDataType x);

// 头插
void SListPushFront(SListNode **plist, SLDataType x);

// 头删
void SListPopFront(SListNode **plist);

// 尾插
void SListPushBack(SListNode **plist, SLDataType x);

// 尾删
void SListPopBack(SListNode **plist);

// 在pos位置之后插入
void SListInsertAfter(SListNode *pos, SLDataType x);

// 尾删
void SListPopBack(SListNode **plist);

// 在pos位置之后删除
void SListEraseAfter(SListNode *pos);

// 单链表的查找
SListNode *SListFind(SListNode *plist, SLDataType x);

// 测试
void testSingleLinkedList();
