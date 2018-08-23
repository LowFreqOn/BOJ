//BOJ 6064.카잉달력
#include<stdio.h>

int test_case;
int M, N, x, y;

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);
		int cnt = 0;
		int ans = 0;
		if (M < N)
		{
			int temp = M;
			M = N;
			N = temp;
			temp = x;
			x = y;
			y = temp;
		}
		while (1)
		{
			int check_num = M * cnt + x;
			if (M == x)x = 0;
			if (N == y)y = 0;
			if (check_num%M == x && check_num%N == y)
			{
				ans = check_num;
				break;
			}
			//else if (check_num == M*N)
			//{
			//	ans = check_num;
			//	break;
			//}
			if (check_num > M*N)
			{
				ans = -1;
				break;
			}
			cnt++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
