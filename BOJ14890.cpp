//BOJ.14890.경사로

#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

int map[102][102];
int occupied[102];
int N, L;
int row[102];
int col[102];

int main(void)
{
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		bool state = true;
		memset(occupied, 0, sizeof(occupied));
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] != map[i][j + 1])
			{
				if (j+1<N && map[i][j] > map[i][j + 1])
				{
					if ((j + L) >= N)
					{
						state = false;
						//printf("1**\n");
						//printf("j:%d map[i][j]:%d map[i][j+1]:%d\n",j, map[i][j], map[i][j + 1]);

						break;
					}
					for (int k = 1; k <= L; k++)
					{
						if ((map[i][j] - map[i][j + k]) != 1)
						{
							state = false;
							//printf("2\n");

							break;
						}
					}
					if (state == false)break;

					if (state)
					{
						for (int k = 1; k <= L; k++)
						{
							occupied[j + k] = 1;
						}
					}
				}
				else if (map[i][j] < map[i][j + 1])
				{
					if (j +1 - L < 0)
					{
						state = false;
						//printf("4\n");

						break;
					}
					for (int k = 1; k <= L; k++)
					{
						if (occupied[j+1-k]==1 || (map[i][j+1] - map[i][j+1 - k]) != 1)
						{
							state = false;
							//printf("5\n");
							//printf("map[i][j]:%d map[i][j-k]:%d\n", map[i][j], map[i][j-k]);


							break;
						}
					}
					if (state == false) break;
					if (state)
					{
						for (int k = 1; k <= L; k++)
						{
							occupied[j - k] = 1;
						}
					}
				}
			}
		}
		if (state == true)row[i] = 1;
	}

	for (int j = 0; j < N; j++)
	{
		bool state = true;
		memset(occupied, 0, sizeof(occupied));
		for (int i = 0; i < N; i++)
		{
			if (map[i][j] != map[i+1][j])
			{
				if (i + 1<N && map[i][j] > map[i+1][j])
				{
					if ((i + L) >= N)
					{
						state = false;
						//printf("1\n");
						//printf("j:%d map[i][j]:%d map[i][j+1]:%d\n", j, map[i][j], map[i][j + 1]);

						break;
					}
					for (int k = 1; k <= L; k++)
					{
						if ((map[i][j] - map[i+k][j]) != 1)
						{
							state = false;
							//printf("2\n");

							break;
						}
					}
					if (state == false)break;

					if (state)
					{
						for (int k = 1; k <= L; k++)
						{
							occupied[i + k] = 1;
						}
					}
				}
				else if (map[i][j] < map[i+1][j])
				{
					if (i+1 - L < 0)
					{
						state = false;
						//printf("4\n");

						break;
					}
					for (int k = 1; k <= L; k++)
					{
						if (occupied[i + 1 - k] == 1 || (map[i+1][j] - map[i+1-k][j]) != 1)
						{
							state = false;
							//printf("5\n");
							//printf("map[i][j]:%d map[i][j-k]:%d\n", map[i][j], map[i][j - k]);


							break;
						}
					}
					if (state == false) break;
					if (state)
					{
						for (int k = 1; k <= L; k++)
						{
							occupied[i - k] = 1;
						}
					}
				}
			}
		}
		if (state == true)col[j] = 1;
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		//printf("%d ", row[i]);
		if (row[i] == 1)ans = ans + row[i];
	}
	//printf("\n");
	for (int i = 0; i < N; i++)
	{
		//printf("%d ", col[i]);
		if (col[i] == 1)ans = ans + col[i];
	}
	printf("%d\n", ans);

	return 0;

}
