//BOJ 10971. 외판원 순회 2

#include<stdio.h>

int city[12][12];
int N;
int min = 1000000*11;
int isVisited[12];
int cur_sum = 0;

void dfs(int depth, int cur_loc, int start_loc)
{
	if (depth == N - 1 && city[cur_loc][start_loc] != 0)//		if (city[cur_loc][i] != 0) 
	{
		cur_sum = cur_sum + city[cur_loc][start_loc];
		if (cur_sum < min)min = cur_sum;
		//printf("*******depth:%d cur_loc:%d cur_sum:%d\n", depth, cur_loc, cur_sum);
		cur_sum = cur_sum - city[cur_loc][start_loc];
		return;
	}


	for (int i = 0; i < N; i++)
	{
		if (isVisited[i] != 0)continue;
		if (city[cur_loc][i] != 0)
		{
			isVisited[i] = 1;
			cur_sum = cur_sum + city[cur_loc][i];
			//printf("++depth:%d cur_loc:%d i:%d cur_sum:%d\n", depth, cur_loc, i, cur_sum);
			dfs(depth + 1, i, start_loc);
			//printf("00depth:%d cur_loc:%d i:%d cur_sum:%d\n", depth, cur_loc, i, cur_sum);

			cur_sum = cur_sum - city[cur_loc][i];
			isVisited[i] = 0;
			//printf("--depth:%d cur_loc:%d i:%d cur_sum:%d\n", depth, cur_loc, i, cur_sum);
		}
	}
	return;
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &city[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		isVisited[i] = 1;
		dfs(0, i, i);
		isVisited[i] = 0;
	}
	printf("%d\n", min);
	return 0;
}
