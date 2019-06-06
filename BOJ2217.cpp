//BOJ2217 로프
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
int arr[100005];
int mx;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] * (n - i) > mx)mx = arr[i] * (n - i);
	}
	cout << mx;
	return 0;
}
