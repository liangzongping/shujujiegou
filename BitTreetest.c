#include"BitTree.h"
//void test()
//{
//	printf("请输入第一个节点数据\n");
//	BitTree* p= bittreecreate();
//	showbittree(p);
//}
void test1()
{
	printf("请输入第一个节点数据\n");
	BitTree* p=NULL;
	bittreecreate(&p);
	showbittree(p);
	/*if (!bittreeEmpty(p))
		printf("不空\n");
	else
	{
		printf("空\n");
	}*/
	printf("\n叶子数为%d\n", leaves(p));
	printf("深度为%d\n", deep(p));
	printf("5所在的层数为%d\n", floor(p, 5));
	printf("一共有%d个节点\n",nodenum(p));
	/*printf("\n");
	BitTree *q=NULL;
	bittreecopy(&q, p);
	showbittree(q);*/
	bittreedestroy(&p);
}
int main()
{
	//test();
	test1();//二级指针传参
	return 0;
}