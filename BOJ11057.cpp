//BOJ 11057. 오르막 수

#include<stdio.h>

long long dp[1001][10];
int N;

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = dp[i][j] + dp[i - 1][k];
			}
			dp[i][j] = dp[i][j] % (long long)10007;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans = ans + dp[N][i];
	}
	ans = ans % 10007;
	printf("%lld\n",ans);
	return 0;
}
