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
void bittreecopy(BitTree** q, BitTree* p)//����������ΪҪ�ı�q
{
	if (p == NULL)
	{
		*q = NULL;
	}//�����ո��ƿ�
	else {
		
		*q = (BitTree*)malloc(sizeof(BitTree));
		if(*q==NULL)
		{
			return;
		}	
	(*q)->data = p->data;
	bittreecopy(&((*q)->lchild), p->lchild);//�ݹ鸴��
	bittreecopy(&((*q)->rchild), p->rchild);
		
	}
	
}
int bittreeEmpty(BitTree* p)
{
	if (p == NULL)
		return 1;
	return 0;
}
int leaves(BitTree* p)
{//�ݹ�д��
	if (p == NULL)//��������
	{
		return 0;
	}
	else if (p->lchild == NULL && p->rchild == NULL)
	{
		return 1;
	}
	else
	{
		return leaves(p->lchild) + leaves(p->rchild);//�ۼ�
	}
}
int deep(BitTree* p)
{
	int lnum, rnum;
	if (p == NULL)
		return 0;
	else
	{
		lnum = deep(p->lchild);
		rnum = deep(p->rchild);
		if (lnum > rnum)
		{
			return lnum + 1;
		}
		else
		{
			return rnum + 1;
		}
	}
}
int floor(BitTree* p, int x)
{
	int lnum;
	int rnum;
	int fnum;
	if (p == NULL)
		 fnum=-1;
	else if (p->data ==x)
	{
		fnum = 1;
	}
	else
	{
		lnum = floor(p->lchild, x);
		rnum = floor(p->rchild, x);
		if (lnum == 0 && rnum == 0)
		{
			//printf("�Ҳ��������ڵĲ���\n");
			fnum = -1;
		}
		else
		{
			if (lnum > rnum)
				fnum = lnum + 1;
			else
				fnum = rnum + 1;
		}
	}
	return fnum;
}
int nodenum(BitTree* p)
{
	//�ݹ飨1��
	//if (p == NULL)
	//	return 0;
	//else
	//{
	//	return (nodenum(p->lchild) + nodenum(p->rchild) + 1);
	//}
	//�ݹ飨2��
	int count = 0;
	if (p == NULL)
		return 0;//��������
	else
	{
		count++;//��һ���ڵ�
		count += nodenum(p->lchild);//�������Ӹ���
		count += nodenum(p->rchild);//�����Һ��Ӹ���
	}
	return count;
}
void showbittree(BitTree* p)//�������ı���Ҳ�õ��ݹ飨��γ��⣩
{
	if (p == NULL)
	{
		return;
	}
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
void bittreedestroy(BitTree** p)
{
	if (*p == NULL)
	{
		return;
	}
	else
	{
		bittreedestroy(&((*p)->lchild));
		bittreedestroy(&((*p)->rchild));
		free(*p);
		*p = NULL;
	}
}
