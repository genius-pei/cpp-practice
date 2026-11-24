#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
typedef int QDdatatype;
//节点结构
typedef struct QueueNode
{
	QDdatatype data;
	struct QueueNode* next;
}QUnode;
//队列结构
typedef struct Queue
{
	struct QueueNode* phead;
	struct QueueNode* ptail;
	//int size;//有效数据的个数
}QU;
void QUinit(QU* pq);//初始化
void QUpushi(QU* pq, QDdatatype x);//入队--队尾
void QUpop(QU* pq);//出队--队头
bool QUempty(QU* pq);//队列判空
QDdatatype QUfront(QU* pq);//取头数据
QDdatatype QUback(QU* pq);//取尾数据
void QUdestroy(QU* pq);//销毁队列
int QUsize(QU* pq);//队列的有效元素