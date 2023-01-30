#include"BitTree.h"
void squeueinit(squeue* p)
{
	p->front = 0;
	p->rear = 0;
}
void squeuepush(squeue* p, BitTree* x)
{
	assert(p);
	if ((p->rear + 1) % Max == p->front)
	{
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
void squeuepop(squeue* p,BitTree** n)
{
	assert(p);
	if (squeueEmpty(p))
	{
		return;
	}
	else
	{
		*n = p->data[p->front];
		p->front = (p->front + 1) % Max;
	}
}