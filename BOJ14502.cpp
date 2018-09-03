//BOJ.14502.연구소

#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int N, M;
int map[9][9];
int map_calc[9][9];
//int isVisited[9][9];
int ans;
int empt[2][65];
int permut_arr[65] = { 1,1,1, };
int virus[2][12];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main(void)
{
	scanf("%d %d", &N, &M);
	int empt_cnt = 0;
	int virus_cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			//if (map[i][j] == 1 || map[i][j] == 2)isVisited[i][j] = 1;
			if (map[i][j] == 2)
			{
				virus[0][virus_cnt] = i;
				virus[1][virus_cnt] = j;
				virus_cnt++;
			}
			if (map[i][j] == 0)
			{
				empt[0][empt_cnt] = i;
				empt[1][empt_cnt] = j;
				empt_cnt++;
			}
		}
	}
	do
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map_calc[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < empt_cnt; i++)
		{
			if (permut_arr[i] == 1)
			{
				map_calc[empt[0][i]][empt[1][i]] = 1;
			}
		}

		queue<pair<int, int> >Q;
		for (int i = 0; i < virus_cnt; i++)
		{
			Q.push(make_pair(virus[0][i], virus[1][i]));
		}
		while (!Q.empty())
		{
			int now_x = Q.front().first;
			int now_y = Q.front().second;
			Q.pop();

			for (int dir =0; dir < 4; dir++)
			{
				int nx = now_x + dx[dir];
				int ny = now_y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
				if (map_calc[nx][ny] == 1 || map_calc[nx][ny] == 2)continue;
				//if (isVisited[nx][ny] == 1)continue;
				map_calc[nx][ny] = 2;
				Q.push(make_pair(nx, ny));
				//isVisited[nx][ny] = 1;

			}
		}
		int zero_cnt = 0;
		//printf("\n");

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				//printf("%d ", map_calc[i][j]);
				if (map_calc[i][j] == 0)zero_cnt++;
			}
			//printf("\n");
		}
		if (zero_cnt > ans)ans = zero_cnt;
	} while (prev_permutation(permut_arr, permut_arr + empt_cnt));
	printf("%d\n", ans);
	return 0;
}
