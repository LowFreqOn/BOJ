// BOJ 13913. 숨바꼭질 4

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int N, K;
int isVisited[100003][2];
int ans_arr[100003];
queue< pair<int, int> >Q;

int main(void)
{
	scanf("%d %d", &N, &K);
	Q.push(make_pair(0, N));
	isVisited[N][0] = 100001; 
	isVisited[N][1] = 1;
	int cur_loc = Q.front().second;
	while (Q.front().second != K)
	{
		cur_loc = Q.front().second;
		Q.pop();

		if (cur_loc - 1 >= 0 &&  isVisited[cur_loc - 1][1] == 0)
		{
			Q.push(make_pair(cur_loc, cur_loc - 1));
			isVisited[cur_loc - 1][0] = cur_loc;
			isVisited[cur_loc - 1][1] = 1;
		}
		if (cur_loc + 1 <= 100000 && isVisited[cur_loc + 1][1] == 0)
		{
			Q.push(make_pair(cur_loc, cur_loc + 1));
			isVisited[cur_loc + 1][0] = cur_loc;
			isVisited[cur_loc + 1][1] = 1;
		}
		if (cur_loc * 2 <= 100000 && isVisited[2 * cur_loc][1] == 0)
		{
			Q.push(make_pair(cur_loc, 2 * cur_loc));
			isVisited[2 * cur_loc][0] = cur_loc;
			isVisited[2 * cur_loc][1] = 1;
		}
	}


	int cnt = 0;
	int cur = K;
	int before = isVisited[cur][0];
	ans_arr[0] = cur;
	while (before != 100001)
	{
		cur = before;
		before = isVisited[cur][0];
		cnt++;
		ans_arr[cnt] = cur;
		//printf("cur:%d before:%d cnt:%d ans:%d\n", cur, before, cnt, ans_arr[cnt]);
	}
	printf("%d\n", cnt);
	for (int i = cnt; i >= 0; i--)
	{
		printf("%d ", ans_arr[i]);
	}
	return 0;
}
