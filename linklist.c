/********************************************************
*   Copyright (C) 2020 All rights reserved.
*   
*   Filename:linklist.c
*   Author  :yhd
*   Date    :2020-09-16
*   Describe:
*
********************************************************/
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "commom.h"
#include <assert.h>

#define LOOP 1

linklist * recurrence(linklist * head);
linklist* FindPrelink(linklist *phead, linklist *pNode);



void CreateLinkList(linklist **head, int n)
{
    assert(NULL != head);
    linklist * p = NULL;
    

    /*create the head node*/
	*head = (linklist *)malloc(sizeof(linklist));
	if (NULL == *head) 
	{
		perror("malloc");
		return ;
	}
	/*init the head node*/
	memset(*head, 0, sizeof(linklist));
	(*head)->data = -1;
	(*head)->next = NULL;

	for (int i = 0; i < n; i++)
	{
        p = (linklist *)malloc(sizeof(linklist));
		if (NULL == p) 
	 	{
			perror("malloc");
			return ;
		}
		memset(p, 0, sizeof(linklist));
		p->data = i;
		p->next = (*head)->next;
		(*head)->next = p;	
	}

	return ;
}

void CreateLinkListTwo(linklist **head, int n)
{
    assert(NULL != head);
    linklist * p = NULL;
    

    /*create the head node*/
	*head = (linklist *)malloc(sizeof(linklist));
	if (NULL == *head) 
	{
		perror("malloc");
		return ;
	}
	/*init the head node*/
	memset(*head, 0, sizeof(linklist));
	(*head)->data = -1;
	(*head)->next = NULL;

	for (int i = 0; i < n; i++)
	{
        p = (linklist *)malloc(sizeof(linklist));
		if (NULL == p) 
	 	{
			perror("malloc");
			return ;
		}
		memset(p, 0, sizeof(linklist));
		p->data = i + 20;
		p->next = (*head)->next;
		(*head)->next = p;	
	}

	return ;
}

/*create the single linklist ,and return the rear pointer*/
linklist* CreateLoopLinkList(linklist **loophead, int n)
{
    assert(NULL != loophead);
    linklist * p = NULL;
	linklist * r = NULL;
	linklist * rear = NULL;
    
    /*create the head node*/
	*loophead = (linklist *)malloc(sizeof(linklist));
	if (NULL == *loophead) 
	{
		perror("malloc");
		return NULL;
	}
	/*init the head node*/
	memset(*loophead, 0, sizeof(linklist));
	(*loophead)->data = -1;
	(*loophead)->next = NULL;
	r = *loophead;

	printf("loophead addr is %p\n", *loophead);

	for (int i = 0; i < n; i++)
	{
        p = (linklist *)malloc(sizeof(linklist));
		if (NULL == p) 
	 	{
			perror("malloc");
			return NULL;
		}
		memset(p, 0, sizeof(linklist));
		p->data = i;
		r->next = p;
		r = p;
	}
	
    r->next = (*loophead);
	rear = r;

	
	return rear;
}

void ClearLinkList(linklist *head)
{
	linklist *p = head->next;
	linklist *q = NULL;

	head->next = NULL;
	while(p != NULL) {
		q = p;
		p = p->next;
		free(q);
		q = NULL;
	}

	return ;
}

int EmptyLinkList(linklist *head)
{
	return (head->next == NULL ? 0 : -1);
}

int FullLinkList(linklist *head)
{
	return -1;
}

int LengthLinkList(linklist *head)
{
	int len = 0;
	linklist *p = head->next;
#if LOOP
    while(head != p) {
		p = p->next;
		len++;
	} 
#else
    while(NULL != p->next) {
		p = p->next;
		len++;
	}
#endif

	return len;
}

