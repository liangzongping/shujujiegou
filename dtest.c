#include"DLIST.h"
void test()
{
	dlist *head= dlistinit();
	//dlistpushback(head, 1);	//Ϊʲô���������Ƕ���ָ�룬�����ﴫ����һ��ָ��
	//dlistpushback(head, 2);//��Ϊ��������Ҫ�ı�ͷָ�룬ԭ���ĵ�����û���ڱ�����
	//dlistpushback(head, 3);//��ʹ�õ���ͷ�巨��β��Ҳ�ǣ���Ϊβ���һ���ı�ͷ�ڵ㣩����ͷ����ı䡣
	////��������һ���ڱ��������Ľڵ����ӣ����ı��ڱ�����λ��
	//dlistpushback(head, 4);
	//dlistdeleback(head);
	/*dlistprint(head);*/
	dlistpushfront(head, 6);
	dlistpushfront(head, 7);
	
	dlistpushfront(head, 8);
	dlistpushfront(head, 9);
	//dlistdeleback(head);
	printf("\n");
	
	dlistprint(head);
}
int main()
{
	test();
	return 0;
}