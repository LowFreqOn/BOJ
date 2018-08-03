//BOJ 2580 sdoku

#include<stdio.h>

int row_visited[100][10];
int col_visited[100][10];
int square_visited[100][10];
int unoccupied[2][100];
int board[10][10];
int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,1,1,0,-1,-1,-1,0,1 };
int cnt;
int test_case;

void dfs(int depth)
{
	if (depth == cnt)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		if (row_visited[unoccupied[0][depth]][i] == 1)continue;
		if (col_visited[unoccupied[1][depth]][i] == 1)continue;
		if (square_visited[(unoccupied[0][depth]/3)*3 + unoccupied[1][depth]/3][i] == 1) continue;
		board[unoccupied[0][depth]][unoccupied[1][depth]] = i;
		row_visited[unoccupied[0][depth]][i] = 1;
		col_visited[unoccupied[1][depth]][i] = 1;
		square_visited[(unoccupied[0][depth] / 3) * 3 + unoccupied[1][depth] / 3][i] = 1;
		dfs(depth + 1);
		board[unoccupied[0][depth]][unoccupied[1][depth]] = 0;
		row_visited[unoccupied[0][depth]][i] = 0;
		col_visited[unoccupied[1][depth]][i] = 0;
		square_visited[(unoccupied[0][depth] / 3) * 3 + unoccupied[1][depth] / 3][i] = 0;
	}
	return;
}

int main(void)
{

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				scanf("%d", &board[i][j]);
				if (board[i][j] == 0)
				{
					unoccupied[0][cnt] = i;
					unoccupied[1][cnt] = j;
					cnt++;
				}
				//else
				//{
				//	row_visited[i][board[i][j]] = 1;
				//}
			}
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j]!=0)row_visited[i][board[i][j]] = 1;
			}
		}
		for (int j = 0; j < 9; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				if (board[i][j])col_visited[j][board[i][j]] = 1;
			}
		}

		for (int i = 1; i < 9; i = i + 3)
		{
			for (int j = 1; j < 9; j = j + 3)
			{
				for (int dir = 0; dir < 9; dir++)
				{
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (board[nx][ny])square_visited[(i/3)*3 + j/3][board[nx][ny]] = 1;
				}
			}
		}

		dfs(0);
	
	return 0;
}
