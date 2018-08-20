// BOJ 11719. 그대로 출력하기2

#include<stdio.h>
#include<stdlib.h>

char a[101];

int main(void)
{
	while (fgets(a,101,stdin))
	{
		fputs(a, stdout);
	}
	return 0;
}


/*
#include<stdio.h>

int a;

int main(void)
{
	while (1)
	{
		a = getchar();
		if (a == EOF) break;
		putchar(a);
	}
	

	return 0;
}
*/
