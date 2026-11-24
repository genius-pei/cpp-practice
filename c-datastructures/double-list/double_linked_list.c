#define _CRT_SECURE_NO_WARNINGS
#include"double_linked_list.h"
//创建新节点
LTNode* ltbuynode(ltdatatype x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = newnode->prev = newnode;
}
//双向链表的初始化
LTNode* ltinit()
{
	 LTNode* phead = ltbuynode(-1);
	return phead;
}
//尾插
//头结点需要发生改变，传二级
//头节点不需要发生改变，传一级
void ltpushback(LTNode* phead, ltdatatype x)
{
	assert(phead);
	LTNode* newnode = ltbuynode(x);
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;
}
//打印链表
void ltprint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}
//头插
void ltpushfrond(LTNode* phead, ltdatatype x)
{
	assert(phead);
	LTNode* newnode = ltbuynode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}
//只有一个节点的情况下，链表为空
bool ltempty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}
//尾删
void ltpopback(LTNode* phead)
{
	assert(!ltempty(phead));//确保不为空链表
	LTNode* del = phead->prev;
	/*phead->prev = del->prev;*/
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
	del = NULL;
}
//头删
void ltpopfront(LTNode* phead)
{
	assert(!ltempty(phead));//确保不为空链表
	LTNode* del = phead->next;
	del->next->prev = phead;
	phead->next = del->next;
	free(del);
	del = NULL;
}
//查找函数
LTNode* ltfind(LTNode* phead, ltdatatype x)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;

}
//在指定位置后插入数据
void ltinsert(LTNode* pos,ltdatatype x)
{
	LTNode* newnode = ltbuynode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;

}
void lterase(LTNode* pos)//删除指定位置的数据
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}
void ltdestroy(LTNode* phead)//销毁链表
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
	
}
