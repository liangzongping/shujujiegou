#include"bittree1.h"
void bittreecreate(BitTree** p)//�ݹ�ʵ�֣����򴴽�
{
	int data;
	scanf("%d", &data);
	if (data != -1)
	{
		*p = (BitTree*)malloc(sizeof(BitTree));
		if (*p == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		(*p)->data = data;
		printf("������������������\n");
		bittreecreate(&((*p)->lchild));//�ı����ӣ�
		printf("������������������\n");
		bittreecreate(&((*p)->rchild));//�ı��к��ӣ�
	}
	else
	{
		*p = NULL;
	}
}
void showbittree(BitTree* p)//�ǵݹ�ʵ��
{
	ST st;
	BitTree* n, * t = p, * r = NULL;

	stackinit(&st);
	//�������
	//while (t||!stackempty(&st))
	//{
	//
	//	if (t)
	//	{
	//		stackpush(&st, t);//�����е����Ӵ���ջ��
	//		t = t->lchild;
	//	}
	//	else//ֱ�������ն˽ڵ㣬�����һ������ȡ������ȡ����С����
	//	{
	//		n = stacktop(&st);
	//		stackpop(&st);
	//		printf("%d ", n->data);
	//		t = n->rchild;
	//	}
	//	
	//		
	//}
	//
	//�������
	//while (t || !stackempty(&st))
	//{
	//	while (t)//���������е����ӣ��Ұ���ȫ������ջ�У�
	//	{
	//		stackpush(&st, t);
	//		printf("%d ", t->data);
	//		t = t->lchild;
	//     }
	//	if (!stackempty(&st))
	//	{
	//		n = stacktop(&st);//��ջһ���ڵ�����Һ���
	//		stackpop(&st);
	//		t = n;
	//		t = t->rchild;
	//	}
	//}
	//�������

	
	while (t || !stackempty(&st))
	{
		if (t)
		{
			stackpush(&st, t);
			t = t->lchild;
		}
		else
		{
			t = stacktop(&st);
			if (t->rchild == NULL || t->rchild == r)
			{
				stackpop(&st);
				printf("%d ", t->data);
				r = t;
			}
			else
			{
				t = t->rchild;
				while (t)
				{
					stackpush(&st, t);
					t = t->lchild;
				}
			}
		}
	}
}