int InsertLinkList(linklist *head, int local, data_t data)
{
	int i = 0;
	linklist *p = head;
	linklist *q = NULL;
	//1.判断local是否满足条件；
	if (local < 0 || local > LengthLinkList(head))	{
		printf("local is error !\n");
		return -1;
	}
	//2.创建一个新的结点，并存入数据；
	q = (linklist *)malloc(sizeof(linklist));
	if (NULL == q) {
		perror("InsertLinklist->malloc");
		return -1;
	}
	memset(q, 0, sizeof(linklist));
	q->data = data;
	q->next = NULL;

	//3.找位置，找要插入结点的前一个位置；
	for (i = 0; i < local; i++ ) {
		p = p->next;
	}

	//4.插入节点（先连后断）；
	q->next = p->next;
	p->next = q;

	return 0;
}
int DeleteDataLinkList(linklist *head, data_t data)
{
	int flag = 0;
	linklist *p = head;
	linklist *q = NULL;
	//1.判断链表是否为空；
	if (!EmptyLinkList(head)) {
		printf("linklist is empty !\n");
		return -1;
	}

	//2.遍历整个链表，找到要删除数据结点的前一个结点
	while(NULL != p->next) {
		//3.删除结点；
		if (p->next->data == data) {
			q = p->next;
			flag++;	
			p->next = q->next;
			free(q);
			q = NULL;
		}
		p = p->next;
	}
	
	return 0;
}
int DeleteLocalLinkList(linklist *head, int local)
{
	int i = 0;
	linklist *p = head;
	linklist *q = NULL;
	//1.判断链表是否为空， local
	if (!EmptyLinkList(head)) {
		printf("linklist is empty !\n");
		return -1;
	}

	if (local < 0 || local >= LengthLinkList(head)) {
		printf("local is error !\n");
		return -1;
	}
	//2.找位置，找到local前一个结点；
	for (i = 0; i < local; i++) {
		p = p->next;
	}
	//3.删除结点
	q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;

	return 0;
}
int GetLinkList(linklist *head, int local, data_t *data)
{
	int i = 0;
	linklist *p = head;
	//1.判断链表是否为空，local；
	if (!EmptyLinkList(head)) {
		printf("linklist is empty !\n");
		return -1;
	}

	if (local < 0 || local >= LengthLinkList(head)) {
		printf("local is error !\n");
		return -1;
	}
	
	//2.找位置，找到local所在结点；
	for (i = 0; i <= local; i++) {
		p = p->next;
	}
	//3.返回数据；
	*data = p->data;
}
int LocalLinkList(linklist *head, data_t data)
{
	int local = 0;
	linklist *p = head->next;
	//1.判断链表是否为空，
	if (!EmptyLinkList(head)) {
		printf("linklist is empty !\n");
		return -1;
	}
	//2.找位置，找data所在的位置；
	while(NULL != p) {
		if (p->data == data) {
			return local;
		}
		p = p->next;
		local ++;
	}

	return -1;

	//3.返回位置；（）
}
void DestoryLinkList(linklist **head)
{
#if 0
	//释放所有空间；
	linklist *p = *head;
	linklist *q = NULL;

	while(NULL != p)  {
		q = p;
		p = p->next;
		free(q);
		q = NULL;
	}

#else
	ClearLinkList(*head);
	free(*head);
	*head = NULL;

#endif

}

/*Reverse print the linklist data but not include head node*/
void ReverseDisplayLinkList(linklist *head)
{
	if (NULL != head) 
	{
	    printf("%d ", head->data);
		ReverseDisplayLinkList(head->next);
	}
	else
	{
        return ;
	}
	printf("\n");
}

/*sequence print the linklist data but not include head node*/
void DisplayLinkList(linklist *head)
{
	linklist *p = head->next;
#if LOOP
    while(p != head) {
		printf("%d ", p->data);
		p = p->next;
	}
#else
	while(NULL != p) {
		printf("%d ", p->data);
		p = p->next;
	}
#endif
	printf("\n");
}

