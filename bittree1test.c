#include"bittree1.h"
void test()
{
	BitTree* p;
	printf("�������һ���ڵ������\n");
	bittreecreate(&p);
	showbittree(p);
	printf("һ����%d���ڵ�\n",nodenum(p));
}
int main()
{
	test();
	return 0;
}