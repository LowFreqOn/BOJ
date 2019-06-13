//BOJ2293.동전1
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> V;
vector<int> V2;
int a[103];
int n, k;

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    V.resize(k + 1);
    V2.resize(k + 1);

    for (int i = 0; i <= k; i = i + a[0])
    {
        V[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        fill(V2.begin(), V2.end(), 0);
        for (int j = 0; j <= k; j++)
        {
            V2[j] = V[j];
            if (j >= a[i])
            {
                V2[j] = V2[j] + V2[j - a[i]];
            }
        }

        for (int l = 1; l <= k; l++)
        {
            V[l] = V2[l];
        }
    }
    cout << V[k] << '\n';
    return 0;
}
