#define _CRT_SECURE_NO_WARNINGS

#include"seqlist.h"
#include<assert.h>
void slinit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void slcheckcapacity(SL* ps)//增容函数
{
	if (ps->capacity == ps->size)
	{
		//增容
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		sldtype* tmp = (sldtype*)realloc(ps->arr, newcapacity * sizeof(sldtype));//不直接使用ps防止扩容失败将其质空导致数据丢失
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}
void slpushback(SL* ps, sldtype x)
{
	//判断空间是否足够
	slcheckcapacity(ps);
	//当空间足够的时候
	ps->arr[ps->size++] = x;//插入数据

}
void slpushfrond(SL* ps, sldtype x)
{
	if (ps == NULL)
	{
		return;
	}
	slcheckcapacity(ps);
	//将数组的所有数据向后挪动一位
	for (int i = ps->size;i > 0;i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	++ps->size;


}
void slpopback(SL* ps)
{
	assert(ps&&ps->size);
	--ps->size;
}
void slprint(SL* ps)
{
	for (int i = 0;i < ps->size;i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}
void slpopfromt(SL* ps)
{
	assert(ps && ps->size);
	for (int i = 0;i < ps->size - 1;i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;
}
void slinsert(SL* ps, int pos, sldtype x)
{
	slcheckcapacity(ps);
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = ps->size;i > pos;i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
		ps->arr[pos] = x;
		++ps->size;

}
void slerase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
		for (int i = pos;i < ps->size - 1;i++)
		{
			ps->arr[i] = ps->arr[i + 1];
		}
		--ps->size;
}
int slfind(SL* ps, sldtype x)
{
	for (int i = 0;i < ps->size;i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void sldestroy(SL* ps)
{
	assert(ps);
	if (ps->arr)
		free(ps->arr);
	ps->arr = NULL;
	ps->capacity =ps->size = 0;
}