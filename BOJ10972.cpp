// BOJ 10972. 다음 순열

#include<stdio.h>
#include<algorithm>

using namespace std;

int N;
int arr[10002];

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	bool state = 0;
	for (int j = N; j > 0; j--)
	{
		if (arr[j] < arr[j - 1] || j-1==0)continue;
		else
		{
			int cmp_num = arr[j - 1];
			for (int k = N; k >= j; k--)
			{
				if (cmp_num < arr[k])
				{
					arr[j - 1] = arr[k];
					arr[k] = cmp_num;
					state = 1;
					break;
				}
			}
			sort(arr+j ,arr+N+1);
			break;
		}
	}
	if(state)	for (int i = 1; i <= N; i++)printf("%d ", arr[i]);
	else printf("%d", -1);
	return 0;
}
