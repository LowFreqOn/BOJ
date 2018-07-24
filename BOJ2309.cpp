//BOJ 2309. 일곱 난쟁이 스페셜 저지

#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[9];
int ans_arr[7];
int sum;
bool state = 0;

int ki_check(int *arr, int last_idx, int depth)
{
	if (sum > 100)return 0;
	if (sum == 100 && depth == 7)
	{
		state = 1;
		sort(ans_arr, ans_arr + 7);
		for (int i = 0; i < 7; i++)
		{
			printf("%d\n", ans_arr[i]);
		}
		return 0;
	}
	if (depth >= 7)return 0;

	for (int i = last_idx + 1; i < 9; i++)
	{
		sum = sum + arr[i];
		ans_arr[depth] = arr[i];
		//printf("sum:%d i:%d depth:%d\n", sum,i, depth);

		ki_check(arr, i, depth + 1);
		if (state == 1) return 0;
		sum = sum - arr[i];
		ans_arr[depth] = 0;
	}
	return 0;
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
	}

	ki_check(arr, -1, 0);

	return 0;
}
