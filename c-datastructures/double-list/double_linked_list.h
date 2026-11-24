#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//双向链表结构
typedef int ltdatatype;
struct Listnode {
	ltdatatype  data;
	struct Listnode* next;
	struct Listnode* prev;
};
typedef struct Listnode LTNode;
LTNode* ltinit();//双向链表的初始化
void ltpushback(LTNode* plist, ltdatatype x);//尾插
void ltprint(LTNode* phead);//打印链表
void ltpushfrond(LTNode* phead, ltdatatype x);//头插
void ltpopback(LTNode* phead);//尾删
void ltpopfront(LTNode* phead);//头删
LTNode* ltfind(LTNode* phead, ltdatatype x);//查找函数
void ltinsert(LTNode* pos, ltdatatype x);//在指定位置后插入数据
void lterase(LTNode* pos);//删除指定位置的数据
void ltdestroy(LTNode* phead);//销毁链表


