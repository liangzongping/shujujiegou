#include"BItTree2.h"
void bittreecreate(BitTree** p)
{
	int data;
	scanf("%d", &data);
	if (data != -1)
	{
		*p = (BitTree*)malloc(sizeof(BitTree));
		if (*p == NULL)
		{
			printf("molloc file\n");
			exit(-1);
		}
		(*p)->data = data;
		(*p)->ltag = 0;
		(*p)->rtag = 0;
		printf("������������������\n");
		bittreecreate(&((*p)->lchild));
		printf("������������������\n");
		bittreecreate(&((*p)->rchild));
	}
	else
	{
		*p = NULL;
	}
}
//void showbittree(BitTree* p)
//{
//	if (p == NULL)
//	{
//		return ;
//	}
//	else
//	{
//		printf("%d ", p->data);
//		showbittree(p->lchild);
//		showbittree(p->rchild);
//	}
//}
//void Inthreading(BitTree* p)//����������
//{
//	if (p)
//	{
//		Inthreading(p->lchild);//����������
//		//���û������
//		if (p->lchild == NULL)
//		{
//			p->ltag = 1;//ǰ��������
//			p->lchild = pre;//ָ��ǰһ���ڵ�
//		}
//		if (pre->rchild == NULL)
//		{
//			pre->rtag = 1;//���������
//			pre->rchild = p;//ָ��ǰ�ڵ�
//		}
//		pre = p;//����ָ��ǰ���ڵ�
//		Inthreading(p->rchild);//�Һ���������
//	}
//}
//void Inorderthreading(BitTree** head, BitTree* p)//����ָ�룬ʹ����ӷ���
//{
//	(*head) = (BitTree*)malloc(sizeof(BitTree));
//	if (*head == NULL)
//	{
//		printf("malloc file\n");
//		exit(-1);
//	}
//	if (p == NULL)
//	{
//		(*head)->lchild = *head;//������ָ���Լ�
//	}
//	else
//	{
//		(*head)->lchild = p;//ͷָ����������Ӹ��ڵ�
//		pre = (*head);
//		Inthreading(p);//������������pΪnull,pre�����ҿ�ָ��
//		pre->rchild = *head;//���һ��Ϊ����������pre���Һ���δ����ʹ��ָ��ͷ�ڵ�
//		pre->rtag = 1;
//		(*head)->rchild = pre;//��ǲ�ʹͷ�ڵ���Һ���ָ��pre
//	}
//}
//void showbithread(BitTree* head)
//{
//	BitTree* p;
//	p = head->lchild;
//	while (p!=head)
//	{
//			while (p->ltag == 0)
//			p = p->lchild;
//			printf("%d ", p->data);
//			while (p->rtag == 1 && p->rchild !=head)
//			{
//				p = p->rchild;
//				printf("%d ", p->data);
//			}
//			p = p->rchild;
//	}
//}





//��ͷ���
void Inorderthreading(BitTree* p)//����������
{
	BitTree* pre = NULL;//ָ��ǰһ���ڵ�
	Inthreading(p,&pre);//���������������pre�ĵ�ַ����ΪҪ�ı�pre
	pre->rtag = 1;//���һ���ڵ���Ϊ�����ˣ�pre���Һ��ӻ�δ����
	pre->rchild = NULL;
	printf("���������\n");
}
void Inthreading(BitTree* p ,BitTree **pre)
{
	if (p)
	{
		Inthreading(p->lchild,pre);//������������
		//���������Ϊ��
		if (p->lchild == NULL)//��ǰ�ڵ������Ϊ�վ�ָ��ǰ��
		{
			p->ltag = 1;//���
			p->lchild = *pre;
		}
		if ((*pre)!=NULL&&(*pre)->rchild == NULL)//ǰ�����Һ���Ϊ�գ���ָ��ǰ�ڵ�
		{
			(*pre)->rtag = 1;//���
			(*pre)->rchild = p;
		}
		*pre = p;//��preָ����һ���ڵ�
		Inthreading(p->rchild,pre);//������������
	}
}
//BitTree* firstnode(BitTree* p)
//{
//	while (p->ltag==0)//��ʾ���������һ���ڵ㣨�ŵ�һ����������ײ���
//	{
//		p = p->lchild;
//	}
//	return p;
//}
//BitTree* nextBitTree1(BitTree* p)
//{
//	if (p->rtag == 0)
//	{
//		return firstnode(p->rchild);
//	}
//	else
//	{
//		return p->rchild;
//	}
//}
//void showbithread1(BitTree* p)//�����ұ����������
//{
//	//�����ǰ�ڵ���Һ�����������rtag==1��,ֱ�ӷ�����һ���ڵ�
//	//�����ǰ�ڵ���Һ����ǽڵ㣨rtag==0�������ػ�ȡ�����������һ���ڵ�
//	BitTree* t = firstnode(p);//��������ĵ�һ���ڵ�
//	while (t!= NULL)
//	{
//		printf("%d ", t->data);
//		t = nextBitTree1(t);//�ж���һ���ǽڵ㻹������
//	}
//}
//BitTree* lastnode(BitTree* p)
//{
//	while (p->rtag == 0)//��ʾ����������һ�����������ҵײ���
//	{
//		p = p->rchild;
//	}
//	return p;
//}
//BitTree* nextBitTree2(BitTree* p)
//{
//	if (p->ltag == 0)
//	{
//		return lastnode(p->lchild);
//	}
//	else
//		return p->lchild;
//}
//void showbithread2(BitTree* p)//���ҵ������
//{
//	//�����ǰ�ڵ���Һ�����������ltag==1��,ֱ�ӷ�����һ���ڵ�
//	//�����ǰ�ڵ���Һ����ǽڵ㣨ltag==0�������ػ�ȡ������������������һ���ڵ�
//	BitTree* k = lastnode(p);//������������һ���ڵ�
//	while (k != NULL)
//	{
//		printf("%d ", k->data);
//		k = nextBitTree2(k);
//	}
//}
void showbithread1(BitTree* p)
{
	
	while (p !=NULL)
	{
		while (p->ltag == 0)//��������ĵ�һ���ڵ�
			p = p->lchild;
		printf("%d ", p->data);
		while (p->rtag == 1 && p->rchild !=NULL)//���ұ����������ͱ������������Ǿͱ����ڵ�
		{
			p = p->rchild;
			printf("%d ", p->data);
		}
		p = p->rchild;
	}
}