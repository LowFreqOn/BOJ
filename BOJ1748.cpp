// BOJ. 1748 수 이어 쓰기1

#include<stdio.h>

int N;

int main(void)
{
	scanf("%d", &N);
	int a = N;
	int sum = 0;
	int div = 10;
	int digit_cnt = 1;
	while (1)
	{
		if (a >= div)
		{
			sum = sum + 9*(div/10)*digit_cnt;
			div *= 10;
			digit_cnt++;
		}
		else
		{
			sum = sum + digit_cnt * (a -div/10+1);
			break;
		}
	}
	printf("%d\n", sum);
	return 0;
}

/* 무식한 풀이
// BOJ. 1748 수 이어 쓰기1

#include<stdio.h>

int N;

int main(void)
{
	scanf("%d", &N);
	int cnt = 0;
	while (N != 0)
	{
		int digit_cnt = 0;
		int a = N;
		while (a != 0)
		{
			a = a / 10;
			digit_cnt++;
		}
		cnt = cnt + digit_cnt;
		N--;
	}
	printf("%d\n", cnt);
	return 0;
}





*/
