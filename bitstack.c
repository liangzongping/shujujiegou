#include"bittree1.h"
void stackinit(ST* st)
{
	assert(st);
	st->a = (BitTree** )malloc(4 * sizeof(BitTree *));
	st->top = 0;
	st->capacity = 4;
}
void stackpush(ST* st, BitTree* x)
{
	assert(st);
	if (st->top == st->capacity)
	{
		int newcapacity = st->capacity * 2;
		BitTree** t = (BitTree** )realloc(st->a, newcapacity * sizeof(BitTree*));
		if (t == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		st->a = t;
		st->capacity = newcapacity;
	}
	st->a[st->top] = x;
	st->top++;
}
void stackpop(ST* st)
{
	assert(st);
	if (st->top > 0)
		st->top--;
}
BitTree* stacktop(ST* st)
{
	assert(st);
	if (st->top > 0)
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