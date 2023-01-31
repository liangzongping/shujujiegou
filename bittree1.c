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
	//中序遍历（1）
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
	//中序遍历（2）
	while (t || !stackempty(&st))
	{
		while (t)//先存左孩子
		{
			stackpush(&st, t);
			t = t->lchild;
		}
		if (!stackempty(&st))
		{
			n = stacktop(&st);//出战一个左孩子
			stackpop(&st);
			printf("%d ", n->data);
			t = n->rchild;//访问是否有有孩子，有就存其左孩子，没有就在出栈一个（其实每一个节点可以看作一个左孩子）
		}//思路中序遍历让第一个先输出（左孩子）
	}
	
	//先序遍历(1)
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
	//前序遍历（2）
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
	//后序遍历
	//while (t)
	//{
	//	stackpush(&st, t);
	//	t = t->lchild;
	//}//先把左子树全部入栈 
	//while (!stackempty(&st))
	//{
	//	t=stacktop(&st);
	//	stackpop(&st);//出栈一个左孩子
	//	if (t->rchild == NULL || t->rchild == r)//判断左孩子是否有右孩子（）
	//	{
	//		printf("%d ", t->data);//没有直接输出，并标记该孩子，使其下一次不再遍历该孩子
	//		r = t;
	//	}
	//	else
	//	{
	//		stackpush(&st, t);//因为有右孩子，要让右孩子先出栈，故其先回栈
	//		t = t->rchild;//遍历其右孩子
	//		while (t)//把该孩子的全部左孩子先入栈
	//		{
	//			stackpush(&st, t);
	//			t = t->lchild;
	//		}
	//	}
	//}
}//思路：先出左孩子，判断该左孩子是否有右孩子，若有就把改左孩子送回栈中，遍历该右孩子，接着重复上面操作