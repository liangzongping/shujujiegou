#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct BitTree {
	int data;
	struct BitTree* lchild;
	struct BitTree* rchild;
}BitTree;
void bittreecreate(BitTree** p);//二级传参
void showbittree(BitTree* p);
//栈
typedef struct ST {
	BitTree** a;
	int top;
	int capacity;
}ST;
void stackinit(ST* st);
void stackpush(ST* st, BitTree* x);
void stackpop(ST* st);
BitTree* stacktop(ST* st);
int sizestack(ST* st);
int stackempty(ST* st);
void stackdestroy(ST* st);