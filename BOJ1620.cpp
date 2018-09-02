//BOJ 1620. 나는야 포켓몬 마스터 이다솜

#include<iostream>
#include<map>
#include<string>

using namespace std;

string table[100003];
int N, M;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	map<string, int>MAP;
	for (int i = 1; i <= N; i++)
	{
		string name;
		cin >> name;
		MAP[name] = i;
		table[i] = name;
	}

	for (int j = 0; j<M; j++)
	{
		string a;
		cin >> a;
		if (a[0]>'0' && a[0] <= '9')
		{
			cout << table[atoi(a.c_str())] << '\n';
		}
		else
		{
			cout << MAP[a] << '\n';
		}
	}
	return 0;

}
