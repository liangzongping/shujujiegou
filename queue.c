#include"queue.h"
void queueinit(queuep* a)
{
	assert(a);
	a->head = NULL;
	a->tail = NULL;
}
void queuedestroy(queuep* a)
{
	assert(a);
	queuenode* cur = a->head;
	while (cur)
	{
		queuenode* next=cur ->next ;
		free(cur);
		cur = next;
	}
	a->head =a->tail = NULL;
}
void queuepush(queuep* a, int x)
{
	assert(a);
	queuenode *newnode = (queuenode*)malloc(sizeof(queuenode));
	newnode->data = x;
	newnode->next = NULL;
	if (a->head == NULL)
	{
		a->head = a->tail =newnode;
	}
	else
	{
		a->tail->next = newnode;
		a->tail = newnode;
	}
}
void queuepop(queuep* a)
{
	assert(a);	
	if (a->head == NULL)
		return;
	queuenode* next = a->head->next;
	free(a->head);
	a->head = next;
	if (a->head == NULL)
		a->tail = NULL;
}
int queuefront(queuep* a)
{
	assert(a);
	assert(a->head);
	return a->head->data;
}
int queueback(queuep* a)
{
	assert(a);
	assert(a->tail);
	return a->tail->data;
}
int sizequeue(queuep* a)
{
	assert(a);
	queuenode* cur = a->head;
	int n = 0;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}
int queueEmpty(queuep* a)
{
	assert(a);
	return a->head == NULL;
}