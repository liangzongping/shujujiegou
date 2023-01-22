#include"sqdoublestack.h"
void test()
{
	Dstack a;
	Dstackinit(&a);
	Dstackpush(&a, 1, 1);
	Dstackpush(&a, 2, 1);
	Dstackpush(&a, 3, 1);
	Dstackpush(&a, 4, 1);
	Dstackpush(&a, 5, 1);
	Dstackpush(&a, 6, 2);
	Dstackpush(&a, 7, 2);
	Dstackpush(&a, 8, 2);
	Dstackpush(&a, 9, 2);
	Dstackpush(&a, 10,2);
	//printf("%d ",Dstackpop(&a, 1));//Õ»1³öÕ»
	//printf("%d ",Dstackpop(&a, 1));
	//printf("%d ",Dstackpop(&a, 1));
	//printf("%d ",Dstackpop(&a, 1));
	//printf("%d ",Dstackpop(&a, 1));
	printf("%d ", Dstackpop(&a, 2));//Õ»2³öÕ»
	printf("%d ", Dstackpop(&a, 2));
	printf("%d ", Dstackpop(&a, 2));
	printf("%d ", Dstackpop(&a, 2));
	printf("%d ", Dstackpop(&a, 2));
	//printf("%d ",Dstackpop(&a, 2));
	
}
int main()
{
	test();
	return 0;
}