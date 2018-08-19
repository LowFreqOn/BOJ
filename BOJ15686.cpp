// BOJ 15686. 치킨배달

#include<stdio.h>
#include<algorithm>
#include<functional>
#include<stdlib.h>
#include<string>
#include<string.h>

using namespace std;

int N, M;
int map[52][52];
int house[2][100];
int chicken_house[2][13];
int chicken_permut[15];
int chicken_length_chart[100][13];
int final_min = 99999999;
int main(void)
{
	scanf("%d %d", &N, &M);
	int house_cnt = 0;
	int chicken_cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				house[0][house_cnt] = i;
				house[1][house_cnt] = j;
				house_cnt++;
			}
			else if (map[i][j] == 2)
			{
				chicken_house[0][chicken_cnt] = i;
				chicken_house[1][chicken_cnt] = j;
				chicken_cnt++;

			}
		}
	}
	//chicken_length_chart 만들기
	for (int i = 0; i < house_cnt; i++)
	{
		for (int j = 0; j < chicken_cnt; j++)
		{
			chicken_length_chart[i][j] = abs(house[0][i] - chicken_house[0][j]) + abs(house[1][i] - chicken_house[1][j]);
		}
	}

	fill(chicken_permut, chicken_permut + chicken_cnt, 1);
	for (int i = 0; i < chicken_cnt - M; i++)
	{
		chicken_permut[i] = 0;
	}
	do
	{
		int min_arr[100] = {};
		fill(min_arr, min_arr + house_cnt, 99999999);
		for (int i = 0; i < house_cnt; i++)
		{
			for (int j = 0; j < chicken_cnt; j++)
			{
				if (chicken_permut[j] == 0)continue;
				if (chicken_length_chart[i][j] < min_arr[i])min_arr[i] = chicken_length_chart[i][j];
			}
		}
		int sum = 0;
		for (int i = 0; i < house_cnt; i++)
		{
			sum = sum + min_arr[i];
		}
		if (sum < final_min)final_min = sum;
	} while (next_permutation(chicken_permut, chicken_permut + chicken_cnt));

	printf("%d\n", final_min);
	return 0;
}
