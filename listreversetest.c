#include"listreverse.h"
//void test1()
//{
//	list* head=NULL;
//	listpush(&head, 1);
//	listpush(&head, 2);
//	listpush(&head, 3);
//	listpush(&head, 4);
//	listpush(&head, 5);
//	listpush(&head, 6);
//	listpush(&head, 7);
//	listreversr(&head);
//	printf("%d ", listtop(&head));
//	listpop(&head);
//	printf("%d ", listtop(&head));
//	listpop(&head);
//	printf("%d ", listtop(&head));
//	listpop(&head);
//	printf("%d ", listtop(&head));
//	listpop(&head);
//	printf("%d ", listtop(&head));
//	listpop(&head);
//	printf("%d ", listtop(&head));
//	listpop(&head);
//	printf("%d ", listtop(&head));
//	listpop(&head);
//	listdestroy(&head);
//	//����ͷ�ڵ�
//}
void test2()
{
	list* head= listinit();
	listpush(head, 1);
	listpush(head, 2);
	listpush(head, 3);
	listpush(head, 4);
	listpush(head, 5);
	listpush(head, 6);
	listpush(head, 7);
	listreversr(head);
	//list* head;
	//listinit(&head);
	//listpush(head, 1);
	//listpush(head, 2);
	//listpush(head, 3);
	//listpush(head, 4);
	printf("%d ", listtop(head));
	listpop(head);
	printf("%d ", listtop(head));
	listpop(head);
	printf("%d ", listtop(head));
	listpop(head);
	printf("%d ", listtop(head));
	listpop(head);
	printf("%d ", listtop(head));
	listpop(head);
	printf("%d ", listtop(head));
	listpop(head);
	printf("%d ", listtop(head));
	listpop(head);
	listdestroy(&head);
}
int main()
{
	//test1();//����ͷ�ڵ�ĵ�����
	test2();//��ͷ���ĵ�����
	return 0;
}