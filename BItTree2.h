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
//void showbittree(BitTree* p);//�����������
//void Inthreading(BitTree* p);//��������������ͷ�ڵ㣩
//void Inorderthreading(BitTree** head, BitTree* p);//��ͷ�ڵ�����
//void showbithread(BitTree* head);//��ͷ�ڵ�ı���
//��ͷָ���������
void Inthreading(BitTree* p,BitTree **pre);
void Inorderthreading(BitTree* p);
void showbithread1(BitTree* p);
//void showbithread2(BitTree* p);