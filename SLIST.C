#include"SLIST.h"
void slistpushback(STU** head, int x)
{
	STU* NEWhead = (STU*)malloc(sizeof(STU));
	NEWhead->num = x;
	NEWhead->next = NULL;
	if (*head == NULL)
	{
		*head = NEWhead;
	}
	else
	{
		STU* tail = *head;
		while (tail->next != NULL)
		{
			tail=tail->next;
		}
		tail->next = NEWhead;
	}
}
void slistprint(STU* head)
{
	STU* cur = head;
	while (cur!= NULL)
	{
		printf("%d ", cur->num);
		cur=cur->next;
	}
}
void slistpushFront(STU** head, int x)
{
	STU *newhead = (STU*)malloc(sizeof(STU));
	newhead->num = x;
	newhead->next = NULL;

		newhead->next = (*head);
		*head = newhead;//返回头节点的位置
}
void slistDeleback(STU** head)
{
	if (*head == NULL)
	{
		return;
	}
	if ((*head)->next == NULL)
	{
		free((*head));
		*head = NULL;
	}
	else
	{
		STU* tail=*head;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next );
		tail->next  = NULL;
		/*STU* P = NULL;
		STU* tail = *head;
		while (tail->next != NULL)
		{
			P = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		P->next = NULL;*/
	}
}
void slistDelefront(STU** head)
{
	/*if (*head == NULL)
	{
		return;
	}
	STU* p = *head;
	(*head) = (*head)->next;
	free(p);
	p = NULL;*/
	if ((*head) == NULL)
	{
		return;
	}
	STU* next = (*head)->next;
	free((*head));
	(*head) = next;
}
STU* slistFind(STU* head, int x)
{
	STU* cur = head;
	while (cur != NULL)
	{
		if (cur->num == x)
		{
			return cur;
		}
		cur = cur->next;
		
	}
	return NULL;
}
void slistInsert(STU** head, int x)
{//后面插入
	/*STU* newhead = (STU*)malloc(sizeof(STU));
	newhead->num = x;
	int n;
	printf("请输入你要在哪个数后面插入\n");
	scanf("%d", &n);
	STU* P = slistFind(*head, n);
	newhead->next = P->next;
	P->next = newhead;*/

	//前面插入	
	STU* newhead = (STU*)malloc(sizeof(STU));
	newhead->num = x;
	int n;
	printf("请输入你要在哪个数前面插入\n");
	scanf("%d", &n);
	STU* P = slistFind(*head, n);
	if (P== *head)
	{
		newhead->next = *head;
		*head = newhead;
		
	}
	else 
	{
		
		STU* P1 = *head;
		while (P1->next != P)
		{
			P1 = P1->next;
		}
		P1->next = newhead;
		newhead->next = P;
	}
}
void slistInsertdele(STU** head, int x)
{
	
	STU *P=slistFind(*head, x);
	STU* cur = *head;
	if (P == *head)
	{
		*head = cur->next;
		free(cur);
		cur = *head;
	}
	else
	{
		while (cur->next != P)
		{
			cur = cur->next;
		}
		cur->next = P->next;
		free(P);
	}
}
void slistdestory(STU** head)
{
	STU* CUR = *head;
	while (CUR)
	{
		STU* next = CUR->next;
			free(CUR);
			CUR = next;
	}
	*head = NULL;
}