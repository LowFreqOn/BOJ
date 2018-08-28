//BOJ. 11052. 붕어빵 판매하기

#include<stdio.h>

int dp[1002];
int P[1002];
int N;

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &P[i]);
	}
	dp[1] = P[1];
	for (int i = 2; i <= N; i++)
	{
		int MX = 0;
		for (int j = 1; j <= i; j++)
		{
			dp[i] = dp[i - j] + P[j];
			if (dp[i] > MX)MX = dp[i];
		}
		dp[i] = MX;
	}
	printf("%d\n", dp[N]);
	return 0;
}
