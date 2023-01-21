#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct queuenode {
	int data;
	struct queuenode* next;
}queuenode;
typedef struct queuep {
	queuenode* head;
	queuenode* tail;
}queuep;
void queueinit(queuep* a);
void queuedestroy(queuep* a);
void queuepush(queuep* a, int x);
void queuepop(queuep* a);
int queuefront(queuep* a);
int queueback(queuep* a);
int sizequeue(queuep* a);
int queueEmpty(queuep* a);