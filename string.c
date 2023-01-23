#include"string.h"
void stringinit(string* s)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		s->s[i] = '\0';
	}
	s->length = 0;
}
void stringpush(string* s, char x)
{
	s->s[s->length] = x;
	s->length++;
}
int stringEmpty(string* s)
{
	if (s->length == 0)
		return 1;
	else
		return 0;
}
int sizestring(string* s)
{
	return s->length;
}
void clearstring(string* s)
{
	stringinit(s);
}
void strcopy(string* s, char* t)
{
	
	while (*t)
	{
		s->s[s->length++] = *t;
		t++;
	}
}
void strconcat(string* s, char* t)
{
	while (*t)
	{
		s->s[s->length++] = *t;
		t++;
	}
}
char* strstr(string* s, char* t)
{
	char* cur = s->s ;
	char* p1 = NULL;
	char* p2 = NULL;
	if (t == NULL)
		return s->s ;
	while (*cur)
	{
		p1 = cur;
		p2 = t;
		while (*p1 == *p2&&*p2&&*p1)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
			return cur;
		cur++;
	}
	
	return NULL;
}