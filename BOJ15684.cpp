//BOJ.15684.사다리 조작

#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

int N, M, H;
int ladder[32][12];
int ans = -1;
bool state = false;
vector<pair<int, int> >a;
int MN = -1;

bool finish_test()
{
	for (int i = 1; i <= N; i++)
	{
		int cur_x = 1;
		int cur_y = i;
		while (cur_x!=(H+1))
		{
			if (ladder[cur_x][cur_y] == 1)
			{
				cur_y = cur_y + 1;
				cur_x = cur_x + 1;
			}
			else if (ladder[cur_x][cur_y] == -1)
			{
				cur_y = cur_y - 1;
				cur_x = cur_x + 1;
			}
			else
				cur_x++;
		}
		if (cur_y != i)
		{
			//printf("cur_y:%d i:%d\n", cur_y, i);
			return false;
		}
	}
	return true;
}

int Recursion(int depth,int lastidx)
{
	if (MN != -1 && MN <= depth)return -1;
	if (depth <= 3)
	{
		if (finish_test())
		{
			MN = depth;
			return depth;
		}
	}
	else if (depth > 3)return -1;

	int len = a.size();
	for (int i = lastidx+1; i < len; i++)
	{
		int a_x = a[i].first;
		int a_y = a[i].second;
		if (ladder[a_x][a_y] == 0 && ladder[a_x][a_y + 1] == 0)
		{
			ladder[a_x][a_y] = 1;
			ladder[a_x][a_y + 1] = -1;
			Recursion(depth + 1,i);
			ladder[a_x][a_y] = 0;
			ladder[a_x][a_y + 1] = 0;
		}
	}
	return 0;
}

int main(void)
{
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 1; i <= M; i++)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		ladder[x][y] = 1;
		ladder[x][y + 1] = -1;
	}
	
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (ladder[i][j] == 0)
			{
				a.push_back(make_pair(i, j));
			}
		}
	}
	Recursion(0,-1);
	if (MN == 999)MN = -1;
	printf("%d\n",MN);
	return 0;
}
