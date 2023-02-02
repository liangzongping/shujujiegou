#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct BitTree {
	int data;
	struct BitTree* lchild;
	struct BitTree* rchild;
	int ltag;
	int rtag;
}BitTree; 
BitTree* pre;
void bittreecreate(BitTree** p);
//void showbittree(BitTree* p);//常规先序遍历
//void Inthreading(BitTree* p);//树的线索化（有头节点）
//void Inorderthreading(BitTree** head, BitTree* p);//与头节点链接
//void showbithread(BitTree* head);//有头节点的遍历
//无头指针的线索化
void Inthreading(BitTree* p,BitTree **pre);
void Inorderthreading(BitTree* p);
void showbithread1(BitTree* p);
//void showbithread2(BitTree* p);