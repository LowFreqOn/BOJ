//BOJ 1463. 1로 만들기

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int dp[1000002];

int main(void)
{
	dp[2] = 1;
	dp[3] = 1;
	int input = 0;
	scanf("%d", &input);

	for (int i = 4; i <= input; i++)
	{
		int temp1 = 99999;
		int temp2 = 99999;
		int temp3 = 99999;
		if (i % 2 == 0)
		{
			temp1 = dp[i / 2] + 1;
		}
		if (i % 3 == 0)
		{
			temp2 = dp[i / 3] + 1;
		}
		if (i > 3)
		{
			temp3 = dp[i - 1] + 1;
		}
		dp[i] = min(min(temp1, temp2), temp3);
	}
	printf("%d\n", dp[input]);
	return 0;
}

/*  <Top-down 방식>
#include <iostream>
using namespace std;
int d[1000001];
int go(int n) {
    if (n == 1) {
        return 0;
    }
    if (d[n] > 0) {
        return d[n];
    }
    d[n] = go(n-1) + 1;
    if (n%2 == 0) {
        int temp = go(n/2) + 1;
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    if (n%3 == 0) {
        int temp = go(n/3) + 1;
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    return d[n];
}
int main() {
    int n;
    cin >> n;
    cout << go(n) << '\n';
    return 0;
}*/
