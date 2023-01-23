#include"string.h"
void test()
{
	string st;
	char t[] = "orla";
	stringinit(&st);
	stringpush(&st, 'h');
	stringpush(&st, 'e');
	stringpush(&st, 'l');
	stringpush(&st, 'l');
	stringpush(&st, 'o');
	stringpush(&st, 'w');
	stringpush(&st, 'o');
	stringpush(&st, 'r');
	stringpush(&st, 'l');
	stringpush(&st, 'd');
	/*char c;
	scanf("%c", &c);
	if (c != '0')
	{
		do
		{
			stringpush(&st, c);
			scanf("%c", &c);

		} while (c != '\n');
	}
	printf("%d\n", sizestring(&st));
	if (stringEmpty(&st))
	{
		printf("¿Õ\n");
	}
	else
	{
		printf("²»¿Õ\n");
	}*/
	//clearstring(&st);
	//printf("%d\n", sizestring(&st));
	//if (stringEmpty(&st))
	//{
	//	printf("¿Õ\n");
	//}
	//else
	//{
	//	printf("²»¿Õ\n");
	//}
	//strcopy(&st, t);
	printf("%s\n", strstr(&st, t));
	//printf("%s", st.s);
}
int main()
{
	test();
	return 0;
}