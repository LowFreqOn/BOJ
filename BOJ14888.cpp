//BOJ 14888 연산자 끼워넣기

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>

int N;
int num_arr[15];
int oper[4];
long long minn = 1000000000;
long long maxx = -1000000000;

void dfs(long long prev, long long next,int depth, int op)
{
	if (op == 0)
	{
		prev = prev + next;
	}
	else if (op == 1)
	{
		prev = prev - next;
	}
	else if (op == 2)
	{
		prev = prev * next;
	}
	else if (op == 3)
	{
		prev = prev / next;
	}
	//printf("prev:%d\n", prev);
	if (depth+1 == N)
	{
		if (prev > maxx)maxx = prev;
		if (prev < minn)minn = prev;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] == 0)continue;
		oper[i]--;
		dfs(prev, num_arr[depth+1], depth+1, i);
		oper[i]++;
	}
	return;
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num_arr[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &oper[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] == 0)continue;
		oper[i]--;
		dfs(num_arr[0], num_arr[1], 1, i);
		oper[i]++;
	}
	printf("%lld\n%lld\n", maxx, minn);

	return 0;
}
