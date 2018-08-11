//BOJ. 1182. 부분집합의 합.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int N, S;
int arr[22];
int cur;
int cnt;

void dfs(int lastdisx)
{
	for (int i = lastdisx + 1; i < N; i++)
	{
		cur = cur + arr[i];
		//printf("cur:%d\n", cur);
		if (cur == S)cnt++;
		dfs(i);
		cur = cur - arr[i];
	}
	return;
}

int main(void)
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	dfs(-1);
	printf("%d\n", cnt);
	

	return 0;
}
