//BOJ 14501. 퇴사

#include<stdio.h>
#include<stdlib.h>

int N;
int T_arr[17];
int P_arr[17];
int MX;


void dfs(int idx,int cur_sum)
{
	if (idx>N)
	{
		if (cur_sum > MX)MX = cur_sum;
		return;
	}

	else
	{
		for (int i = idx; i <= N+1; i++)
		{
			if (i + T_arr[i] <= N+1)
			{
				//printf("i:%d P_arr[i]:%d\n", i, P_arr[i]);
				//printf("*cur_sum:%d\n", cur_sum);
				cur_sum = cur_sum + P_arr[i];
				//printf("**cur_sum:%d\n", cur_sum);
				dfs(i + T_arr[i], cur_sum);
				cur_sum = cur_sum - P_arr[i];
			}
			else
				dfs(i + T_arr[i], cur_sum);
		}
		return;
	}
	
}


int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &T_arr[i], &P_arr[i]);
	}


	dfs(1,0);
	printf("%d\n", MX);

	return 0;
}
