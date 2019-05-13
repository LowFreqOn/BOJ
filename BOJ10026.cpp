#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

char map[100][100];
bool normal[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt, cnt2;
queue< pair<int, int> > Q;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;
	for(int i = 0;i<N;i++)
	{
		cin>>map[i];
	}


	//정상 찾기

	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			if(normal[i][j] == true)continue;
			Q.push(make_pair(i,j));
			normal[i][j] = true;
			while(!Q.empty())
			{
				int cur_x = Q.front().first;
				int cur_y = Q.front().second;
				char cur_state = map[cur_x][cur_y];


				Q.pop();

				for(int dir = 0;dir<4;dir++)
				{
					int nx = cur_x + dx[dir];
					int ny = cur_y + dy[dir];
					if(nx<0 || ny <0 || nx>=N || ny>=N)continue;
					if(normal[nx][ny] == true)continue;
					if(map[nx][ny] == cur_state)
					{
						Q.push(make_pair(nx,ny));
						normal[nx][ny] = true;
					}
				}
			}
			cnt++;
		}
	}
	cout<<cnt <<" ";
	//////////////////////////////////////////////////////////////////////////
	for(int i = 0;i<N;i++)
		for(int j = 0;j<N;j++) normal[i][j] = false;
	//////////////////////////////////////////////////////////////////////////
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			if(normal[i][j] == true)continue;
			Q.push(make_pair(i,j));
			normal[i][j] = true;
			while(!Q.empty())
			{
				int cur_x = Q.front().first;
				int cur_y = Q.front().second;
				char cur_state = map[cur_x][cur_y];


				Q.pop();

				for(int dir = 0;dir<4;dir++)
				{
					int nx = cur_x + dx[dir];
					int ny = cur_y + dy[dir];
					if(nx<0 || ny <0 || nx>=N || ny>=N)continue;
					if(normal[nx][ny] == true)continue;
					if(((cur_state == 'R') || (cur_state == 'G')) && ((map[nx][ny] == 'R') || (map[nx][ny] == 'G')))
					{
						Q.push(make_pair(nx,ny));
						normal[nx][ny] = true;
					}
					else if((cur_state == 'B') && (map[nx][ny] == 'B'))
					{
						Q.push(make_pair(nx,ny));
						normal[nx][ny] = true;
					}
				}
			}
			cnt2++;
		}
	}


	cout<<cnt2;
	return 0;
}
