//BOJ 15685. 드래곤 커브

#include<stdio.h>
#include<stdlib.h>

int curve_chart[1200];
int N;
int data[22][4];
int board[101][101];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	//curve_chart만들기
	for (int i = 0; i < 10; i++)
	{
		for (int j = (1 << i); j < (1 << i + 1); j++)
		{
			curve_chart[j] = (curve_chart[(1 << (i + 1)) - 1 - j] + 1) % 4;
		}
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &data[i][0], &data[i][1], &data[i][2], &data[i][3]);
		board[data[i][0]][data[i][1]] = 1;
		int nx = data[i][1];
		int ny = data[i][0];
		for (int j = 0; j < (1 << data[i][3]); j++)
		{
			nx = nx + dx[(data[i][2] + curve_chart[j]) % 4];
			ny = ny + dy[(data[i][2] + curve_chart[j]) % 4];
			board[ny][nx] = 1;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1)cnt++;
		}
	}
	printf("%d\n", cnt);


	return 0;
}
