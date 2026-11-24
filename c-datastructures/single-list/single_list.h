#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义链表结构
typedef int sldatatype;
struct slistnode
{
	sldatatype data;//储存的数据
	struct slistnode* next;//指向下一个节点
};
typedef struct slistnode SLTNODE;
void sltprint(SLTNODE* phead);//打印链表
void sltpushback(SLTNODE** pphead, sldatatype x);//尾插
SLTNODE* sltbuynode(sldatatype x);//创建新的节点
void sltpushfrond(SLTNODE** pphead, sldatatype x);//头插
void sltpopback(SLTNODE** pphead);//尾删
void sltpopfront(SLTNODE** pphead);//头删
SLTNODE* sltfind(SLTNODE* phead, sldatatype x);//查找
void sltinsert(SLTNODE** pphead, SLTNODE* pos, sldatatype x);//在指定数据前插入数据
void sltinsertafter( SLTNODE* pos, sldatatype x);//在指定数据后插入数据
void slterase(SLTNODE** pphead, SLTNODE* pos);//删除pos节点
void slteraseafter(SLTNODE* pos);//删除pos的下一个节点
void slistdestory(SLTNODE** pphead);//销毁链表
