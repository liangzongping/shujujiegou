#include"BitTree.h"
//void test()
//{
//	printf("�������һ���ڵ�����\n");
//	BitTree* p= bittreecreate();
//	showbittree(p);
//}
void test1()
{
	printf("�������һ���ڵ�����\n");
	BitTree* p=NULL;
	bittreecreate(&p);
	showbittree(p);
	/*if (!bittreeEmpty(p))
		printf("����\n");
	else
	{
		printf("��\n");
	}*/
	printf("\nҶ����Ϊ%d\n", leaves(p));
	printf("���Ϊ%d\n", deep(p));
	printf("5���ڵĲ���Ϊ%d\n", floor(p, 5));
	printf("һ����%d���ڵ�\n",nodenum(p));
	/*printf("\n");
	BitTree *q=NULL;
	bittreecopy(&q, p);
	showbittree(q);*/
	bittreedestroy(&p);
}
int main()
{
	//test();
	test1();//����ָ�봫��
	return 0;
}