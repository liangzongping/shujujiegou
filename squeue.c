#include"squeue.h"
void squeueinit(squeue* p)
{
	p->front  = 0;
	p->rear = 0;
}
void squeuepush(squeue* p,int x)
{
	assert(p);
	if ((p->rear + 1) % Max == p->front)
	{
		printf("已满，添加失败\n");
		return;
	}
	p->data[p->rear] = x;
	p->rear = (p->rear + 1) % Max;//形成循环的原因
}
int squeuemax(squeue* p)
{
	assert(p);
	return (p->rear + 1) % Max == p->front;
}
int squeueEmpty(squeue* p)
{
	assert(p);
	return p->front == p->rear;
}
void squeuepop(squeue* p)
{
	assert(p);
	if (squeueEmpty(p))
	{
		return;
	}
	else
	{
		p->front = (p->front + 1) % Max;
	}
}