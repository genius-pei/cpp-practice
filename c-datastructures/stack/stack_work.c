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

    int size;//有效数据的个数

}QU;



void QUinit(QU* pq)//初始化

{

    assert(pq);

    pq->phead = pq->ptail = NULL;

    pq->size = 0;

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

    pq->size++;

}

void QUpop(QU* pq)//出队--队头

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

    pq->size--;

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

    pq->size = 0;

}

int QUsize(QU* pq)//队列的有效元素

{

    assert(pq);

    // QUnode* pcur = pq->phead;

    // int size = 0;

    // while (pcur)

    // {

    //  size++;

    //  pcur = pcur->next;

    // }

    return pq->size;

}







//以上是队列-----------------------

typedef struct {

    QU q1;

    QU q2;



} MyStack;





MyStack* myStackCreate()//初始化

{

    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));

    QUinit(&pst->q1);

    QUinit(&pst->q2);

    return pst;



}



void myStackPush(MyStack* obj, int x)

{

    if (!QUempty(&obj->q1))//往非空队列插入数据

    {

        QUpushi(&obj->q1, x);



    }

    else

    {

        QUpushi(&obj->q2, x);

    }



}



int myStackPop(MyStack* obj)

{

    QU* emp = &obj->q1;

    QU* noneempty = &obj->q2;

    if (QUempty(&obj->q2))

    {

        emp = &obj->q2;

        noneempty = &obj->q1;

    }

    while (QUsize(noneempty) > 1)//将非空队列的数据导入空队列

    {

        QUpushi(emp, QUfront(noneempty));

        QUpop(noneempty);

    }

    int top = QUfront(noneempty);//取队头

    QUpop(noneempty);

    return top;

}



int myStackTop(MyStack* obj)

{

    //取不为空栈的栈顶

    if (!QUempty(&obj->q1))

    {

        return QUback(&obj->q1);

    }

    else

    {

        return QUback(&obj->q2);

    }

}



bool myStackEmpty(MyStack* obj)

{

    return QUempty(&obj->q1) && QUempty(&obj->q2);

}



void myStackFree(MyStack* obj)

{

    QUdestroy(&obj->q1);

    QUdestroy(&obj->q2);

    free(obj);

    obj = NULL;

}



