#include"squeue.h"
void test()
{
	squeue a;
	squeueinit(&a);
	squeuepush(&a, 1);
	squeuepush(&a, 2);
	squeuepush(&a, 3);
	squeuepush(&a, 4);
	//squeuepop(&a);
	//squeuepop(&a);
	squeuepush(&a, 5);
	squeuepush(&a, 6);
	squeuepop(&a);
	squeuepop(&a);
	squeuepush(&a, 7);
	squeuepush(&a, 8);
	//squeuepop(&a);
	while (a.front != a.rear)
	{
		printf("%d ", a.data[a.front ]);
		a.front = (a.front + 1) % Max;
	}
	/*if (squeueEmpty(&a))
		printf("\n¿Õ\n");
	else
	{
		printf("²»¿Õ\n");
	}*/
	/*if (squeuemax(&a))
		printf("\nÒÑÂú\n");
	else
	{
		printf("²»Âú\n");
	}*/
}
int main()
{
	test();
	return 0;
}