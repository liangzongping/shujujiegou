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
}
int main()
{
	//test();
	test1();//二级指针传参
	return 0;
}