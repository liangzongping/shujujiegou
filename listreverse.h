#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct list {
	int a;
	struct list* next;
}list;
//void listpush(list** head, int x);//��ͷ�ڵ����ջ,�����ʼ����
//void listpop(list** head);
//int listtop(list** head);
//void listdestroy(list** head);
//void listreversr(list** head);
//void listinit(list** head);
list* listinit();
void listpush(list* head, int x);//��ͷ�ڵ����ջ
void listpop(list* head);
int listtop(list* head);
void listdestroy(list** head);
void listreversr(list* head);