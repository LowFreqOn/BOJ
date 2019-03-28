#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int local[4][10002];
int ICE[302][302];
int temp_ICE[302][302];
int visited[302][302];
int N, M,year,plevel,idx;
int total_ice_num;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue <pair<int, int> > Q;

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &ICE[i][j]);


			if (ICE[i][j] != 0)
			{
				local[0][idx] = i;
				local[1][idx] = j;
				local[2][idx] = 1;
				local[3][idx] = ICE[i][j];
				idx++;
				total_ice_num++;
			}
		}
	}

	while (1)
	{
		for (int i = 0; i < idx; i++)
		{
			visited[local[0][i]][local[1][i]] = 0;
			if (local[2][i] == 0)continue;
			int cur_x = local[0][i];
			int cur_y = local[1][i];
			int ocean_cnt = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				if (cur_x + dx[dir] < 0 || cur_x + dx[dir] >= N || cur_y + dy[dir] < 0 || cur_y + dy[dir] >= M)continue;
				if (ICE[cur_x + dx[dir]][cur_y + dy[dir]] == 0)
					ocean_cnt++;
			}
			if (ocean_cnt < local[3][i])local[3][i] = local[3][i] - ocean_cnt;
			else
			{
				local[3][i] = 0;
				local[2][i] = 0;
				total_ice_num--;
			}
		}

	
		year++;

		for (int j = 0; j < idx; j++)
		{
			ICE[local[0][j]][local[1][j]] = local[3][j];
		}

		//printf("*********************\n");
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < M; j++)
		//	{
		//		printf("%d ", ICE[i][j]);
		//	}
		//	printf("\n");
		//}
		//printf("************************\n");

		//printf("total_ice:%d\n", total_ice_num);

		for (int k = 0; k < idx; k++)
		{
			int total_cnt = 0;
			if (local[2][k] == 0)continue;
			else if (ICE[local[0][k]][local[1][k]] != 0)
			{
				Q.push({ local[0][k],local[1][k] });
				visited[local[0][k]][local[1][k]] = 1;
				total_cnt++;
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						if (ICE[cur.first + dx[dir]][cur.second + dy[dir]] != 0 && visited[cur.first + dx[dir]][cur.second+ dy[dir]]!=1)
						{
							visited[cur.first + dx[dir]][cur.second + dy[dir]] = 1;
							Q.push({ cur.first + dx[dir] ,cur.second + dy[dir] });
							total_cnt++;
						}
					}

				}
				
			}

			//printf("total_cnt:%d\n", total_cnt);
			if (total_cnt == total_ice_num)break;
			if (total_cnt != total_ice_num)
			{
				printf("%d\n", year);
				return 0;
			}
		}
		if (total_ice_num == 0)
		{
			printf("0\n");
			return 0;
		}

	}

	return 0;
}

/* 비교적 깔끔했던 다른 풀이

#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Point {
	int x, y;
};

queue<Point> q;
vector<Point> v;
bool visited[310][310] = { 0, };
int graph[310][310] = { 0, };
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
int n, m, year = 0, totalGlacier = 0;

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] != 0) v.push_back({ j , i });
		}
	}
	
	totalGlacier = v.size();
	
	while (true) {
		// Search a first node for bfs
		for (int i = 0; i < v.size(); i++) {
			if (graph[v[i].y][v[i].x] > 0) {
				q.push(v[i]); visited[v[i].y][v[i].x] = true;
				break;
			}
		}

		// Start bfs
		int cnt = 0, numOfMeltedIce = 0;
		while (!q.empty()) {
			Point cur = q.front(); q.pop();
			int numOfWater = 0;
			cnt++;

			for (int i = 0; i < 4; i++) {
				Point next = { cur.x + dx[i], cur.y + dy[i] };

				if (!visited[next.y][next.x] && graph[next.y][next.x] <= 0) numOfWater++;
				if (!visited[next.y][next.x] && graph[next.y][next.x] > 0) {
					q.push({ next.x, next.y });
					visited[next.y][next.x] = true;
				}
			}
			graph[cur.y][cur.x] -= numOfWater;

			if (graph[cur.y][cur.x] <= 0) numOfMeltedIce++;
		}
		memset(visited, 0, sizeof(visited));
		year++;
		
		if (cnt != totalGlacier) {
			printf("%d", year - 1);
			return 0;
		}
		
		totalGlacier -= numOfMeltedIce;

		if (totalGlacier == 0) {
			printf("0");
			return 0;
		}
	}
}

*/
