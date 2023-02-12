#include"contact1.h"
void menu()
{
	printf("\n**********************************\n");
	printf("\n*****0.���沢�˳�ͨѶ¼***********\n");
	printf("\n*******1.����ͨѶ¼***************\n");
	printf("\n*******2.��ʾͨѶ¼***************\n");
	printf("\n*******3.ɾ��ͨѶ¼***************\n");
	printf("\n*******4.����ͨѶ¼***************\n");
	printf("\n*******5.�޸�ͨѶ¼***************\n");
	printf("\n*******6.ͳ��ͨѶ¼***************\n");
	printf("\n*******7.���ͨѶ¼***************\n");
	printf("\n**********************************\n");
	printf("\n��ѡ��-->\n");
}
//����û��ͷָ�������洢������Ҫ������������
//��������
void conload(con** head)
{
	stu t = {0};
	FILE* pf = fopen("text1.dat", "rb");
	if (pf == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	else
	{
		while (fread(&t, sizeof(stu), 1, pf))//��fread()������ȡ�ĸ���Ϊ0ʱ����
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
				//β��
				con* tail = *head;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				tail->next = p;
			}
			//���ﲻ�����ٿռ䣬��Ϊheadָ��ָ���⣬����ͨ��condestroy����
		}
		fclose(pf);
		pf = NULL;
	}
	printf("���سɹ�\n");
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
		printf("�������%d���˵����\n", n);
		scanf("%d", &(newnode->student.n));
		if (newnode->student.n != 0)
		{
			n++;
			printf("�������%d���˵�����\n", n - 1);
			scanf("%s", &(newnode->student.name));
			printf("�������%d���˵��Ա�\n", n - 1);
			scanf("%s", &(newnode->student.sex));
			printf("�������%d���˵ĵ绰����\n", n - 1);
			scanf("%d", &(newnode->student.num));
			printf("�������%d���˵ĵ�ַ\n", n - 1);
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
	printf("%-5s     %-5s      %-5s     %-15s      %-20s\n", "���", "����", "�Ա�", "�绰", "��ַ");
	while (head != NULL)
	{

		printf("%-5d     %-5s      %-5s     %-15d      %-20s\n", head->student.n, head->student.name, head->student.sex, head->student.num, head->student.adress);
		head = head->next;
	}
}
con* find(con* head, int n)//�ҵ�Ҫɾ���Ľڵ�
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


	//�����ɾ��
	con* p = find(cur, n);
	if (p == NULL)
	{
		printf("û��������\n");
		return;
	}
	if (p == *head)
	{
		*head = cur->next;
		free(cur);
	}
	else
	{
		//�ҵ�Ҫɾ����ǰһ���ڵ�
		while (cur->next != p)
		{
			cur = cur->next;
		}
		con* next = p->next;
		free(p);
		cur->next = next;
	}
	//ɾ���ڼ�����
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
	printf("ɾ���ɹ�\n");
}
void conInsert(con** head, int n)
{
	con* newnode = (con*)malloc(sizeof(con));
	if (newnode == NULL)
	{
		printf("malloc file\n");
		exit(-1);
	}
	printf("����������˵����\n");
	scanf("%d", &(newnode->student.n));
	printf("����������˵�����\n");
	scanf("%s", &(newnode->student.name));
	printf("����������˵��Ա�\n");
	scanf("%s", &(newnode->student.sex));
	printf("����������˵ĵ绰����\n");
	scanf("%d", &(newnode->student.num));
	printf("����������˵ĵ�ַ\n");
	scanf("%s", &(newnode->student.adress));
	newnode->next = NULL;
	con* cur = *head;
	//�ҵ���Ҫ���ĸ���ź����
	con* q = find(*head, n);
	while (cur != q)
	{
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;
	printf("����ɹ�\n");
}
void conrevise(con** head, int n)
{
	con* cur = *head;
	con* p = find(cur, n);
	while (cur != p)
	{
		cur = cur->next;
	}
	printf("���޸ĸ��˵�����\n");
	printf("����������˵����\n");
	scanf("%d", &(cur->student.n));
	printf("����������˵�����\n");
	scanf("%s", &(cur->student.name));
	printf("����������˵��Ա�\n");
	scanf("%s", &(cur->student.sex));
	printf("����������˵ĵ绰����\n");
	scanf("%d", &(cur->student.num));
	printf("����������˵ĵ�ַ\n");
	scanf("%s", &(cur->student.adress));
	printf("�޸ĳɹ�\n");
}
void consave(con* head)
{
	FILE* pf = fopen("text1.dat", "wb");
	if (pf == NULL)
	{
		printf("�ļ���ʧ��\n");
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
	printf("����ɹ�\n");
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
	printf("ͨѶ¼����%d����", count);
}
void conclear(con** head)
{
	while (*head)
	{
		con* cur = *head;
		*head = cur->next;
		free(cur);
	}
	printf("����ɹ�\n");
}
void condestroy(con** head)
{
	con* cur = *head;
	while (cur)
	{
		//����ǰ��ס��һ���ڵ�ĵ�ַ�������Ҳ���
		con* next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}