#include"BitTree.h"
//二叉树的建立需要利用递归；
void bittreecreate(BitTree **p)
{
	int data;
	scanf("%d", &data);
		if (data != -1)
		{
			*p = (BitTree*)malloc(sizeof(BitTree));
			if (*p == NULL)
			{
				printf("创建失败\n");
				exit(-1);
			}
			(*p)->data = data;
			printf("请输入左子树的数据\n");
			bittreecreate(&((*p)->lchild));//改变左孩子；
			printf("请输入右子树的数据\n");
			bittreecreate(&((*p)->rchild));//改变有孩子；
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
//			printf("创建失败\n");
//			exit(-1);
//		}
//		else
//		{
//			p->data = data;
//			printf("请输入左子树数据\n");
//			p->lchild = bittreecreate();
//			printf("请输入右子树数据\n");
//			p->rchild = bittreecreate();
//			
//		}
//		return p;//返回这个节点给左孩子，接下来是右孩子
//	}
//	else
//	{
//		return NULL;
//	}
//}
void bittreecopy(BitTree** q, BitTree* p)//传二级是因为要改变q
{
	if (p == NULL)
	{
		*q = NULL;
	}//遇到空复制空
	else {
		
		*q = (BitTree*)malloc(sizeof(BitTree));
		if(*q==NULL)
		{
			return;
		}	
	(*q)->data = p->data;
	bittreecopy(&((*q)->lchild), p->lchild);//递归复制
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
{//递归写法
	if (p == NULL)//结束条件
	{
		return 0;
	}
	else if (p->lchild == NULL && p->rchild == NULL)
	{
		return 1;
	}
	else
	{
		return leaves(p->lchild) + leaves(p->rchild);//累加
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
			//printf("找不到其所在的层数\n");
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
	//递归（1）
	//if (p == NULL)
	//	return 0;
	//else
	//{
	//	return (nodenum(p->lchild) + nodenum(p->rchild) + 1);
	//}
	//递归（2）
	int count = 0;
	if (p == NULL)
		return 0;//结束条件
	else
	{
		count++;//第一个节点
		count += nodenum(p->lchild);//加上左孩子个数
		count += nodenum(p->rchild);//加上右孩子个数
	}
	return count;
}
void showbittree(BitTree* p)//二叉树的遍历也用到递归（层次除外）
{
	if (p == NULL)
	{
		return;
	}
//	//前序遍历
//	if (p == NULL)
//	{
//		return ;
//	}
//	printf("%d ", p->data);
//	showbittree(p->lchild);//先遍历完左孩子
//	showbittree(p->rchild);//后先序遍历右孩子；

//
//	//中序遍历
//	//if(p==NULL)
//	//{
//	//	return;
//	//}
//	//showbittree(p->lchild);//先遍历靠底左孩子
//	//printf("%d ", p->data);
//	//showbittree(p->rchild);
//
//
//	//后序遍历
//	//if (p == NULL)
//	//{
//	//	return;
//	//}
//	//showbittree(p->lchild);//先遍历左子树
//	//showbittree(p->rchild);
//	//printf("%d ", p->data);
//	
//层次遍历
	squeue a;
	squeueinit(&a);
	squeuepush(&a, p);//把数的第一个节点交给队列（什么队列都可以）
	while (!squeueEmpty(&a))
	{
		BitTree* n;
		squeuepop(&a, &n);
		printf("%d ", n->data);
		if (n->lchild != NULL)//先出左孩子
		{
			squeuepush(&a, n->lchild);
		}
		if (n->rchild != NULL)//再出有孩子
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
