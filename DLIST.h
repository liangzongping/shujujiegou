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
void dlistdelefront(dlist* head);
dlist * dlistFind(dlist* head, int x);//也可以用二级指针来返回你要找的位置
void dlistInsertfront(dlist* head,int x);//在第几个数前插入；
void dlistInsertback(dlist* pos, int x);//在第几个数后插入;
void dlistpop(dlist* pos);
void dlistdestory(dlist* head);