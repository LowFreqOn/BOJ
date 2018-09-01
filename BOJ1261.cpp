//BOJ. 1261. 알고스팟

#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

char map[102][102];
int isVisited[102][102];
int wall_cnt[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int M, N;

int main(void)
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", &map[i]);
	}

	queue<pair<int, int> >Q;
	Q.push({ 0,0 });
	isVisited[0][0] = 1;
	queue<pair<int, int> >Q2;

	while (!Q.empty())
	{
		int cur_x = Q.front().first;
		int cur_y = Q.front().second;
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur_x + dx[dir];
			int ny = cur_y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (isVisited[nx][ny] == 1)continue;
			if (map[nx][ny] == '0')
			{
				Q.push({ nx,ny });
				wall_cnt[nx][ny] = wall_cnt[cur_x][cur_y];
				isVisited[nx][ny] = 1;
			}
			else if (map[nx][ny] == '1')
			{
				Q2.push({ nx,ny });
				wall_cnt[nx][ny] = wall_cnt[cur_x][cur_y] + 1;
				isVisited[nx][ny] = 1;
			}
		}
		if (Q.empty())
		{
			Q = Q2;
			Q2 = queue<pair<int, int>>();
		}

	}
	printf("%d\n", wall_cnt[N - 1][M - 1]);
	return 0;
}
