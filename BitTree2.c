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
		printf("请输入左子树的数据\n");
		bittreecreate(&((*p)->lchild));
		printf("请输入右子树的数据\n");
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
//void Inthreading(BitTree* p)//树的线索化
//{
//	if (p)
//	{
//		Inthreading(p->lchild);//左孩子线索化
//		//如果没有左孩子
//		if (p->lchild == NULL)
//		{
//			p->ltag = 1;//前继线索化
//			p->lchild = pre;//指向前一个节点
//		}
//		if (pre->rchild == NULL)
//		{
//			pre->rtag = 1;//后继线索化
//			pre->rchild = p;//指向当前节点
//		}
//		pre = p;//保持指向前驱节点
//		Inthreading(p->rchild);//右孩子线索化
//	}
//}
//void Inorderthreading(BitTree** head, BitTree* p)//链接指针，使其更加方便
//{
//	(*head) = (BitTree*)malloc(sizeof(BitTree));
//	if (*head == NULL)
//	{
//		printf("malloc file\n");
//		exit(-1);
//	}
//	if (p == NULL)
//	{
//		(*head)->lchild = *head;//空树就指向自己
//	}
//	else
//	{
//		(*head)->lchild = p;//头指针的左孩子链接根节点
//		pre = (*head);
//		Inthreading(p);//中序线索化后p为null,pre存在右空指针
//		pre->rchild = *head;//最后一个为结束条件，pre的右孩子未处理，使其指向头节点
//		pre->rtag = 1;
//		(*head)->rchild = pre;//标记并使头节点的右孩子指向pre
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





//无头结点
void Inorderthreading(BitTree* p)//树的线索化
{
	BitTree* pre = NULL;//指向前一个节点
	Inthreading(p,&pre);//书店线索化，传入pre的地址是因为要改变pre
	pre->rtag = 1;//最后一个节点因为结束了，pre的右孩子还未处理
	pre->rchild = NULL;
	printf("线索化完成\n");
}
void Inthreading(BitTree* p ,BitTree **pre)
{
	if (p)
	{
		Inthreading(p->lchild,pre);//左子树线索化
		//如果左子树为空
		if (p->lchild == NULL)//当前节点的左孩子为空就指向前驱
		{
			p->ltag = 1;//标记
			p->lchild = *pre;
		}
		if ((*pre)!=NULL&&(*pre)->rchild == NULL)//前驱的右孩子为空，就指向当前节点
		{
			(*pre)->rtag = 1;//标记
			(*pre)->rchild = p;
		}
		*pre = p;//让pre指向下一个节点
		Inthreading(p->rchild,pre);//右子树线索化
	}
}
//BitTree* firstnode(BitTree* p)
//{
//	while (p->ltag==0)//表示中序遍历第一个节点（排第一的在树的左底部）
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
//void showbithread1(BitTree* p)//从左到右遍历中序遍历
//{
//	//如果当前节点的右孩子是线索（rtag==1）,直接返回下一个节点
//	//如果当前节点的右孩子是节点（rtag==0），返回获取中序二叉树第一个节点
//	BitTree* t = firstnode(p);//中序遍历的第一个节点
//	while (t!= NULL)
//	{
//		printf("%d ", t->data);
//		t = nextBitTree1(t);//判断下一个是节点还是线索
//	}
//}
//BitTree* lastnode(BitTree* p)
//{
//	while (p->rtag == 0)//表示中序遍历最后一个（在树的右底部）
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
//void showbithread2(BitTree* p)//从右到左遍历
//{
//	//如果当前节点的右孩子是线索（ltag==1）,直接返回上一个节点
//	//如果当前节点的右孩子是节点（ltag==0），返回获取二叉树中序遍历的最后一个节点
//	BitTree* k = lastnode(p);//中序遍历的最后一个节点
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
		while (p->ltag == 0)//中序遍历的第一个节点
			p = p->lchild;
		printf("%d ", p->data);
		while (p->rtag == 1 && p->rchild !=NULL)//向右遍历是线索就遍历线索，不是就遍历节点
		{
			p = p->rchild;
			printf("%d ", p->data);
		}
		p = p->rchild;
	}
}