#include"bittree1.h"
void test()
{
	BitTree* p;
	printf("请输入第一个节点的数据\n");
	bittreecreate(&p);
	showbittree(p);
}
int main()
{
	test();
	return 0;
}