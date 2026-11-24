#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//定义栈的结构
typedef int stdatatype;
struct Stack
{
	stdatatype* arr;
	int top;//指向栈顶
	int capacity;//栈的容量
};
typedef struct Stack ST;

void stackinit(ST* ps);//栈初始化
void stackpush(ST* ps, stdatatype x);//入栈
void stackpop(ST* ps);//出栈
bool stackempty(ST* ps);//判空
stdatatype stacktop(ST* ps);//取栈顶元素
void stackdestroy(ST* ps);//销毁栈