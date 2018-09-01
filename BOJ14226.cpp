//BOJ. 14226.이모티콘

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;


int S;
int depth[1002][1002];

int main(void)
{
	scanf("%d", &S);
	queue<pair<int, int> >Q;
	Q.push(make_pair(1, 0));
	depth[1][0] = 1;

	while (Q.front().first != S)
	{
		int now = Q.front().first;
		int now_clip = Q.front().second;
		Q.pop();

		//첫 번째 연산
		int next_1 = now;
		int next_clip_1 = now;
		if (depth[next_1][next_clip_1] == 0)
		{
			depth[next_1][next_clip_1] = depth[now][now_clip] + 1;
			Q.push({ next_1,next_clip_1 });
		}
		//두 번쨰 연산
		int next_2 = now + now_clip;
		int next_clip_2 = now_clip;
		if (next_2 <= 1000 && depth[next_2][next_clip_2] == 0)
		{
			depth[next_2][next_clip_2] = depth[now][now_clip] + 1;
			Q.push({ next_2,next_clip_2 });
		}
		//세 번째 연산
		int next_3 = now - 1;
		int next_clip_3 = now_clip;
		if (next_3 >= 0 && depth[next_3][next_clip_3] == 0)
		{
			depth[next_3][next_clip_3] = depth[now][now_clip] + 1;
			Q.push({ next_3,next_clip_3 });
		}
	}

	int ans = 9999;
	for (int i = 0; i < 1001; i++)
	{
		if (depth[S][i] != 0)
		{
			if (depth[S][i] < ans)ans = depth[S][i];
		}
	}
	printf("%d\n", ans - 1);
	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		printf("%d ", depth[i][j]);
	//	}
	//	printf("\n");
	//}
	return 0;
}
