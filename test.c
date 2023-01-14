#include"SLIST.h"
void test1()
{
	STU* head = NULL;
	slistpushback(&head,2);
	slistpushback(&head,1);
	slistpushback(&head,3);
	slistpushback(&head, 2);
	slistpushback(&head,4);
	/*slistpushFront(&head, 0);
	slistpushFront(&head, 9);
	slistpushFront(&head, 6);*/
	//slistDeleback(&head);
	/*slistDelefront(&head);
	slistDelefront(&head);*/
	//slistDelefront(&head);
	//slistDelefront(&head);
	//slistprint(head);
	/*STU* P = slistFind(head, 2);
	int i=1;
	while (P)
	{
		printf("\n%d\n", i++);
		P= slistFind(P->next, 2);
	}*/
	/*STU *P= slistFind(head, 3);
	if(P!=NULL)
	P->num = 66;
	printf("\n");
	slistprint(head);*/
	/*printf("\n");
	slistInsert(&head, 66);
	slistprint(head);
	printf("\n");
	int n;
	printf("ÇëÊäÈëÄãÒªÉ¾³ıÄÄ¸öÊı×Ö\n");
	scanf("%d", &n);
	slistInsertdele(&head, n);*/

	slistprint(head);
	slistdestory(&head);
}
int main()
{
	test1();
	return 0;
}