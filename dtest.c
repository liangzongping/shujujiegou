#include"DLIST.h"
void test()
{
	dlist *head= dlistinit();
	dlistpushback(head, 1);	//为什么单链表传的是二级指针，而这里传的是一级指针
	dlistpushback(head, 2);//因为单链表需要改变头指针，原来的单链表没有哨兵卫，
	dlistpushback(head, 3);//若使用的是头插法（尾插也是，因为尾插第一个改变头节点），那头结点会改变。	                      
	dlistpushback(head, 4);//而这里有一个哨兵卫，它的节点增加，不改变哨兵卫的位置
	//dlistdeleback(head);
	//dlistdelefront(head);
	//dlistprint(head);
	//dlistpushfront(head, 6);
	//dlistpushfront(head, 7);
	//dlistpushfront(head, 8);
	//dlistpushfront(head, 9);
	/*dlist *pos=dlistFind(head, 4);
	dlistpop(pos)*/;
	//dlistInsertfront(pos, 66);
	//dlistInsertback(pos, 66);
	//dlistdelefront(head);
	////dlistdeleback(head);
	//printf("\n");
	dlistprint(head);
	dlistdestory(&head);//为什么要传二级指针呢？因为要把哨兵卫释放掉，需要改变头指针，故要传二级指针
}
int main()
{
	test();
	return 0;
}