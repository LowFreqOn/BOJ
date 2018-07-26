// BOJ 2529. 부등호

#include<stdio.h>

char arr[12];
int isVisited[12];
long long N,cur_num;
long long min_num = 9999999999;
long long max_num = 0;

int inequal_check(int a, int b, char c)
{
	if (c == '>')
	{
		if (a > b) return 1;
		else return 0;
	}
	else if(c == '<')
	{
		if (a > b) return 0;
		else return 1;
	}
}

int DFS(int depth, long long N, long long cur_num,long long prev_num)
{
	if (depth == N+1)
	{
		if (cur_num > max_num)max_num = cur_num;
		if (cur_num < min_num)min_num = cur_num;
		return 0;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (inequal_check(prev_num,i,arr[depth-1]) && isVisited[i]!=1)
		{
			isVisited[i] = 1;
			cur_num = cur_num * 10 + i;
			//printf("depth:%d prev:%d next:%d cur_num:%d\n",depth, prev_num, i, cur_num);
			DFS(depth + 1, N, cur_num, i);
			isVisited[i] = 0;
			cur_num = (cur_num - i) / 10;
		}
		
	}
	return 0;
}

void digit_check(long long aa)
{
	long long digit = 0;
	long long a = aa;
	if (a == 0)
	{
		digit = 1;
		printf("0\n");
		return;
	}

	while (a != 0)
	{
		a /= 10;
		digit++;
	}
	//printf("digit:%d\n", digit);
	if (N + 1 == digit)
	{
		printf("%lld\n", aa);
		return;
	}
	else
	{
		printf("0%lld\n", aa);
		return;
	}
}

int main(void)
{
	scanf("%lld", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%*c%c", &arr[i]);
	}

	for (int i = 0; i <= 9; i++)
	{
		isVisited[i] = 1;
		DFS(1, N, i, i);
		isVisited[i] = 0;
	}
	
	//printf("%d\n%d\n", max_num, min_num);
	digit_check(max_num);
	digit_check(min_num);
	return 0;
}
