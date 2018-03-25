/********************************************************
*   Copyright (C) 2016 All rights reserved.
*   
*   Filename:main.c
*   Author  :tanw
*   Date    :2016-08-03
*   Describe:
*
********************************************************/
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "commom.h"

int main()
{
    data_t data=0;
    int i = 10;
    linklist *head = NULL;
    linklist *head2 = NULL;
    linklist *pHead = NULL;
    linklist *loophead = NULL;

    
#if 0
    /*create the linklist*/
    CreateLinkList(&head, 10);
    
    /*create the linklist*/
    CreateLinkListTwo(&head2, 10);


    /*reverse the linklist*/
    ReverseLinklistOne(&head);

    /*reverse the linklist*/
    ReverseLinklistOne(&head2);
    /*display the linklist data*/
    DisplayLinkList(head);

    /*display the linklist data*/
    DisplayLinkList(head2);

    /*create the head node*/
    pHead = (linklist *)malloc(sizeof(linklist));
    pHead->data = -1;
    pHead->next = NULL;

    /*merge the linklist*/
    MergeLinklist(pHead, head->next, head2->next);

    DisplayLinkList(pHead);
#endif

#if 1
    /*create the looplinklist*/
    linklist * pLoopRear = NULL;
    pLoopRear = CreateLoopLinkList(&loophead, 10);

    DisplayLinkList(loophead);
    linklist* pNode = FindLocalNode(loophead, 5);

    DeletePreNode(pNode);

    DisplayLinkList(loophead);      
#endif 

#if 0
    InsertLinkList(head, 0, 3);
    InsertLinkList(head, 0, 4);
    InsertLinkList(head, 0, 5);
    InsertLinkList(head, 0, 8);
    InsertLinkList(head, 0, 2);
    InsertLinkList(head, 0, 1);
    InsertLinkList(head, 0, 10);
#endif


#if 0
    linklist *pNodeFirst = FindLocalNode(head, 5);
    if (NULL == pNodeFirst)
    {
        printf("FindLocalNode is error\n");
        return -1;
    }
    printf("pNodeFirst->next = %p\n", pNodeFirst->next);
    
    linklist *pNodeSecond = FindLocalNode(head, 1);
    if (NULL == pNodeSecond)
    {
        printf("FindLocalNode is error\n");
        return -1;
    }
    printf("pNodeSecond = %p\n", pNodeSecond);

    head = LinklistSwap(head, pNodeFirst, pNodeSecond);
    if (NULL == head)
    {
        printf("LinklistSwap is error!\n");
        return -1;
    }
#endif
    //BubbleSortLink(head);
    //DisplayLinkList(head);

    //ReverseDisplayLinkList(head->next);
 
#if 0
    /*reverse the linklist*/
    ReverseLinklistOne(&head);

    /*display the linklist data*/
    DisplayLinkList(head);

    /*reverse the linklist*/
    ReverseLinklistTwo(&head);

    /*display the linklist data*/
    DisplayLinkList(head);  

    /*Obtain the value of the second elements 
    of the reciprocal(倒数) of a single chain table*/
    data_t val =0;
    val = GetLastLinklist(head, 2);
    printf("last val is = %d\n", val);

    /*insert element to the local of 0,it is one element*/
    InsertLinkList(head, 0, 10);
    InsertLinkList(head, 0, 9);
    InsertLinkList(head, 0, 7);
    InsertLinkList(head, 0, 6);
    InsertLinkList(head, 0, 5);
    InsertLinkList(head, 0, 4);
    InsertLinkList(head, 0, 3);
    /*display the linklist data*/
    DisplayLinkList(head);

    /*Get the middle elements of the single chain table*/
    val = GetMidLinklist(head);
    printf("middle val is = %d\n", val);

    /*get the middle elements of mode address */
    linklist * NodeAddress =  GetMidAddrLinklist(head);
    /*删除指定地址的节点*/
    DeleteNode(NodeAddress);
    /*display the linklist data*/
    DisplayLinkList(head);

    bool ret = false;
    ret = JudgeLoopLinklist(head);
    if (true == ret)
    {
        printf("linklist is loop\n");
    }
    else
    {
        printf("linklist is not loop\n");
    }
#endif    
    return 0;
}
