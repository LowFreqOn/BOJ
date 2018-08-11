// BOJ. 2133. 타일 채우기

#include<stdio.h>

int N;
int dp[35];

int main(void)
{
	scanf("%d", &N);
	dp[2] = 3;
	dp[4] = 11;
	for (int i = 6; i < 31; i = i+2)
	{
		for (int j = i-2; j > 0; j = j-2)
		{
			dp[i] = dp[i] + 2 * dp[j];
		}
		dp[i] = dp[i] + dp[i - 2] +2;
	}
	printf("%d\n", dp[N]);
	return 0;

}
