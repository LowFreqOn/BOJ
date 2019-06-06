//BOJ 1931.회의실 배정문제
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
pair<int, int> s[100005];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].second >> s[i].first;
	}
	sort(s, s + n);

	int cur_term = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (cur_term <= s[i].second)
		{
			cur_term = s[i].first;
			ans++;
		}
		else continue;
	}
	cout << ans;

	return 0;
}
