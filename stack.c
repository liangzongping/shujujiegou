#include"stack.h"
void stackinit(ST* st)
{
	assert(st);
	st->a = (int*)malloc(4 * sizeof(int));
	st->top = 0;
	st->capacity = 4;
}
void stackpush(ST* st,int x)
{
	assert(st);
	if (st->top == st->capacity)
	{
		int newcapacity =st->capacity * 2;
		int* t = (int*)realloc(st->a, newcapacity *sizeof(int));
		if (t == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		st->a = t;
		st->capacity = newcapacity;
	}
	st->a[st->top]=x;
	st->top++;
}
void stackpop(ST* st)
{
	assert(st);
	if (st->top > 0)
	st->top--;
}
int stacktop(ST* st)
{
	assert(st);
	if(st->top >0)
	return st->a[st->top - 1];
}
int sizestack(ST* st)
{
	assert(st);
	return (st->top);
}
int stackempty(ST* st)
{
	if (st->top == 0)
		return 1;
	else
		return 0;
}
void stackdestroy(ST* st)
{
	assert(st);

	free(st->a);
	st->a = NULL;
	st->capacity = 0;
}