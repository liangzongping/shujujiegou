#include"BitTree.h"
//�������Ľ�����Ҫ���õݹ飻
void bittreecreate(BitTree **p)
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
			*p=NULL ;
		}
	}
//BitTree* bittreecreate()
//{
//
//	int data;
//	scanf("%d", &data);
//	if (data != -1)
//	{
//		BitTree* p = (BitTree*)malloc(sizeof(BitTree));
//		if (p == NULL)
//		{
//			printf("����ʧ��\n");
//			exit(-1);
//		}
//		else
//		{
//			p->data = data;
//			printf("����������������\n");
//			p->lchild = bittreecreate();
//			printf("����������������\n");
//			p->rchild = bittreecreate();
//			
//		}
//		return p;//��������ڵ�����ӣ����������Һ���
//	}
//	else
//	{
//		return NULL;
//	}
//}
	
void showbittree(BitTree* p)//�������ı���Ҳ�õ��ݹ飨��γ��⣩
{
//	//ǰ�����
//	if (p == NULL)
//	{
//		return ;
//	}
//	printf("%d ", p->data);
//	showbittree(p->lchild);//�ȱ���������
//	showbittree(p->rchild);//����������Һ��ӣ�

//
//	//�������
//	//if(p==NULL)
//	//{
//	//	return;
//	//}
//	//showbittree(p->lchild);//�ȱ�����������
//	//printf("%d ", p->data);
//	//showbittree(p->rchild);
//
//
//	//�������
//	//if (p == NULL)
//	//{
//	//	return;
//	//}
//	//showbittree(p->lchild);//�ȱ���������
//	//showbittree(p->rchild);
//	//printf("%d ", p->data);
//	
//��α���
	squeue a;
	squeueinit(&a);
	squeuepush(&a, p);//�����ĵ�һ���ڵ㽻�����У�ʲô���ж����ԣ�
	while (!squeueEmpty(&a))
	{
		BitTree* n;
		squeuepop(&a, &n);
		printf("%d ", n->data);
		if (n->lchild != NULL)//�ȳ�����
		{
			squeuepush(&a, n->lchild);
		}
		if (n->rchild != NULL)//�ٳ��к���
		{
			squeuepush(&a, n->rchild);
		}
	}	
}