int ChangeDataLinkList(linklist *head, data_t olddata, data_t newdata)
{
	int flag = -1;
	linklist *p = head->next;
	//1.判断链表是否为空
	if (!EmptyLinkList(head)) {
		printf("linklist is empty !\n");
		return -1;
	}
	//2.找元素所在结点位置；
	while(NULL != p) {
		if (olddata == p->data) {
			p->data = newdata;
			flag ++;
		}

		p = p->next;
	}
	//3.修改值；

	return flag;
}
int ChangeLocalLinkList(linklist *head, int local, data_t data)
{
	int i = 0;
	linklist *p = head->next; 
	//1.判断链表是否为空；
	if (!EmptyLinkList(head)) {
		printf("linklist is empty !\n");
		return -1;
	}

	if (local < 0 || local >= LengthLinkList(head)) {
		printf("lcoal is error !\n");
		return -1;
	}
	//2.找local所对应结点；
	for (i = 0; i < local; i++ ) {
		p = p->next;
	}
	//3.修改值
	p->data = data;

	return 0;
}

/*Find the node local*/
linklist * FindLocalNode(linklist *phead, int local)
{
    assert(NULL != phead);

	linklist * pTempNode = phead;

	if (!EmptyLinkList(phead)) 
	{
		printf("linklist is empty !\n");
		return NULL;
	}

	if (local <= 0 || local > LengthLinkList(phead)) 
	{
		printf("lcoal is error !\n");
		return NULL;
	}

	for (int i = 0; i < local; i++)
	{
        pTempNode = pTempNode->next;    
	}

	return pTempNode;
}


/*reverse the linklist, iteration(迭代法)*/
void ReverseLinklistOne(linklist **head)
{
	assert(head != NULL);
    linklist * prev = NULL;
	linklist * p = (*head)->next;
	linklist * latter = p->next;

	while (p != NULL)
	{
        p->next = prev;
		prev = p;
		p = latter;
		/*if the p == NULL,not neccessary to change the latter*/
		if (NULL != p) 
		{
            latter = p->next;
		}     
	}

	(*head)->next = prev; 
}

/*reverse the linklist,recurrence(递归)*/
void ReverseLinklistTwo(linklist **head)
{
     assert(head != NULL);
	 
     (*head)->next = recurrence((*head)->next);
}

/*recurrence*/
linklist * recurrence(linklist * head)
{
    linklist * pNewHead = NULL;

    if (NULL == head || NULL == head->next)
    {
        return head;
	}
	pNewHead = recurrence(head->next);
	head->next->next = head;
	head->next =NULL;
	
    return pNewHead;	
}

/*get last n element(获得倒数第几个元素)*/
int GetLastLinklist(linklist *head, int last)
{
    assert(NULL != head);
    linklist *first = head;
	linklist *back = head;

	for (int i =0; i < last; i++)
	{
        first = first->next;
	}

	while (NULL != first)
	{
        first = first->next;
		back = back->next;
	}

	return back->data;
}

/*get the middle elements of the single chain table*/
int GetMidLinklist(linklist *head)
{
    assert(NULL != head);
    linklist *first = head;
	linklist *back = head;

	while ((NULL != first) && (NULL != first->next))
	{
        first = first->next->next;
		back = back->next;
	}

	return back->data;
}

/*get the middle elements of the single chain table
(返回中间元素结点的地址)*/
linklist * GetMidAddrLinklist(linklist *head)
{
    assert(NULL != head);
    linklist *first = head;
	linklist *back = head;

	while ((NULL != first) && (NULL != first->next))
	{
        first = first->next->next;
		back = back->next;
	}

	return back;
}


/*delete the element of designer node,
我们只给出了当前结点的地址，不知道它的前一个节点*/
void DeleteNode(linklist * node)
{
    assert(NULL != node);
    linklist *CurNode = node;
	linklist *DelNode = node->next;

	CurNode->data = DelNode->data;
	CurNode->next = DelNode->next;

	free(DelNode);
}

/*delete the node of pre pNode in the single circular*/
void DeletePreNode(linklist * pNode)
{
    assert(NULL != pNode);

	linklist * pNodeTemp = pNode;
	linklist * pDelNode = NULL;

	while (pNode != pNodeTemp->next->next)
	{
        pNodeTemp = pNodeTemp->next;
	}

	pDelNode = pNodeTemp->next;
	pNodeTemp->next = pNode;
	free(pDelNode);
}

