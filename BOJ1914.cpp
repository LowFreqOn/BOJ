#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int K;

int calc(int K,int cur_level, string cur)
{
	if (K-1 == cur_level)
	{
		int end_num = cur.back() - '0';
		cur.pop_back();
		end_num = end_num - 1;
		cur.push_back((end_num + '0'));
		cout << cur << "\n";
		return 0;
	}

	string temp_cur = "";
	int sum = 0;
	//cout << "cur:"<<cur << "\n";
	while (!cur.empty() || sum!=0)
	{
		if ((cur.back() - '0') >= 0)
		{
			sum = 2 * (cur.back() - '0') + sum;
			
			temp_cur.push_back((sum % 10) + '0');
			
			cur.pop_back();
		}
		else
			temp_cur.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(temp_cur.begin(), temp_cur.end());
	calc(K, cur_level + 1, temp_cur);

}

long long cnt(int K)
{
	if (K == 1)
	{
		return 1;
	}
	return 1 + 2 * cnt(K - 1);
}

void hanoi(int start, int mid, int end, int level)
{
	if (level == 1)
	{
		printf("%d %d\n", start, end);
		return;
	}
	hanoi(start, end, mid, level - 1);
	printf("%d %d\n", start, end);
	hanoi(mid, start, end, level - 1);
	return;
}

int main(void)
{
	scanf("%d", &K);
	if (K > 20)
	{
		calc(K, 0, "2");
	}
	else
	{

		printf("%d\n", cnt(K));
		hanoi(1, 2, 3, K);
	}
	return 0;
}
