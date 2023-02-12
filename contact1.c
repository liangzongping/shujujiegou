#include"contact1.h"
void menu()
{
	printf("\n**********************************\n");
	printf("\n*****0.保存并退出通讯录***********\n");
	printf("\n*******1.创建通讯录***************\n");
	printf("\n*******2.显示通讯录***************\n");
	printf("\n*******3.删除通讯录***************\n");
	printf("\n*******4.插入通讯录***************\n");
	printf("\n*******5.修改通讯录***************\n");
	printf("\n*******6.统计通讯录***************\n");
	printf("\n*******7.清除通讯录***************\n");
	printf("\n**********************************\n");
	printf("\n请选择-->\n");
}
//采用没有头指针的链表存储，不需要考虑扩容问题
//加载数据
void conload(con** head)
{
	stu t = {0};
	FILE* pf = fopen("text1.dat", "rb");
	if (pf == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	else
	{
		while (fread(&t, sizeof(stu), 1, pf))//当fread()函数读取的个数为0时结束
		{
			con* p = (con*)malloc(sizeof(con));
			p->next = NULL;
			p->student = t;
			if (*head == NULL)
			{
				*head = p;
			}
			else
			{
				//尾插
				con* tail = *head;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				tail->next = p;
			}
			//这里不需销毁空间，因为head指针指向这，最终通过condestroy销毁
		}
		fclose(pf);
		pf = NULL;
	}
	printf("加载成功\n");
}
void createcon(con** head)
{
	int n = 1;
	while (n)
	{
		con* newnode = (con*)malloc(sizeof(con));
		if (newnode == NULL)
		{
			printf("malloc file \n");
			exit(-1);
		}
		printf("请输入第%d个人的序号\n", n);
		scanf("%d", &(newnode->student.n));
		if (newnode->student.n != 0)
		{
			n++;
			printf("请输入第%d个人的名字\n", n - 1);
			scanf("%s", &(newnode->student.name));
			printf("请输入第%d个人的性别\n", n - 1);
			scanf("%s", &(newnode->student.sex));
			printf("请输入第%d个人的电话号码\n", n - 1);
			scanf("%d", &(newnode->student.num));
			printf("请输入第%d个人的地址\n", n - 1);
			scanf("%s", &(newnode->student.adress));
			newnode->next = NULL;
			if (*head == NULL)
			{
				*head = newnode;
			}
			else
			{
				con* tail = *head;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				tail->next = newnode;

			}
		}
		else
		{
			return;
		}
	}

}
void conprint(con* head)
{
	printf("%-5s     %-5s      %-5s     %-15s      %-20s\n", "序号", "名字", "性别", "电话", "地址");
	while (head != NULL)
	{

		printf("%-5d     %-5s      %-5s     %-15d      %-20s\n", head->student.n, head->student.name, head->student.sex, head->student.num, head->student.adress);
		head = head->next;
	}
}
con* find(con* head, int n)//找到要删除的节点
{
	if (head == NULL)
		return NULL;
	con* cur = head;
	while (cur)
	{
		if (cur->student.n == n)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void condele(con** head, int n)
{
	con* cur = *head;


	//按序号删除
	con* p = find(cur, n);
	if (p == NULL)
	{
		printf("没有这个序号\n");
		return;
	}
	if (p == *head)
	{
		*head = cur->next;
		free(cur);
	}
	else
	{
		//找到要删除的前一个节点
		while (cur->next != p)
		{
			cur = cur->next;
		}
		con* next = p->next;
		free(p);
		cur->next = next;
	}
	//删除第几个人
	/*int i = 1;
	if (n == 1)
	{
		*head = cur->next;
		free(cur);
	}
	else
	{
		while (i < n - 1 && cur->next->next != NULL)
		{
			i++;
			cur = cur->next;
		}
		con* p = cur->next->next;
		free(cur->next);
		cur->next = p;
	}*/
	printf("删除成功\n");
}
void conInsert(con** head, int n)
{
	con* newnode = (con*)malloc(sizeof(con));
	if (newnode == NULL)
	{
		printf("malloc file\n");
		exit(-1);
	}
	printf("请输入这个人的序号\n");
	scanf("%d", &(newnode->student.n));
	printf("请输入这个人的名字\n");
	scanf("%s", &(newnode->student.name));
	printf("请输入这个人的性别\n");
	scanf("%s", &(newnode->student.sex));
	printf("请输入这个人的电话号码\n");
	scanf("%d", &(newnode->student.num));
	printf("请输入这个人的地址\n");
	scanf("%s", &(newnode->student.adress));
	newnode->next = NULL;
	con* cur = *head;
	//找到你要在哪个序号后插入
	con* q = find(*head, n);
	while (cur != q)
	{
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;
	printf("插入成功\n");
}
void conrevise(con** head, int n)
{
	con* cur = *head;
	con* p = find(cur, n);
	while (cur != p)
	{
		cur = cur->next;
	}
	printf("请修改该人的数据\n");
	printf("请输入这个人的序号\n");
	scanf("%d", &(cur->student.n));
	printf("请输入这个人的名字\n");
	scanf("%s", &(cur->student.name));
	printf("请输入这个人的性别\n");
	scanf("%s", &(cur->student.sex));
	printf("请输入这个人的电话号码\n");
	scanf("%d", &(cur->student.num));
	printf("请输入这个人的地址\n");
	scanf("%s", &(cur->student.adress));
	printf("修改成功\n");
}
void consave(con* head)
{
	FILE* pf = fopen("text1.dat", "wb");
	if (pf == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	else
	{
		con* cur = head;
		while (cur)
		{
			fwrite(&(cur->student ), sizeof(stu), 1, pf);
			cur = cur->next;
		}
		fclose(pf);
		pf = NULL;
	}
	printf("保存成功\n");
}
void compute(con* head)
{
	int count = 0;
	con* cur = head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	printf("通讯录中有%d个人", count);
}
void conclear(con** head)
{
	while (*head)
	{
		con* cur = *head;
		*head = cur->next;
		free(cur);
	}
	printf("清楚成功\n");
}
void condestroy(con** head)
{
	con* cur = *head;
	while (cur)
	{
		//销毁前记住下一个节点的地址，以免找不到
		con* next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}