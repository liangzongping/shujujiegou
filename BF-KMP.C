#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//BF
//char* mystrstr(char* a, char* b)
//{
//	//利用下标
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
//	//	//双指针
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




//KMP//next数组其实是最大相同前后缀//求解next数组，定义两个下标分别指前缀和后缀，前缀可以表示要回溯的量，后缀表示next数组的下标
void get_next(char* b, int next[])//改造KMP,使其变为最优//优化的是next数组，这里优化后的next数组不再是原来那个，是nextval数组
{
	int len = strlen(b);
	int i = 0;
	int j = -1;
	next[0] = -1;

	while (i < len)
	{
		if (j == -1 || b[i] == b[j])//通过前后缀的比较来确定最长前后缀（j来决定）
		{
			i++;
			j++;
			if (b[i] != b[j])
			{
				next[i] = j;	
			}
			else//既然回溯前与回溯后的一样，就没必要回到这个next数组了(j)；应该回溯到前缀的next数组（next[j]）；
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

//暴力求解next数组
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
//	*///为什么可以直接赋值next[0]=-1;next[1]=0;因为j个元素前没有元素（0）或者只有一个元素（没有前后缀）（0+1）
//	next[0] = -1;//next[0]==0的原因是模式串第一个匹配失败后模式串指针退到第一个前面
//	next[1] = 0;//
//	int i, j;
//	//i表示串的长度
//	for (i = 2; i < len; i++)//模式串的下标，匹配失败的下标前的字符串
//	{
//		int maxlen = 0;
//		for (j = 1; j < i;j++)//j表示取前缀第几个和取后缀第几个
//		{
//			char b1[10];
//			char b2[10];
//			memset(b1, 0, sizeof(b1));
//			memset(b2, 0, sizeof(b2));
//			strncpy(b1, b, j);//前缀
//			strncpy(b2, b + i - j, j);//后缀
//			if (strcmp(b1,b2) == 0)//找前缀和后缀相同
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
			j++;//j++后就是模式串第一个
		}
		else
		{
			j = next[j];//第一次匹配失败就next[0]=-1;赋值给j,上面j==-1表示目标串与模式串比较后一个
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