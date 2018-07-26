// BOJ 10974. 모든 순열

#include<stdio.h>
#include<algorithm>

using namespace std;

int N;
int isVisited[10];
int arr_print[10];

void DFS(int depth,int N)
{
	if (depth == N)
	{
		for (int i = 1; i <= N; i++)
		{
			printf("%d ", arr_print[i]);
		}
		printf("\n");

		return;
	}
	for (int j = 1; j <= N; j++)
	{
		if (isVisited[j] == 1)continue;
			arr_print[depth + 1] = j;
			isVisited[j] = 1;
			DFS(depth + 1, N);
			isVisited[j] = 0;
			arr_print[depth + 1] = 0;
	}
	return;
}

int main(void)
{

	scanf("%d", &N);
	DFS(0, N);
	return 0;
}
