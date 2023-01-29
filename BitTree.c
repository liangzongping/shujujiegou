#include"BitTree.h"
//二叉树的建立需要利用递归；
//void bittreecreate(BitTree **p)
//{
//	int data;
//	scanf("%d", &data);
//		if (data != -1)
//		{
//			*p = (BitTree*)malloc(sizeof(BitTree));
//			if (*p == NULL)
//			{
//				printf("创建失败\n");
//				exit(-1);
//			}
//			(*p)->data = data;
//			printf("请输入左子树的数据\n");
//			bittreecreate(&((*p)->lchild));//改变左孩子；
//			printf("请输入右子树的数据\n");
//			bittreecreate(&((*p)->rchild));//改变有孩子；
//		}
//		else
//		{
//			*p=NULL ;
//		}
//	}
BitTree* bittreecreate()
{

	int data;
	scanf("%d", &data);
	if (data != -1)
	{
		BitTree* p = (BitTree*)malloc(sizeof(BitTree));
		if (p == NULL)
		{
			printf("创建失败\n");
			exit(-1);
		}
		else
		{
			p->data = data;
			printf("请输入左子树数据\n");
			p->lchild = bittreecreate();
			printf("请输入右子树数据\n");
			p->rchild = bittreecreate();
			
		}
		return p;//返回这个节点给左孩子，接下来是右孩子
	}
	else
	{
		return NULL;
	}
}
	
void showbittree(BitTree* p)//二叉树的遍历也用到递归
{
	//前序遍历
	if (p == NULL)
	{
		return ;
	}
	printf("%d ", p->data);
	showbittree(p->lchild);//先遍历完左孩子
	showbittree(p->rchild);//后先序遍历右孩子；

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
//	
//	
}
