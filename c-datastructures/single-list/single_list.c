#define _CRT_SECURE_NO_WARNINGS
#include"single_list.h"
    
void sltprint(SLTNODE* phead)
{
    SLTNODE* pcur = phead;
    while (pcur)
    {
        printf("%d -> ", pcur->data);
        pcur = pcur->next;
    }
    printf("NULL\n");
}
SLTNODE* sltbuynode(sldatatype x)
{
    //创建新的节点
    SLTNODE* newnode = (SLTNODE*)malloc(sizeof(SLTNODE));
    if (newnode == NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void sltpushback(SLTNODE** pphead, sldatatype x)
{
    SLTNODE* newnode= sltbuynode(x);
    if (*pphead == NULL)//链表为空
    {
       *pphead = newnode;
    }
    else
    {
        SLTNODE* ptail = *pphead;
        while (ptail->next)
        {
            ptail = ptail->next;
        }
        ptail->next = newnode;
    }
   
}
void sltpushfrond(SLTNODE** pphead, sldatatype x)
{
    assert(*pphead);
    SLTNODE* newnode = sltbuynode(x);
    newnode->next = *pphead;
    *pphead = newnode;//让指向第一个节点的位置变化
}
void sltpopback(SLTNODE** pphead)
{
    assert(pphead && *pphead);
    //只有一个节点
    if ((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;

    }
    else 
    {
        SLTNODE* prev = NULL;
        SLTNODE* ptail = *pphead;
        while (ptail->next)
        {
            prev = ptail;
            ptail = ptail->next;
        }
        prev->next = NULL;
        free(ptail);
        ptail = NULL;
    }
}
void sltpopfront(SLTNODE** pphead)
{
    assert(pphead && *pphead);
    SLTNODE* next = (*pphead)->next;
    free(*pphead);
    *pphead=next;
}
SLTNODE* sltfind(SLTNODE* phead, sldatatype x)
{
    SLTNODE* pcur = phead;
    while (pcur)
    {
        if (pcur->data == x)
        {
            return pcur;
        }
        pcur = pcur->next;
    }
    return NULL;
}
void sltinsert(SLTNODE** pphead, SLTNODE* pos, sldatatype x)
{
    assert(pphead && pos);
    //指向第一个节点时
    if (pos == *pphead)
    {
        sltpushfrond(*pphead,x);
    }
    SLTNODE* newnode = sltbuynode(x);
    SLTNODE* prev = *pphead;
    while (prev->next != pos)
    {
        prev = prev->next;
    }
    prev->next = newnode;
    newnode->next = pos;
}
void sltinsertafter(SLTNODE* pos, sldatatype x)
{
    assert(pos);
    SLTNODE* newnode = sltbuynode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}
void slterase(SLTNODE** pphead, SLTNODE* pos)
{
    assert(pphead && pos);
    //pos头结点
    if (pos == *pphead)
    {
        sltpopfront(*pphead);
    }
    else 
    {
        SLTNODE* prev = *pphead;
        while (prev->next != pos)
        {
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
        pos = NULL;
    }
}
void slteraseafter(SLTNODE* pos)
{
    assert(pos&&pos->next);
    
    SLTNODE* del = pos->next;
    pos->next = del->next;
    free(del);
    del = NULL;
}
void slistdestory(SLTNODE** pphead)
{
    SLTNODE* pcur = *pphead;
    while (pcur)
    {
        SLTNODE* next = pcur->next;
        free(pcur);
        pcur = next;
    }
    *pphead = NULL;
}


