//BOJ 1987. 알파벳

#include<stdio.h>

int R, C;
char board[22][22];
int isVisted[100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int MX;

void Recursion(int x, int y,int cnt)
{
	if (cnt > MX)MX = cnt;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || nx > R || ny <= 0 || ny > C)continue;
		if (isVisted[board[nx][ny]] == 1)continue;

		isVisted[board[nx][ny]] = 1;
		Recursion(nx, ny,cnt+1);
		isVisted[board[nx][ny]] = 0;
	}
	return;
}

int main(void)
{
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf(" %c", &board[i][j]);
		}
	}
	isVisted[board[1][1]] = 1;
	Recursion(1,1,1);
	
	printf("%d\n", MX);
	return 0;
}
