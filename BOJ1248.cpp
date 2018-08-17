//BOJ 1248. 맞춰봐

#include<stdio.h>

int N;
char sign_board[12][12];
int N_arr[12];
bool state = false;

char sign_check_func(int sum)
{
	if (sum > 0)return '+';
	else if (sum < 0)return'-';
	else return '0';
}


int validation_check(int depth)
{
	int cur_sum = 0;
	for (int i = depth; i <= N; i++)
	{
		cur_sum = cur_sum + N_arr[i];
		if (sign_check_func(cur_sum) != sign_board[depth][i])return -1;
	}
	return 1;
}

void Recursion(int depth)
{
	if (depth == 0)
	{
		state = true;
		for (int i = 1; i <= N; i++)
		{
			printf("%d ", N_arr[i]);
		}
		printf("\n");
		return;
	}


	if (sign_board[depth][depth] == '+')
	{
		for (int i = 1; i < 11; i++)
		{
			N_arr[depth] = i;
			if (validation_check(depth) == -1)continue;
			else if(validation_check(depth))Recursion(depth - 1);
			if (state == true)return;
		}
	}
	else if (sign_board[depth][depth] == '-')
	{
		for (int i = -10; i < 0; i++)
		{
			N_arr[depth] = i;
			if (validation_check(depth) == -1)continue;
			else if (validation_check(depth))Recursion(depth - 1);
			if (state == true)return;
		}
	}
	else
	{
		N_arr[depth] = 0;
		Recursion(depth - 1);
		if (state == true)return;
	}
}

int main(void)
{
	scanf("%d", &N);
	for (int row = 1; row <= N; row++)
	{
		for (int col = row; col <= N; col++)
		{
			scanf(" %c", &sign_board[row][col]);
		}
	}
	Recursion(N);

	return 0;
}
