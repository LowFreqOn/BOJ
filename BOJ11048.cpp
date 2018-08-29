// BOJ. 11048. 이동하기

#include<stdio.h>
#include<algorithm>

using namespace std;

int N, M;
int dp[1002][1002];
int candy[1002][1002];

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &candy[i][j]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + candy[i][j];
		}
	}
	printf("%d\n", dp[N][M]);

	return 0;
}
