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
dlist * dlistFind(dlist* head, int x);//Ҳ�����ö���ָ����������Ҫ�ҵ�λ��
void dlistInsertfront(dlist* head,int x);//�ڵڼ�����ǰ���룻
void dlistInsertback(dlist* pos, int x);//�ڵڼ����������;
void dlistpop(dlist* pos);
void dlistdestory(dlist* head);