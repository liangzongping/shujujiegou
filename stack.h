#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct ST{
	int* a;
	int top;
	int capacity;
}ST;
void stackinit(ST *st);
void stackpush(ST* st,int x);
void stackpop(ST* st);
int stacktop(ST* st);
int sizestack(ST* st);
int stackempty(ST* st);
void stackdestroy(ST* st);