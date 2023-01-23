#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 100
typedef struct string {
	char s[MAX];
	int length;
}string;
void stringinit(string* s);
void stringpush(string* s, char x);
int stringEmpty(string *s);
int sizestring(string* s);
void clearstring(string* s);
void strcopy(string* s, char* t);
void strconcat(string* s, char* t);
char* strstr(string* s, char* t);
