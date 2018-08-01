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

/* <다른 사람 풀이>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>


using namespace std;

int n, k;
int p[100002];
queue<int> q;


int ntok(void) 
{
	fill(p, p + k + 2, -1);

	q.push(n);
	p[n] = n;

	int lv = 0;
	while (!q.empty()) 
	{
		int sz = q.size();
		for (int i = 0; i < sz; i++) 
		{
			int curr = q.front();
			q.pop();

			if (curr == k)
				return lv;

			if (curr < k && p[curr + 1] == -1) 
			{
				p[curr + 1] = curr;
				q.push(curr + 1);
			}
			if (curr > 0 && p[curr - 1] == -1) {
				p[curr - 1] = curr;
				q.push(curr - 1);
			}
			if (2 * curr <= k + 1 && p[2 * curr] == -1) {
				p[2 * curr] = curr;
				q.push(2 * curr);
			}
		}
		lv++;
	}
	return -1;
}


int main(void) {
	scanf("%d %d", &n, &k);

	if (k <= n) {
		printf("%d\n", n - k);
		for (int i = n; i >= k; i--)
			printf("%d ", i);
	}
	else {
		printf("%d\n", ntok());

		vector<int> path;
		while (k != n) {
			path.push_back(k);
			k = p[k];
		}
		printf("%d ", n);
		for (int i = path.size() - 1; i >= 0; i--)
			printf("%d ", path[i]);
	}

	return 0;
}
*/
