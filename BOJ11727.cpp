//BOJ. 11727 2×n 타일링 2 
#include<stdio.h>

int dp[1002];
int input;

int main(void)
{
	dp[1] = 1;
	dp[2] = 3;
	scanf("%d", &input);
	for (int i = 3; i <= input; i++)
	{
		dp[i] = dp[i - 2] * 2 + dp[i - 1];
		dp[i] = dp[i] % 10007;
	}
	printf("%d\n", dp[input]);
	return 0;
}
