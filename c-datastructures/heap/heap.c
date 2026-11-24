#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"


void HPinit(HP* php)//堆初始化
{
	php->arr = NULL;
	php->size = php->capacity = 0;
}
void HPdestroy(HP* php)//销毁堆
{
	if (php->arr)
	{
		free(php->arr);
		php->arr = NULL;
		php->size = php->capacity = 0;
	}
}
void Swap(int* x, int* y)//交换函数
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void Adjustup(HPdatatype* arr,int child)//向上调整算法
{
	int parrent = (child - 1) / 2;
	while (child > 0)
	{
		//小堆<
	    //大堆>
		if (arr[child] < arr[parrent])
		{
			//调整
			
			Swap(&arr[child], &arr[parrent]);
			child = parrent;
			parrent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HPpush(HP* php,HPdatatype x)//向堆插入数据
{
	assert(php);
	//判断空间是否足够
	
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPdatatype* tmp = (HPdatatype*)realloc(php->arr,sizeof(HPdatatype)*newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	php->arr[php->size] = x;
	Adjustup(php->arr, php->size);
	php->size++;
	
}
void HPprint(HP* php)//打印函数
{
	for (int i = 0;i < php->size;i++)
	{
		printf("%d ",php->arr[i]);
	}
	printf("\n");
}
bool HPempty(HP* php)//判空
{
	assert(php);
	return php->size == 0;
}
void Adjustdown(HPdatatype* arr,int parent,int n)//向下调整算法
{
	int child = parent * 2 + 1;//左孩子
	while (child < n)
	{
		if (child+1<n && arr[child]>arr[child + 1])//小堆>
		{
			child++;
		}
		//
		if (arr[child] <arr[parent])//小堆<
		{
			//调整
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HPpop(HP* php)//出堆
{
	assert(!HPempty(php));
	//将最开始的父节点删掉
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	--php->size;
	//向下调整
	Adjustdown(php->arr, 0, php->size);

}
HPdatatype HPtop(HP* php)//取堆顶数据
{
	assert(!HPempty(php));
	return php->arr[0];
}
void HPsort1(int* arr, int n)//堆排序
{
	HP hp;
	HPinit(&hp);
	for (int i = 0;i < n;i++)
	{
		HPpush(&hp, arr[i]);
	}
	int i = 0;
	while (!HPempty(&hp))
	{
		int top = HPtop(&hp);
		arr[i++] = top;
		HPpop(&hp);
	}
	HPdestroy(&hp);
}
int HPsize(HP* php)//求堆的元素个数
{
	assert(php);
	return php->size;
}