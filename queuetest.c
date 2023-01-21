#include"queue.h"
void test1()
{
	queuep a;
	queueinit(&a);
	queuepush(&a,1);
	queuepush(&a,2);
	queuepush(&a,3);
	queuepush(&a,4);
	//queuepop(&a);
	//queuepop(&a);
	//queuepop(&a);
	//queuepop(&a);
	/*printf("%d",queuefront(&a));
	printf("%d",queueback(&a));*/
	/*if (queueEmpty(&a))
		printf("空队列\n");
	else
	{
		printf("不空\n");
	}*/
	//printf("该队列有%d个", sizequeue(&a));
	queuedestroy(&a);
}
void test2()
{
	queuep a;
	queueinit(&a);
	queuepush(&a, 1);
	queuepush(&a, 2);
	queuepush(&a, 3);
	queuepush(&a, 4);
	while (a.head)
	{
		printf("%d ", a.head->data);
		queuepop(&a);
	}
}
int main()
{
	//test1();
	test2();
	return 0;
}