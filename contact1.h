#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ͨѶ¼�Ľ���
typedef struct stu {
	char name[20];
	char sex[10];
	int num;
	char adress[50];
	int n;
}stu;
typedef struct contact {
	stu student;
	struct contact* next;
}con;
//�˵�
void menu();
//���ݵļ���
void conload(con** head);
//ͨѶ¼�Ĵ���
void createcon(con** head);
//ͨѶ¼����ʾ
void conprint(con* head);
//ͨѶ¼��ɾ��
void condele(con** head, int n);
//����Ҫɾ�������
con* find(con* head, int n);
//ͨѶ¼�Ĳ���
void conInsert(con** head, int n);
//ͨѶ¼���޸�
void conrevise(con** head, int n);
//ͨѶ¼�ı���
void consave(con* head);
//��¼ͨѶ¼���ж��ٸ���
void compute(con* head);
//���ͨѶ¼
void conclear(con** head);
//���٣������ڴ�й©
void condestroy(con** head);