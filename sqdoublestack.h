#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 10
typedef struct doublestack {
	int data[MAX];
	int top1;//ջ��1
	int top2;//ջ��2
}Dstack;
void Dstackinit(Dstack* a);
void Dstackpush(Dstack* a,int x,int stacknum);
int Dstackpop(Dstack* a, int stacknum);