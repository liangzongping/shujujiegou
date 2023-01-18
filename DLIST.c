#include"DLIST.h"
dlist* dlistinit()
{
	//�ڱ���
	dlist* head = (dlist*)malloc(sizeof(dlist));
	head->next = head;
	head->prve = head;
	return head;
}
void dlistpushback( dlist* head,int x)
{
	assert(head);
	/*dlist* tail = head->prve;
	dlist* newhead= (dlist*)malloc(sizeof(dlist));
	newhead->val = x;
	tail->next = newhead;
	newhead->prve = tail;
	newhead->next = head;
	head->prve = newhead;*/
	//���ò�����ʵ��β��
	//dlistInsertfront(head, x);
	dlistInsertback(head->prve, x);
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
	newhead->prve = tail->prve;//��������
	tail->prve = newhead;*/
	//��ȷ����
	
	dlist *newhead=(dlist*)malloc(sizeof(dlist));
	/*dlist* next = head->next;
	head->next = newhead;
	newhead->prve = head;
	newhead->next = next;
	next->prve = newhead;*/
	
	//���ò�����ʵ��ͷ��
	//dlistInsertfront(head->next , x);
	dlistInsertback(head, x);
}
void dlistdeleback(dlist* head)
{
	assert(head);
	assert(head->next != head);
	/*dlist* tail = head->prve;
	dlist* tailprve = tail->prve;
	free(tail);
	tailprve->next = head;
	head->prve = tailprve;*/
	//���ò���ɾ����ʵ�֣�
	dlistpop(head->prve);
}
void dlistdelefront(dlist* head)
{
	assert(head);
	/*dlist* p = head->next;
	head->next = p->next;
	p->next->prve = head;
	free(p);*/
	//���ò���ɾ����ʵ��
	dlistpop(head->next);
}
void dlistInsertfront(dlist* pos,int x)
{
	dlist* newhead = (dlist*)malloc(sizeof(dlist));//��ȷ����
	newhead->val = x;
	//int n;
	//printf("���������ڵڼ��������\n");
	//scanf("%d", &n);
	//dlist* tail = dlistFind(head, n);
	//dlist* next = tail->next;
	//newhead->next = next;
	//next->prve = newhead;
	//tail->next = newhead;
	//newhead->prve = tail;
	dlist* posprve = pos->prve;
	newhead->next = pos;
	pos->prve = newhead;
	newhead->prve = posprve;
	posprve->next = newhead;

}
dlist * dlistFind(dlist* head, int x)
{
	dlist* tail = head;
	int i = 0;
	while (i<x)
	{
		tail = tail->next;
		i++;
		if (tail == head)
			return tail;
	}
	return tail;
}
void dlistInsertback(dlist* pos, int x)
{
	assert(pos);
	dlist* newhead = (dlist*)malloc(sizeof(dlist));//��ȷ����
	newhead->val = x;
	dlist* posnext = pos->next;
	pos->next = newhead;
	newhead->prve = pos;
	newhead->next =posnext;
	posnext->prve = newhead;
}
void dlistpop(dlist* pos)
{
	dlist* posprve = pos->prve;
	dlist* posnext = pos->next;
	posprve->next = posnext;
	posnext->prve = posprve;
	free(pos);
}
void dlistdestory(dlist** head)
{
	assert(head);
	dlist* cur = (*head)->next;
	while (cur->next != *head)
	{
		dlist* next = cur->next;
		free(cur);
		cur = next;
	}
	free(*head);
	*head = NULL;
}