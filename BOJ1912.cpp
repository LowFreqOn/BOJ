//BOJ.1912.연속합

#include<stdio.h>
#include<algorithm>
using namespace std;

int d[100002] = {-99999, };
int N;
int MX = -99999;

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int a = 0;
		scanf("%d", &a);
		d[i] = max(d[i - 1] + a, a);
		if (d[i] > MX)MX = d[i];
	}
	printf("%d\n", MX);
	return 0;
}
