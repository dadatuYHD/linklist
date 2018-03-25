/********************************************************
 * cal
*   Copyright (C) 2016 All rights reserved.
*   
*   Filename:commom.h
*   Author  :tanw
*   Date    :2016-08-02
*   Describe:
*
********************************************************/
#ifndef _COMMOM_H
#define _COMMOM_H

#include <stdbool.h>

typedef int data_t;

typedef struct node_t
{
	data_t data;
	struct node_t *next;
}linklist;

void CreateLinkList(linklist **head, int n);
void CreateLinkListTwo(linklist **head, int n);
linklist* CreateLoopLinkList(linklist **loophead, int n);
void ClearLinkList(linklist *head);
int EmptyLinkList(linklist *head);
int FullLinkList(linklist *head);
int LengthLinkList(linklist *head);
int InsertLinkList(linklist *head, int local, data_t data);
int DeleteDataLinkList(linklist *head, data_t data);
int DEleteLocalLinkList(linklist *head, int local);
int GetLinkList(linklist *head, int local, data_t *data);
int LocalLinkList(linklist *head, data_t data);
void DestoryLinkList(linklist **head);
void ReverseDisplayLinkList(linklist *head);
void DisplayLinkList(linklist *head);
int ChangeDataLinkList(linklist *head, data_t olddata, data_t newdata);
int ChangeLocalLinkList(linklist *head, int local, data_t data);
void ReverseLinklistOne(linklist **head);
void ReverseLinklistTwo(linklist **head);
int GetLastLinklist(linklist *head, int last);
int GetMidLinklist(linklist *head);
void DeleteNode(linklist * node);
void DeletePreNode(linklist * pNode);
linklist * GetMidAddrLinklist(linklist *head);
bool JudgeLoopLinklist(linklist *head);
void BubbleSortLink(linklist *head);
linklist* LinklistSwap(linklist *phead, linklist *pNodeFirst, linklist *pNodeSecond);
linklist * FindLocalNode(linklist *phead, int local);
linklist *MergeLinklist(linklist *pHead, linklist *pHead1, linklist *pHead2);
#endif
