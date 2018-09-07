//BOJ.14891.톱니바퀴

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;
int wheel[4][8];
int connect_state[3];
int K;

int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &wheel[i][j]);
		}
	}
	scanf("%d", &K);
	for (int op = 1; op <= K; op++)
	{
		int start = 0;
		int dir = 0;//-1:반시계 1:시계
		scanf("%d %d", &start, &dir);
		start = start - 1;
		fill(connect_state, connect_state + 3, 0);
		connect_state[0] = wheel[0][2] ^ wheel[1][6];
		connect_state[1] = wheel[1][2] ^ wheel[2][6];
		connect_state[2] = wheel[2][2] ^ wheel[3][6];
		if (start == 0)
		{
			if (connect_state[0] == 1)
			{
				if (connect_state[1] == 1)
				{
					if (connect_state[2] == 1)
					{
						int dir_4 = -1 * dir;
						if (dir_4 == 1)
						{
							int temp = wheel[3][7];
							for (int i = 6; i >= 0; i--)
							{
								wheel[3][i + 1] = wheel[3][i];
							}
							wheel[3][0] = temp;
						}
						else
						{
							int temp = wheel[3][0];
							for (int i = 0; i < 7; i++)
							{
								wheel[3][i] = wheel[3][i + 1];
							}
							wheel[3][7] = temp;
						}
					}
					int dir_3 = dir;
					if (dir_3 == 1)
					{
						int temp = wheel[2][7];
						for (int i = 6; i >= 0; i--)
						{
							wheel[2][i + 1] = wheel[2][i];
						}
						wheel[2][0] = temp;
					}
					else
					{
						int temp = wheel[2][0];
						for (int i = 0; i < 7; i++)
						{
							wheel[2][i] = wheel[2][i + 1];
						}
						wheel[2][7] = temp;
					}

				}
				int dir_2 = dir * -1;
				if (dir_2 == 1)
				{
					int temp = wheel[1][7];
					for (int i = 6; i >= 0; i--)
					{
						wheel[1][i + 1] = wheel[1][i];
					}
					wheel[1][0] = temp;
				}
				else
				{
					int temp = wheel[1][0];
					for (int i = 0; i < 7; i++)
					{
						wheel[1][i] = wheel[1][i + 1];
					}
					wheel[1][7] = temp;
				}

			}
			if (dir == 1)
			{
				int temp = wheel[0][7];
				for (int i = 6; i >= 0; i--)
				{
					wheel[0][i + 1] = wheel[0][i];
				}
				wheel[0][0] = temp;
			}
			else
			{
				int temp = wheel[0][0];
				for (int i = 0; i < 7; i++)
				{
					wheel[0][i] = wheel[0][i + 1];
				}
				wheel[0][7] = temp;
			}
		}

		else if (start == 1)
		{
			if (connect_state[1] == 1)
			{
				if (connect_state[2] == 1)
				{
					int dir_4 = dir;
					if (dir_4 == 1)
					{
						int temp = wheel[3][7];
						for (int i = 6; i >= 0; i--)
						{
							wheel[3][i + 1] = wheel[3][i];
						}
						wheel[3][0] = temp;
					}
					else
					{
						int temp = wheel[3][0];
						for (int i = 0; i < 7; i++)
						{
							wheel[3][i] = wheel[3][i + 1];
						}
						wheel[3][7] = temp;
					}
				}
				int dir_3 = dir * -1;
				if (dir_3 == 1)
				{
					int temp = wheel[2][7];
					for (int i = 6; i >= 0; i--)
					{
						wheel[2][i + 1] = wheel[2][i];
					}
					wheel[2][0] = temp;
				}
				else
				{
					int temp = wheel[2][0];
					for (int i = 0; i < 7; i++)
					{
						wheel[2][i] = wheel[2][i + 1];
					}
					wheel[2][7] = temp;
				}

			}
			if (connect_state[0] == 1)
			{
				int dir_1 = dir * -1;
				if (dir_1 == 1)
				{
					int temp = wheel[0][7];
					for (int i = 6; i >= 0; i--)
					{
						wheel[0][i + 1] = wheel[0][i];
					}
					wheel[0][0] = temp;
				}
				else
				{
					int temp = wheel[0][0];
					for (int i = 0; i < 7; i++)
					{
						wheel[0][i] = wheel[0][i + 1];
					}
					wheel[0][7] = temp;
				}
			}
			if (dir == 1)
			{
				int temp = wheel[1][7];
				for (int i = 6; i >= 0; i--)
				{
					wheel[1][i + 1] = wheel[1][i];
				}
				wheel[1][0] = temp;
			}
			else
			{
				int temp = wheel[1][0];
				for (int i = 0; i < 7; i++)
				{
					wheel[1][i] = wheel[1][i + 1];
				}
				wheel[1][7] = temp;
			}
		}

		else if (start == 2)
		{
			if (connect_state[1] == 1)
			{
				if (connect_state[0] == 1)
				{
					int dir_1 = dir;
					if (dir_1 == 1)
					{
						int temp = wheel[0][7];
						for (int i = 6; i >= 0; i--)
						{
							wheel[0][i + 1] = wheel[0][i];
						}
						wheel[0][0] = temp;
					}
					else
					{
						int temp = wheel[0][0];
						for (int i = 0; i < 7; i++)
						{
							wheel[0][i] = wheel[0][i + 1];
						}
						wheel[0][7] = temp;
					}
				}
				int dir_2 = dir * -1;
				if (dir_2 == 1)
				{
					int temp = wheel[1][7];
					for (int i = 6; i >= 0; i--)
					{
						wheel[1][i + 1] = wheel[1][i];
					}
					wheel[1][0] = temp;
				}
				else
				{
					int temp = wheel[1][0];
					for (int i = 0; i < 7; i++)
					{
						wheel[1][i] = wheel[1][i + 1];
					}
					wheel[1][7] = temp;
				}

			}
			if (connect_state[2] == 1)
			{
				int dir_4 = dir * -1;
				if (dir_4 == 1)
				{
					int temp = wheel[3][7];
					for (int i = 6; i >= 0; i--)
					{
						wheel[3][i + 1] = wheel[3][i];
					}
					wheel[3][0] = temp;

				}
				else
				{

					int temp = wheel[3][0];
					for (int i = 0; i < 7; i++)
					{
						wheel[3][i] = wheel[3][i + 1];
					}
					wheel[3][7] = temp;
				}

			}
			if (dir == 1)
			{
				int temp = wheel[2][7];
				for (int i = 6; i >= 0; i--)
				{
					wheel[2][i + 1] = wheel[2][i];
				}
				wheel[2][0] = temp;
			}
			else
			{
				int temp = wheel[2][0];
				for (int i = 0; i < 7; i++)
				{
					wheel[2][i] = wheel[2][i + 1];
				}
				wheel[2][7] = temp;
			}
		}
		else if (start == 3)
		{
			if (connect_state[2] == 1)
			{
				if (connect_state[1] == 1)
				{
					if (connect_state[0] == 1)
					{
						int dir_1 = -1 * dir;
						if (dir_1 == 1)
						{
							int temp = wheel[0][7];
							for (int i = 6; i >=0; i--)
							{
								wheel[0][i + 1] = wheel[0][i];
							}
							wheel[0][0] = temp;
						}
						else
						{
							int temp = wheel[0][0];
							for (int i = 0; i < 7; i++)
							{
								wheel[0][i] = wheel[0][i + 1];
							}
							wheel[0][7] = temp;
						}
					}
					int dir_2 = dir;
					if (dir_2 == 1)
					{
						int temp = wheel[1][7];
						for (int i = 6; i >= 0; i--)
						{
							wheel[1][i + 1] = wheel[1][i];
						}
						wheel[1][0] = temp;
					}
					else
					{
						int temp = wheel[1][0];
						for (int i = 0; i < 7; i++)
						{
							wheel[1][i] = wheel[1][i + 1];
						}
						wheel[1][7] = temp;
					}

				}
				int dir_3 = dir * -1;
				if (dir_3 == 1)
				{
					int temp = wheel[2][7];
					for (int i = 6; i >= 0; i--)
					{
						wheel[2][i + 1] = wheel[2][i];
					}
					wheel[2][0] = temp;
				}
				else
				{
					int temp = wheel[2][0];
					for (int i = 0; i < 7; i++)
					{
						wheel[2][i] = wheel[2][i + 1];
					}
					wheel[2][7] = temp;
				}

			}
			if (dir == 1)
			{
				int temp = wheel[3][7];
				for (int i = 6; i >= 0; i--)
				{
					wheel[3][i + 1] = wheel[3][i];
				}
				wheel[3][0] = temp;
			}
			else
			{
				int temp = wheel[3][0];
				for (int i = 0; i < 7; i++)
				{
					wheel[3][i] = wheel[3][i + 1];
				}
				wheel[3][7] = temp;
			}
		}
	}
	int ans = 0;
	if (wheel[0][0] == 1)ans = ans + 1;
	if (wheel[1][0] == 1)ans = ans + 2;
	if (wheel[2][0] == 1)ans = ans + 4;
	if (wheel[3][0] == 1)ans = ans + 8;
	printf("%d\n", ans);

	return 0;
}
