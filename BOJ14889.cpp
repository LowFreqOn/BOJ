// BOJ 14889 스타트와 링크

#include<stdio.h>
#include<stdlib.h>

int N;
int synergy[22][22];
int isVisited[22];
int syn_gap = 1000000;
int A_sum;
int B_sum;

void dfs_sum(void)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)continue;
			if (isVisited[i] == 1 && isVisited[j] == 1)
				A_sum = A_sum + synergy[i][j];
			if (isVisited[i] == 0 && isVisited[j] == 0)
				B_sum = B_sum + synergy[i][j];
		}
	}
	return;
}

void dfs(int prev,int next, int syn_sum, int depth)
{
	if (depth == N / 2)
	{
		dfs_sum();
		if (abs(A_sum - B_sum) < syn_gap)syn_gap = abs(A_sum - B_sum);
		A_sum = 0;
		B_sum = 0;
		return;
	}
	for (int i = next; i <= N; i++)
	{
		if (next == i)continue;
		isVisited[i] = 1;
		dfs(next, i, syn_sum, depth + 1);
		isVisited[i] = 0;
	}
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &synergy[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		isVisited[i] = 1;
		dfs(0,i,0, 1);
		isVisited[i] = 0;
	}
	printf("%d\n", syn_gap);
	return 0;
}
