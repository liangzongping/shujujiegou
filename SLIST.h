#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct S {
	int num;
	struct S * next;
}STU;
void slistpushback(STU **head,int x);
void slistprint(STU* head);
void slistpushFront(STU** head, int x);
void slistDeleback(STU** head);
void slistDelefront(STU** head);
STU* slistFind(STU* head, int x);
void slistInsert(STU** head, int x);
void slistInsertdele(STU** head, int x);
void slistdestory(STU** head);