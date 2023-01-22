#include"sqdoublestack.h"
void Dstackinit(Dstack* a)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		a->data[i] = 0;
	}
	a->top1 = 0;
	a->top2 = MAX-1;
}
void Dstackpush(Dstack* a,int x,int stacknum)
{
	if (a->top1-1== a->top2)
		return;
	if (stacknum == 1)
	{
		a->data[a->top1++] = x;
	}
	if (stacknum == 2)
	{
		a->data[a->top2--] = x;
	}
}
int Dstackpop(Dstack* a, int stacknum)
{
	if (stacknum == 1)
	{
		assert(a->top1>0);
		return a->data [--a->top1];
		
	}
	if (stacknum == 2)
	{
		assert(a->top2 < MAX - 1);
		return a->data[++a->top2];
	}
}