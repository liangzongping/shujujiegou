#include"BItTree2.h"
void test()
{
	BitTree* p = NULL;
	//BitTree* head;
	printf("��������ڵ������\n");
	bittreecreate(&p);
	/*Inorderthreading(&head,p);
	showbithread(head);*/




	Inorderthreading(p);
	//printf("�����ұ����������\n");
	//showbithread1(p);
	//printf("\n");
	//printf("���ҵ�������������\n");
	//showbithread2(p);
	showbithread1(p);


	//showbittree(p);
}
int main()
{
	test();
	return 0;
}