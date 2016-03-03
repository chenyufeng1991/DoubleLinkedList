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

//7.返回不带头节点的双向非循环链表中第pos位置的元素
int getElement(Node *pNode,int pos){

    int i = 1;
    Node *pMove;
    pMove = pNode;
    while (pMove != NULL) {

        if (i == pos) {

            printf("%s函数执行，第pos=%d位置的元素是%d\n",__FUNCTION__,pos,pMove->element);
            return pMove->element;
        }

        i++;
        pMove = pMove->next;
    }

    printf("%s函数执行，获取pos位置的元素失败\n",__FUNCTION__);

    return -1;
}

//8.从不带头结点的双链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL
int *getElemAddr(Node *pNode,int x){

    Node *pMove;
    pMove = pNode;
    while (pMove != NULL) {
        if (pMove->element == x) {
            printf("%s函数执行，x=%d元素的内存地址为:0x%x\n",__FUNCTION__,x,&(pMove->element));
            return &(pMove->element);
        }
        pMove = pMove->next;
    }
    printf("%s函数执行，获取x=%d内存地址失败\n",__FUNCTION__,x);
    return &(pMove->element);
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

    getElement(pList, 4);

    getElemAddr(pList, 5);

    pList = clearList(pList);
    printList(pList);
    
    return 0;
}










