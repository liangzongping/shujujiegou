#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//通讯录的建立
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
//菜单
void menu();
//数据的加载
void conload(con** head);
//通讯录的创建
void createcon(con** head);
//通讯录的显示
void conprint(con* head);
//通讯录的删除
void condele(con** head, int n);
//查找要删除的序号
con* find(con* head, int n);
//通讯录的插入
void conInsert(con** head, int n);
//通讯录的修改
void conrevise(con** head, int n);
//通讯录的保存
void consave(con* head);
//记录通讯录中有多少个人
void compute(con* head);
//清楚通讯录
void conclear(con** head);
//销毁，以免内存泄漏
void condestroy(con** head);