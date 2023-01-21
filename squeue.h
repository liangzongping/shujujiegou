#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define Max 5
typedef struct squeue {
	int data[Max];
	int front;
	int rear;
}squeue;
void squeueinit(squeue* p);
void squeuepush(squeue* p,int x);
int squeueEmpty(squeue* p);
int squeuemax(squeue* p);
void squeuepop(squeue* p);