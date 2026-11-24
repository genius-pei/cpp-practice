#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
void QUinit(QU* pq)//初始化
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	//pq->size = 0;
}
bool QUempty(QU* pq)//队列判空
{
	assert(pq);
	return pq->phead == NULL;
}
void QUpushi(QU* pq, QDdatatype x)//入队--队尾
{
	assert(pq);
	//队列为空
	QUnode* newnode = (QUnode*)malloc(sizeof(QUnode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;
	}
	//pq->size++;
}
	void QUpop(QU * pq)//出队--队头
	{
		assert(!QUempty(pq));
		//只有一个节点
		if (pq->phead == pq->ptail)
		{
			free(pq->phead);
			pq->phead = pq->ptail = NULL;
		}
		else
		{
			QUnode* next = pq->phead->next;
			free(pq->phead);
			pq->phead = next;
		}
		/*pq->size--;*/
	}
	QDdatatype QUfront(QU* pq)//取头数据
	{
		assert(!QUempty(pq));
	    return pq->phead->data;
	}
	QDdatatype QUback(QU* pq)//取尾数据
	{
		assert(!QUempty(pq));
		return pq->ptail->data;
	}
	void QUdestroy(QU* pq)//销毁队列
	{
		assert(pq);
		QUnode* pcur = pq->phead;
		while (pcur)
		{
			QUnode* next = pcur->next;
			free(pcur);
			pcur = next;
		}
		pq->phead = pq->ptail = NULL;
		/*pq->size = 0;*/
	}
	int QUsize(QU* pq)//队列的有效元素
	{
		/*assert(pq);
		QUnode* pcur = pq->phead;
		int size = 0;
		while (pcur)
		{
			size++;
			pcur = pcur->next;
		}*/
		/*return pq->size;*/
	}

	

