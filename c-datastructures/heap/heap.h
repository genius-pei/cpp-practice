#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

//堆的结构
typedef int HPdatatype;
typedef struct heap
{
	HPdatatype* arr;
	int size;//有效数据个数
	int capacity;//空间大小

}HP;

void HPinit(HP* php);//堆初始化
void HPdestroy(HP* php);//销毁堆
void HPpush(HP* php,HPdatatype x);//向堆插入数据
void Adjustup(HPdatatype* arr, int child);//向上调整算法
void Adjustdown(HPdatatype* arr,int parent,int n);//向下调整算法
void Swap(int* x, int* y);//交换函数
void HPprint(HP* php);//打印函数
void HPpop(HP* php);//出堆
bool HPempty(HP* php);//判空
HPdatatype HPtop(HP* php);//取堆顶数据
void HPsort1(int* arr, int n);//堆排序--数据结构
void HPsort2(int* arr, int n);//堆排序
int HPsize(HP* php);//求堆的元素个数