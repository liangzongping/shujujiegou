#include"listreverse.h"
//void listpush(list** head, int x)//����ͷ�ڵ����ջ
//{
//	
//	list* newhead = (list*)malloc(sizeof(list));
//	newhead->a = x;
//	newhead->next = NULL;
//	if (*head == NULL)
//	{
//		*head = newhead;
//	}
//	else
//	{
//		newhead->next = *head;
//		*head = newhead;
//	}
//}
//int listtop(list** head)//����ͷ�ĳ�ջ
//{
//	return (*head)->a;
//}
//void listpop(list** head)//����ͷ��ɾ��
//{
//	list* next = (*head)->next;
//	free(*head);
//	*head = next;
//}
//void listdestroy(list** head)//����ͷ������
//{
//	list* cur = *head;
//	while (cur)
//	{
//		list* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	*head = NULL;
//}
//void listreversr(list**head)//��ͷ���ķ�ת
//{
//	list* cur = *head;//��newnodeǰ���������head;�����ǵ�Ų��head
//	list* newnode = NULL;
//	while (cur)
//	{
//		list* next = cur->next;
//		cur->next = newnode;
//		newnode = cur;
//		cur = next;//newnode��Ϊhead
//	}
//	*head = newnode;
//}

//void listinit(list** head)//����ͷ�ڵ�ķ�ʽһ
//{
//	*head = (list*)malloc(sizeof(list));
//	(*head)->next = NULL;//ͷ�ڵ㲻�洢���ݣ����ù�
//}
list* listinit()//����ͷ�ڵ�ķ�ʽ��
{
	list *head= (list*)malloc(sizeof(list));
	head->next = NULL;
	return head;
}
void listpush(list* head, int x)//��ͷ�ڵ����ջ
{
	list* newhead = (list*)malloc(sizeof(list));
	newhead->a = x;
	newhead->next = NULL;
	list* next = head->next;
	head->next = newhead;
	newhead->next = next;
}
void listdestroy(list** head)//��ͷ�ڵ������
{
	list* cur = (*head)->next;
	while (cur)
	{
		list* next = cur->next;
		free(cur);
		cur = next;
	}
	free(*head);
	*head = NULL;
}
int listtop(list* head)//��ͷ�ڵ�ĳ�ջ
{
	if(head->next !=NULL)
	return head->next->a;
}
void listpop(list* head)//��ͷ�ڵ��ɾ��
{
	list* next = head->next->next;
	free(head->next);
	head->next = next;
}
void listreversr(list* head)
{
	list* cur = head->next ;
	list* newnode = NULL;
	while (cur)
	{
		list* next = cur->next;
		head->next = newnode;
		cur->next = newnode;
		head->next = cur;
		newnode = cur;//newnode��Զ��head->next,�ǵ�ÿ�������Ų��newhnode
		cur = next;
	}
}