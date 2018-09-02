//BOJ 13398. 연속합2

#include<stdio.h>
#include<algorithm>
using namespace std;

int dpl[100003] = { -9999, };
int dpr[100003];
int input[100003];
int N;
int MX = -99999;
int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &input[i]);
		dpl[i] = max(dpl[i - 1] + input[i], input[i]);
	}
	dpr[N + 1] = -9999;
	for (int j = N; j > 0; j--)
	{
		dpr[j] = max(dpr[j + 1] + input[j], input[j]);
	}

	dpl[0] = 0;
	dpr[N + 1] = 0;
	if (N == 1)
	{
		MX = dpl[1];
	}
	else
	{
		for (int k = 1; k <= N; k++)
		{
			int a = max(dpl[k - 1] + dpr[k + 1],dpl[k]);
			if (a > MX)MX = a;
		}
	}
	printf("%d\n", MX);
	return 0;
}
