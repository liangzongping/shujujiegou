#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct dlist {
	int val;
	struct dlist* next;
	struct dlist* prve;
}dlist;
dlist *dlistinit();
void dlistpushback(dlist* head,int x);
void dlistprint(dlist* head);
void dlistpushfront(dlist* head, int x);
void dlistdeleback(dlist* head);