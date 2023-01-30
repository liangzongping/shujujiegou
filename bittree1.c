#include"bittree1.h"
void bittreecreate(BitTree** p)//递归实现，先序创建
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
		*p = NULL;
	}
}
void showbittree(BitTree* p)//非递归实现
{
	ST st;
	BitTree* n, * t = p, * r = NULL;

	stackinit(&st);
	//中序遍历
	//while (t||!stackempty(&st))
	//{
	//
	//	if (t)
	//	{
	//		stackpush(&st, t);//把所有的左孩子存入栈中
	//		t = t->lchild;
	//	}
	//	else//直到遇到终端节点，把最后一个左孩子取出，再取根（小根）
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
	//先序遍历
	//while (t || !stackempty(&st))
	//{
	//	while (t)//遍历把所有的左孩子，且把其全部存入栈中，
	//	{
	//		stackpush(&st, t);
	//		printf("%d ", t->data);
	//		t = t->lchild;
	//     }
	//	if (!stackempty(&st))
	//	{
	//		n = stacktop(&st);//出栈一个节点遍历右孩子
	//		stackpop(&st);
	//		t = n;
	//		t = t->rchild;
	//	}
	//}
	//后序遍历

	
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