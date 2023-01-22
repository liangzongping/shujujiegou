#include"listreverse.h"
//void listpush(list** head, int x)//不带头节点的入栈
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
//int listtop(list** head)//不带头的出栈
//{
//	return (*head)->a;
//}
//void listpop(list** head)//不带头的删除
//{
//	list* next = (*head)->next;
//	free(*head);
//	*head = next;
//}
//void listdestroy(list** head)//不带头的销毁
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
//void listreversr(list**head)//无头结点的反转
//{
//	list* cur = *head;//在newnode前面插入链表head;插入后记得挪动head
//	list* newnode = NULL;
//	while (cur)
//	{
//		list* next = cur->next;
//		cur->next = newnode;
//		newnode = cur;
//		cur = next;//newnode变为head
//	}
//	*head = newnode;
//}

//void listinit(list** head)//创建头节点的方式一
//{
//	*head = (list*)malloc(sizeof(list));
//	(*head)->next = NULL;//头节点不存储数据，不用管
//}
list* listinit()//创建头节点的方式二
{
	list *head= (list*)malloc(sizeof(list));
	head->next = NULL;
	return head;
}
void listpush(list* head, int x)//有头节点的入栈
{
	list* newhead = (list*)malloc(sizeof(list));
	newhead->a = x;
	newhead->next = NULL;
	list* next = head->next;
	head->next = newhead;
	newhead->next = next;
}
void listdestroy(list** head)//有头节点的销毁
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
int listtop(list* head)//有头节点的出栈
{
	if(head->next !=NULL)
	return head->next->a;
}
void listpop(list* head)//有头节点的删除
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
		newnode = cur;//newnode永远是head->next,记得每个插入后挪动newhnode
		cur = next;
	}
}