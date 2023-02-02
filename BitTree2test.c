#include"BItTree2.h"
void test()
{
	BitTree* p = NULL;
	//BitTree* head;
	printf("请输入根节点的数据\n");
	bittreecreate(&p);
	/*Inorderthreading(&head,p);
	showbithread(head);*/




	Inorderthreading(p);
	//printf("从左到右遍历中序遍历\n");
	//showbithread1(p);
	//printf("\n");
	//printf("从右到左遍历中序遍历\n");
	//showbithread2(p);
	showbithread1(p);


	//showbittree(p);
}
int main()
{
	test();
	return 0;
}