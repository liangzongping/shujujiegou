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
	//���������1��
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
	//���������2��
	while (t || !stackempty(&st))
	{
		while (t)//�ȴ�����
		{
			stackpush(&st, t);
			t = t->lchild;
		}
		if (!stackempty(&st))
		{
			n = stacktop(&st);//��սһ������
			stackpop(&st);
			printf("%d ", n->data);
			t = n->rchild;//�����Ƿ����к��ӣ��оʹ������ӣ�û�о��ڳ�ջһ������ʵÿһ���ڵ���Կ���һ�����ӣ�
		}//˼·��������õ�һ������������ӣ�
	}
	
	//�������(1)
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
	//ǰ�������2��
	/*while (t || !stackempty(&st))
	{
		if (t)
		{
			printf("%d ", t->data);
			stackpush(&st, t);
			t = t->lchild;
		}
		else
		{
			n = stacktop(&st);
			stackpop(&st);
			t = n;
			t = t->rchild; 
		}
		}*/
	//�������
	//while (t)
	//{
	//	stackpush(&st, t);
	//	t = t->lchild;
	//}//�Ȱ�������ȫ����ջ 
	//while (!stackempty(&st))
	//{
	//	t=stacktop(&st);
	//	stackpop(&st);//��ջһ������
	//	if (t->rchild == NULL || t->rchild == r)//�ж������Ƿ����Һ��ӣ���
	//	{
	//		printf("%d ", t->data);//û��ֱ�����������Ǹú��ӣ�ʹ����һ�β��ٱ����ú���
	//		r = t;
	//	}
	//	else
	//	{
	//		stackpush(&st, t);//��Ϊ���Һ��ӣ�Ҫ���Һ����ȳ�ջ�������Ȼ�ջ
	//		t = t->rchild;//�������Һ���
	//		while (t)//�Ѹú��ӵ�ȫ����������ջ
	//		{
	//			stackpush(&st, t);
	//			t = t->lchild;
	//		}
	//	}
	//}
}//˼·���ȳ����ӣ��жϸ������Ƿ����Һ��ӣ����оͰѸ������ͻ�ջ�У��������Һ��ӣ������ظ��������