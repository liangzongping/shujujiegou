#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define Max 30

typedef struct BitTree {
	int data;
	struct BitTree* lchild;
	struct BitTree* rchild;
}BitTree;
void bittreecreate(BitTree **p);//二级传参
//BitTree* bittreecreate();
void showbittree(BitTree* p);


//队列
typedef struct squeue {
	BitTree* data[Max];
	int front;
	int rear;
}squeue;
void squeueinit(squeue* p);
void squeuepush(squeue* p, BitTree* x);
int squeueEmpty(squeue* p);
int squeuemax(squeue* p);
void squeuepop(squeue* p,BitTree** n);

