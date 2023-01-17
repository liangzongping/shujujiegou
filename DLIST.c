#include"DLIST.h"
dlist* dlistinit()
{
	//哨兵卫
	dlist* head = (dlist*)malloc(sizeof(dlist));
	head->next = head;
	head->prve = head;
	return head;
}
void dlistpushback( dlist* head,int x)
{
	assert(head);
	dlist* tail = head->prve;
	dlist* newhead= (dlist*)malloc(sizeof(dlist));
	newhead->val = x;
	tail->next = newhead;
	newhead->prve = tail;
	newhead->next = head;
	head->prve = newhead;
}
void dlistprint(dlist* head)
{

	dlist* p = head->next;
	while (p!=head)
	{
		printf("%d ", p->val);
		p = p->next;
	}
}
void dlistpushfront(dlist* head, int x)
{
	assert(head);
	/*dlist* tail = head->prve;
	dlist* newhead = (dlist*)malloc(sizeof(dlist));
	newhead->val = x;
	newhead->next = head->next;
	head->next = newhead;
	newhead->prve = tail->prve;//错误做法
	tail->prve = newhead;*/
	dlist *newhead=(dlist*)malloc(sizeof(dlist));//正确做法
	newhead->val = x;
	dlist* next = head->next;
	head->next = newhead;
	newhead->prve = head;
	newhead->next = next;
	next->prve = newhead;


}
void dlistdeleback(dlist* head)
{
	assert(head);
	assert(head->next != head);
	dlist* tail = head->prve;
	dlist* tailprve = tail->prve;
	free(tail);
	tailprve->next = head;
	head->prve = tailprve;
	
	
}