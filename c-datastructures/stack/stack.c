#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"

void stackinit(ST* ps)//栈初始化
{
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}
void stackpush(ST* ps, stdatatype x)//入栈
{
	if (ps->top == ps->capacity)
	{
		//增容
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		stdatatype* tmp = (stdatatype*)realloc(ps->arr, newcapacity*sizeof(stdatatype));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	ps->arr[ps->top++] = x;
}
bool stackempty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
void stackpop(ST* ps)//出栈
{
	assert(!stackempty(ps));//判空
	--ps->top;
}
stdatatype stacktop(ST* ps)//取栈顶元素
{
	assert(!stackempty(ps));
	return ps->arr[ps->top - 1];
}
void stackdestroy(ST* ps)//销毁栈
{
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->top = ps->capacity = 0;
	}
}	  