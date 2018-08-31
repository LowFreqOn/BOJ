//BOJ 9019. DSLR

#include<stdio.h>
#include<algorithm>
#include<string>
#include<queue>
#include<string>
#include<iostream>
using namespace std;

int test_case;
int from[10003];
char method[10003];

int main(void)
{
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++)
	{
		//init
		fill(from, from + 10000, -1);
		fill(method, method + 10000, NULL);

		int input = 0;
		int output = 0;
		scanf("%d %d", &input, &output);
		queue<pair<int,int> >Q;
		Q.push(make_pair(input, -1));

		while (Q.front().first!=output)
		{
			int cur_num = Q.front().first;
			int cur_num_from = Q.front().second;
			Q.pop();

			//D
			int cur_D = (cur_num * 2)%10000;
			if (from[cur_D] == -1)
			{
				from[cur_D] = cur_num;
				method[cur_D] = 'D';
				Q.push(make_pair(cur_D, cur_num));
			}
			//S
			int cur_S = cur_num - 1;
			if (cur_S == -1)cur_S = 9999;
			if (from[cur_S] == -1)
			{
				from[cur_S] = cur_num;
				method[cur_S] = 'S';
				Q.push(make_pair(cur_S, cur_num));
			}

			//L
			int cur_L = (cur_num % 1000) * 10 + (cur_num / 1000);
			if (from[cur_L] == -1)
			{
				from[cur_L] = cur_num;
				method[cur_L] = 'L';
				Q.push(make_pair(cur_L, cur_num));
			}
			//R

			int cur_R = (cur_num % 10) * 1000 + (cur_num / 10);
			if (from[cur_R] == -1)
			{
				from[cur_R] = cur_num;
				method[cur_R] = 'R';
				Q.push(make_pair(cur_R, cur_num));
			}
		}
		while (!Q.empty())
		{
			Q.pop();
		}
		int i = output;
		char ans[10000] = {};
		int cnt = 0;
		while (i!=input)
		{
			ans[cnt++] = method[i];
			i = from[i];
		}
		reverse(ans, ans + cnt);
		printf("%s", ans);
		printf("\n");
	}
	return 0;
}
