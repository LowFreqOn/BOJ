//BOJ.14503.로봇 청소기
#include<stdio.h>
#include<algorithm>
using namespace std;

int N, M;
int map[52][52];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int robot_loc[3];
int main(void)
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &robot_loc[0], &robot_loc[1], &robot_loc[2]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	map[robot_loc[0]][robot_loc[1]] = 2;

	int state = 1;

	while (state)
	{
		int left_dir = (robot_loc[2] + 3) % 4;
		int left_x = robot_loc[0] + dx[left_dir];
		int left_y = robot_loc[1] + dy[left_dir];

		int dir_1 = (robot_loc[2] + 0) % 4;
		int dir_2 = (robot_loc[2] + 1) % 4;
		int dir_3 = (robot_loc[2] + 2) % 4;
		int dir_4 = (robot_loc[2] + 3) % 4;
		if ((map[robot_loc[0] + dx[dir_1]][robot_loc[1] + dy[dir_1]] == 2 || map[robot_loc[0] + dx[dir_1]][robot_loc[1] + dy[dir_1]] == 1) && (map[robot_loc[0] + dx[dir_2]][robot_loc[1] + dy[dir_2]] == 2 || map[robot_loc[0] + dx[dir_2]][robot_loc[1] + dy[dir_2]] == 1) && (map[robot_loc[0] + dx[dir_3]][robot_loc[1] + dy[dir_3]] == 2 || map[robot_loc[0] + dx[dir_3]][robot_loc[1] + dy[dir_3]] == 1) && (map[robot_loc[0] + dx[dir_4]][robot_loc[1] + dy[dir_4]] == 2 || map[robot_loc[0] + dx[dir_4]][robot_loc[1] + dy[dir_4]] == 1))
		{
			int back_x = robot_loc[0] + dx[dir_3];
			int back_y = robot_loc[1] + dy[dir_3];
			if (map[back_x][back_y] != 1)
			{
				robot_loc[0] = back_x;
				robot_loc[1] = back_y;
				continue;
			}
			else if (map[back_x][back_y] == 1) state = 0;
		}

		if (left_x >= 0 && left_y >= 0 && left_x < N && left_y < M)
		{
			if (map[left_x][left_y] == 0)
			{

				robot_loc[2] = left_dir;
				robot_loc[0] = left_x;
				robot_loc[1] = left_y;
				map[left_x][left_y] = 2;

				continue;
			}
			else if (map[left_x][left_y] != 0)
			{
				robot_loc[2] = left_dir;
				continue;
			}

		}

	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2)ans++;
		}
	}
	printf("%d\n", ans);
	return 0;

}
