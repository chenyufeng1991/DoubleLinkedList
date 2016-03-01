//
//  main.c
//  DoubleLinkedList
//
//  Created by chenyufeng on 16/2/27.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  实现一个非循环双向链表（不带头结点）
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//1.初始化不带头结点的非循环双向链表
void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，链表初始化完成\n",__FUNCTION__);
}

//2.创建非循环双向链表
Node *createList(Node *pNode){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;
    pInsert->prior = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;

    if (pInsert->element <= 0) {

        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0) {
        if (pNode == NULL) {
            pNode = pInsert;
            pMove = pNode;
        }else{

            pMove->next = pInsert;
            pInsert->prior = pMove;
            pMove = pMove->next;
        }

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;
        pInsert->prior = NULL;
        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行，建立链表成功\n",__FUNCTION__);

    return pNode;
}

//3.打印非循环双向链表
void printList(Node *pNode){

    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//4.清除线性表L中的所有元素，使之成为一个空表
Node *clearList(Node *pNode){

    if (pNode == NULL) {
        printf("%s函数执行，原链表就是空链表，无须执行该方法\n",__FUNCTION__);
        return  NULL;
    }else{
        while (pNode->next != NULL) {

            //一次删除每一个节点
            pNode = pNode->next;
            free(pNode->prior);
            pNode->prior = NULL;
        }

        //清除最后一个节点
        free(pNode);
        pNode = NULL;

        printf("%s函数执行，双向非循环链表清空成功\n",__FUNCTION__);
        return pNode;
    }
}

//5.返回不带头节点的双向链表的长度
int sizeList(Node *pNode){

    int i = 0;
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，长度为0\n",__FUNCTION__);
        return 0;
    }else{

        while (pNode != NULL) {
            i++;
            pNode = pNode->next;
        }
        printf("%s函数执行，链表长度为%d\n",__FUNCTION__,i);
        return i;
    }
}

//6.检查双链表链表是否为空，若为空则返回１，否则返回０
int isEmptyList(Node *pNode){

    if (pNode == NULL) {
        printf("%s函数执行，当前链表为空\n",__FUNCTION__);
        return 1;
    }
    printf("%s函数执行，当前链表非空\n",__FUNCTION__);

    return 0;
}


int main(int argc, const char * argv[]) {

    Node *pList;

    initList(pList);
    printList(pList);
    sizeList(pList);

    pList = createList(pList);
    printList(pList);
    sizeList(pList);

    isEmptyList(pList);
    
    pList = clearList(pList);
    printList(pList);
    
    return 0;
}










