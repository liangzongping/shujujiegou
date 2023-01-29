#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//BF
//char* mystrstr(char* a, char* b)
//{
//	//�����±�
//	int len1 = strlen(a);
//	int len2 = strlen(b);
//	int i = 0;
//	int j = 0;
//	while (i < len1 && j < len2)
//	{
//		if (a[i] == b[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			i = i - j + 1;
//			j = 0;
//		}
//		if (j == len2)
//			return &a[i - j];
//	}
//	//	//˫ָ��
//	//		char *cur=a;
//	//		char *p1=NULL;
//	//		char *p2=NULL;
//	//		if(*b=='\0')
//	//		{
//	//			return a;
//	//		 } 
//	//		 while(*cur)
//	//		 {
//	//		 	p1=cur;
//	//		 	p2=b;
//	//		 	while(*p1==*p2&&*p2&&*p1)
//	//		 	{
//	//		 		p1++;
//	//		 		p2++;
//	//			 }
//	//			 if(*p2=='\0')
//	//			 return cur;
//	//			 cur++;
//	//		 }
//	return NULL;
//}
//int main()
//{
//
//	char a[] = "BBCABCDABABCDABCDABDE";
//	char b[] = "ABCDABD";
//	printf("%s", mystrstr(a, b));
//	return 0;
//}




//KMP//next������ʵ�������ͬǰ��׺//���next���飬���������±�ֱ�ָǰ׺�ͺ�׺��ǰ׺���Ա�ʾҪ���ݵ�������׺��ʾnext������±�
void get_next(char* b, int next[])//����KMP,ʹ���Ϊ����//�Ż�����next���飬�����Ż����next���鲻����ԭ���Ǹ�����nextval����
{
	int len = strlen(b);
	int i = 0;
	int j = -1;
	next[0] = -1;

	while (i < len)
	{
		if (j == -1 || b[i] == b[j])//ͨ��ǰ��׺�ıȽ���ȷ���ǰ��׺��j��������
		{
			i++;
			j++;
			if (b[i] != b[j])
			{
				next[i] = j;	
			}
			else//��Ȼ����ǰ����ݺ��һ������û��Ҫ�ص����next������(j)��Ӧ�û��ݵ�ǰ׺��next���飨next[j]����
			{
				next[i] = next[j];
				
			}
			//next[i] = j;
		}
		else
		{
			j = next[j]; 
		}

	}
}

//�������next����
//void get_next(char* b, int next[])
//{
//	if (b == NULL || next == NULL)
//		return;
//	int len = strlen(b);
//	/*if(len==0)
//	{return ;}
//	if(len==1)
//	{next[0]=-1}
//	return ;
//	if(len==2)
//	{next[0]=-1;
//	next[1]=0;
//	return ;}
//	*///Ϊʲô����ֱ�Ӹ�ֵnext[0]=-1;next[1]=0;��Ϊj��Ԫ��ǰû��Ԫ�أ�0������ֻ��һ��Ԫ�أ�û��ǰ��׺����0+1��
//	next[0] = -1;//next[0]==0��ԭ����ģʽ����һ��ƥ��ʧ�ܺ�ģʽ��ָ���˵���һ��ǰ��
//	next[1] = 0;//
//	int i, j;
//	//i��ʾ���ĳ���
//	for (i = 2; i < len; i++)//ģʽ�����±꣬ƥ��ʧ�ܵ��±�ǰ���ַ���
//	{
//		int maxlen = 0;
//		for (j = 1; j < i;j++)//j��ʾȡǰ׺�ڼ�����ȡ��׺�ڼ���
//		{
//			char b1[10];
//			char b2[10];
//			memset(b1, 0, sizeof(b1));
//			memset(b2, 0, sizeof(b2));
//			strncpy(b1, b, j);//ǰ׺
//			strncpy(b2, b + i - j, j);//��׺
//			if (strcmp(b1,b2) == 0)//��ǰ׺�ͺ�׺��ͬ
//			{
//				maxlen = j;
//			}
//		}
//		next[i] = maxlen;
//	}
//}
char* mystrstr(char* a, char* b, int next[])
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	int i = 0, j = 0;
	while (i < len1 && j < len2)
	{
		if (j==-1||a[i] == b[j])
		{
			i++;
			j++;//j++�����ģʽ����һ��
		}
		else
		{
			j = next[j];//��һ��ƥ��ʧ�ܾ�next[0]=-1;��ֵ��j,����j==-1��ʾĿ�괮��ģʽ���ȽϺ�һ��
		}
	}
	if (j == len2)
		return &a[i - len2];
	return NULL;
}
int main()
{
	char a[] = "BBCABCDABABCDABCDABDE";
	char b[] = "ABABAAABA";
	int next[100];
	get_next(b, next);
	int i;
	for (i = 0; i < 100; i++)
	{
		printf("%d ", next[i]);
	}
	printf("%s", mystrstr(a, b, next));
	return 0;
}