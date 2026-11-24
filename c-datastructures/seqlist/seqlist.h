#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int  sldtype;
struct seqlist
{
	sldtype* arr;
	int size;//有效数据个数
	int capacity;//空间容量

};
typedef struct seqlist SL;
void slinit(SL*);//顺序表的初始化
void slpushback(SL* ps, sldtype x);//尾插
void slpushfrond(SL* ps, sldtype x);//头插
void slcheckcapacity(SL* ps);//增容函数
void slprint(SL* ps);//打印顺序表
void slpopback(SL* ps);//尾删

void slpopfromt(SL* ps);//头删
void slinsert(SL* ps ,int pos, sldtype x);//在指定位置(下标)前插入数据
void slerase(SL* ps, int pos);//删除指定位置的数据
int slfind(SL* ps, sldtype x);//查找指定数据
void sldestroy(SL* ps);//销毁顺序表
