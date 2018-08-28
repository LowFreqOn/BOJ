//BOJ. 10844. 쉬운 계단수

#include<stdio.h>

long long dp[102][102];
int input;

int main(void)
{
	scanf("%d", &input);
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= input; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(j>=1 && j<10)
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			else if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)dp[i][j] = dp[i - 1][j - 1];
			dp[i][j] = dp[i][j] % (long long)1000000000;
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans = ans + dp[input][i];
	}
	ans = ans % (long long)1000000000;
	printf("%lld\n", ans);
	return 0;
}
