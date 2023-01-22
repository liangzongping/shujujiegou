#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct list {
	int a;
	struct list* next;
}list;
//void listpush(list** head, int x);//无头节点的入栈,无需初始化，
//void listpop(list** head);
//int listtop(list** head);
//void listdestroy(list** head);
//void listreversr(list** head);
//void listinit(list** head);
list* listinit();
void listpush(list* head, int x);//有头节点的入栈
void listpop(list* head);
int listtop(list* head);
void listdestroy(list** head);
void listreversr(list* head);