bool JudgeLoopLinklist(linklist *head)
{
    assert(NULL != head);
    linklist *first = head;
	linklist *back = head;

	while (first != NULL && first->next != NULL)
	{
        first = first->next->next; 
		back = back->next;

		if (first == back)
		{
            return true;
		}
	}

	return false;
}

/*linklist sort of Bubble*/
void BubbleSortLink(linklist *head)
{
    assert(NULL != head);

	linklist * cur = head->next;
	linklist * tail = NULL;
	data_t temp = 0;
	bool flag = true;           //避免重复排序，比如1、2、3、4、5只需要内循环一次，其实就没有必要在比较了，毕竟已经升序了
	int count = 0;

	while (tail != head->next && flag)
	{
	    count++;
	    flag = false;
        while (cur->next != tail)
        {
            if (cur->data > cur->next->data)
            {
                temp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = temp;
				flag = true;
			}
			cur = cur->next;
			count++;
		}
		tail = cur;
		cur = head->next;
	}

	printf("count is %d\n", count);
}

/*find the node of the pre,and return address*/
linklist* FindPrelink(linklist *phead, linklist *pNode)
{
    assert(NULL != phead && NULL != pNode);
    linklist *pTempNode = phead;

	while (NULL != pTempNode)
	{
        if (pTempNode->next == pNode)
        {
            return pTempNode;         
		}

		pTempNode = pTempNode->next;
	}

	return NULL;
}

/*swap the nodem,parameter is any address of the two node*/
linklist* LinklistSwap(linklist *phead, linklist *pNodeFirst, linklist *pNodeSecond)
{
    assert(NULL != phead && NULL != pNodeFirst && NULL != pNodeSecond);
    linklist * pNodeFirstFre = NULL;
	linklist * pNodeSecondFre = NULL;
	linklist * pNodeAfterFirst = NULL;

    /*the same as node not swap*/
	if (pNodeFirst->data == pNodeSecond->data)
	{
        return NULL;
	}
    else if (pNodeFirst->next == pNodeSecond && pNodeFirst != phead)/*the node is the Neighbor*/
	{
        pNodeFirstFre = FindPrelink(phead, pNodeFirst);
        pNodeFirst->next = pNodeSecond->next;
		pNodeSecond->next = pNodeFirst;
		pNodeFirstFre->next = pNodeSecond;
	}
	else if (pNodeSecond->next == pNodeFirst && pNodeSecond != phead)/*the node is the Neighbor*/
	{
        pNodeSecondFre = FindPrelink(phead, pNodeSecond);
        pNodeSecond->next = pNodeFirst->next;
		pNodeFirst->next = pNodeSecond;
		pNodeSecondFre->next = pNodeFirst;   
	}
	else/*the node is not the Neighbor*/
	{
        pNodeFirstFre = FindPrelink(phead, pNodeFirst);
		pNodeSecondFre = FindPrelink(phead, pNodeSecond);
		pNodeAfterFirst = pNodeFirst->next;
        pNodeFirst->next = pNodeSecond->next;
		pNodeSecond->next = pNodeAfterFirst;
		pNodeFirstFre->next = pNodeSecond;
		pNodeSecondFre->next = pNodeFirst;
	}

	return phead;
}

/*merge the no head linklist pHead1 and pHead2 to the pHead,
但是这两个无头链表是升序排列的,没有重复*/
linklist* MergeLinklist(linklist *pHead, linklist *pHead1, linklist *pHead2)
{
    assert(NULL != pHead && NULL != pHead1 && NULL != pHead2);

    linklist *pHeadTemp = pHead;

    while (NULL != pHead1 && NULL != pHead2)
	{
        if (pHead1->data < pHead2->data)
        {
            pHeadTemp->next = pHead1;
			pHeadTemp = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
            pHeadTemp->next = pHead2;
			pHeadTemp = pHead2;
			pHead2 = pHead2->next;
		}
	}



	if (NULL != pHead1)
	{
        pHeadTemp->next = pHead1;
	}

	if (NULL != pHead2)
	{
        pHeadTemp->next = pHead2;
	}
	
    return pHead;	
}


