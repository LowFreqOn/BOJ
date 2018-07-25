//BOJ 1476. 날짜 계산

#include<stdio.h>
#include<stdlib.h>

int E, S, M;
int cnt;
int main(void)
{
	scanf("%d %d %d", &E, &S, &M);
	while (1)
	{
		cnt++;
		int a = cnt % 15;
		int b = cnt % 28;
		int c = cnt % 19;
		if (a == 0)a = 15;
		if (b == 0)b = 28;
		if (c == 0)c = 19;
		if (a == E && b == S && c == M)
			break;
	}
	printf("%d\n",cnt);
	return 0;
}
