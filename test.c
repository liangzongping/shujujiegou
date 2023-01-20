#include"stack.h"
void test1()
{
	ST st;
	stackinit(&st);
	stackpush(&st, 1);
	stackpush(&st, 2);
	stackpush(&st, 3);
	stackpush(&st, 4);
	stackpop(&st);
	stackpop(&st);
	stackpush(&st, 5);
	stackpush(&st, 6);
	while (!(stackempty(&st)))//遍历查看；
	{
		printf("%d ", stacktop(&st));
		stackpop(&st);
	}
	/*stackpop(&st);
	stackpop(&st);
	stackpop(&st);
	stackpop(&st);
	stackpop(&st);*/
	//printf("%d", stacktop(&st));
	/*if (stackempty(&st))
		printf("空\n");
	else
		printf("不空\n");*/
	printf("\n%d",sizestack(&st));
	stackdestroy(&st);
}
int main()
{
	test1();
	return 0;
}