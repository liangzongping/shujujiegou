#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef struct BitTree {
	int data;
	struct BitTree* lchild;
	struct BitTree* rchild;
}BitTree;
//void bittreecreate(BitTree **p);//二级传参
BitTree* bittreecreate();
void showbittree(BitTree* p);

//void bittreedestroy(BitTree* p);


