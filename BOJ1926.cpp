#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, MX, area_cnt;
int map[502][502];
bool check[502][502];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue< pair<int,pair<int, int> > >Q;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check[i][j] == true || map[i][j] == 0)continue;
			area_cnt++;
			int level = 1;
			Q.push(make_pair(1,make_pair(i, j)));
			check[i][j] = true;
			while (!Q.empty())
			{
				int cl = Q.front().first;
				//if (cl > MX)MX = cl;
				int cx = Q.front().second.first;
				int cy = Q.front().second.second;
				if (level > MX)MX = level;
				Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cx + dx[dir];
					int ny = cy + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
					if (check[nx][ny] == true || map[nx][ny] == 0)continue;
					check[nx][ny] = true;
					level++;
					Q.push({ cl + 1,{nx,ny} });
				}

			}
		}
	}
	cout << area_cnt << " " << MX;
	return 0;
}
