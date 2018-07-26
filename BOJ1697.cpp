// BOJ 1697. 숨바꼭질

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int N, K;
int cnt;
int ans;
int isVisited[100002];

int main(void)
{
	scanf("%d %d", &N, &K);
	queue<pair<int,int> >Q;
	Q.push(make_pair(N,0));
	isVisited[0] = 1;

	while (1)
	{
		if (Q.front().first == K)
		{
			ans = Q.front().second;
			break;
		}
		int cur_loc = Q.front().first;
		int cur_cnt = Q.front().second;
		Q.pop();
		if(cur_loc>K)
		{
			Q.push(make_pair(cur_loc - 1, cur_cnt + 1));
			isVisited[cur_loc - 1] = 1;

		}
		else
		{
			if (cur_loc + 1 <= 100000 && isVisited[cur_loc + 1] != 1)
			{
				Q.push(make_pair(cur_loc + 1, cur_cnt + 1));
				isVisited[cur_loc + 1] = 1;
			}
			if (cur_loc - 1 >= 0 && isVisited[cur_loc - 1] != 1)
			{
				Q.push(make_pair(cur_loc - 1, cur_cnt + 1));
				isVisited[cur_loc - 1] = 1;
			}
			if (2 * cur_loc <= 100000 && isVisited[2 * cur_loc] != 1)
			{
				Q.push(make_pair(2 * cur_loc, cur_cnt + 1));
				isVisited[2 * cur_loc] = 1;
			}
		}

	}
	printf("%d\n", ans);
	return 0;
}
