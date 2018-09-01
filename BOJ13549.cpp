//BOJ. 13549. 숨바꼭질 3

#include<stdio.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<string.h>

using namespace std;

int isVisited[100002];
int N, K;

int main(void)
{
	memset(isVisited, -1, sizeof(isVisited));
	scanf("%d %d", &N, &K);
	isVisited[N] = 0;

	queue<int>Q1,Q2;
	Q1.push(N);
	bool state = false;
	while (!state)
	{
		while (!Q1.empty())
		{
			int now = Q1.front();
			if (state)break;
			if (Q1.front() == K)
			{
				state = true;
				break;
			}
			Q1.pop();
			if (2 * now <= 100000 && isVisited[2*now]==-1)
			{
				Q1.push(2 * now);
				isVisited[2 * now] = isVisited[now];
			}
			if (now - 1 >= 0 && isVisited[now-1] == -1)
			{
				Q2.push(now - 1);
				isVisited[now - 1] = isVisited[now] + 1;
			}
			if (now + 1 <= 100000 && isVisited[now+1] == -1)
			{
				Q2.push(now + 1);
				isVisited[now + 1] = isVisited[now] + 1;
			}
		}

		while (!Q2.empty())
		{
			int now = Q2.front();
			if (state)break;
			if (Q2.front() == K)
			{
				state = true;
				break;
			}
			Q2.pop();
			if (2 * now <= 100000 && isVisited[2 * now] == -1)
			{
				Q2.push(2 * now);
				isVisited[2 * now] = isVisited[now];
			}
			if (now - 1 >= 0 && isVisited[now - 1] == -1)
			{
				Q1.push(now - 1);
				isVisited[now - 1] = isVisited[now] + 1;
			}
			if (now + 1 <= 100000 && isVisited[now + 1] == -1)
			{
				Q1.push(now + 1);
				isVisited[now + 1] = isVisited[now] + 1;
			}
		}
	}
	printf("%d\n", isVisited[K]);
	return 0;

}
