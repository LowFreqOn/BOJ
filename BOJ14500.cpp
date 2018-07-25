//BOJ 14500. 테트로미노

#include<stdio.h>

int board[502][502];
int isVisited[502][502];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dk_1[4][2] = { {-1,0},{0,1},{1,0},{ 0,-1 } };

int max = 0;
int cur_sum;
int N, M;

void DFS(int depth, int cur_x, int cur_y)
{
	if (depth == 3)
	{
		if (cur_sum > max)max = cur_sum;
		return;
	}
	for (int dir = 0; dir < 4; dir++)
	{
		int new_x = cur_x + dx[dir];
		int new_y = cur_y + dy[dir];
		if (new_x <= 0 || new_x > N || new_y <= 0 || new_y > M)continue;
		if (isVisited[new_x][new_y] == 1)continue;
		cur_sum = cur_sum + board[new_x][new_y];
		isVisited[new_x][new_y] = 1;
		DFS(depth + 1, new_x, new_y);
		cur_sum = cur_sum - board[new_x][new_y];
		isVisited[new_x][new_y] = 0;
	}

	return;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cur_sum = board[i][j];
			isVisited[i][j] = 1;
			DFS(0, i, j);
			isVisited[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cur_sum = board[i][j];// +board[i + 1][j] + board[i][j + 1] + board[i - 1][j] + board[i][j - 1];
			for (int dir = 0; dir < 4; dir++)
			{
				cur_sum = cur_sum + board[i + dx[dir]][j + dy[dir]];
			}

			for (int k = 0; k < 4; k++)
			{
				cur_sum = cur_sum - board[i + dx[k]][j + dy[k]];
				if (cur_sum > max)max = cur_sum;
				cur_sum = cur_sum + board[i + dx[k]][j + dy[k]];

			}

		}
	}
	
	printf("%d\n", max);
	

	return 0;
}
