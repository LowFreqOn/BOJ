// BOJ 1339. 단어수학

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

typedef struct Word
{
	char word[10];
	int len;
}Word;

char word_arr[100][10];
int word_visited[100];
long long alphabet_sum[100];
int N, max_len;
Word input[12];

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", input[i].word);
		input[i].len = strlen(input[i].word);
		if (input[i].len > max_len)max_len = input[i].len;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = input[i].len - 1; j >= 0; j--)
		{
			word_arr[input[i].word[j]][(input[i].len-1)-j] += 1;
			word_visited[input[i].word[j]] = 1;
		}
	}
	int word_num = 0;
	for (int i = 65; i < 92; i++)
	{
		word_num = word_num + word_visited[i];
	}
	//여기까지 의도한 대로 되었음.

	for (int i = 0; i < 100; i++)
	{
		for (int j = max_len-1; j >=0 ; j--)
		{
			alphabet_sum[i] = word_arr[i][j] + alphabet_sum[i] * 10;
		}
	}

	
	sort(alphabet_sum, alphabet_sum + 100, greater<int>());
	//for (int i = 0; i < 26; i++)
	//{
	//	printf("sum:%d\n", alphabet_sum[i]);
	//}
	long long ans = 0;
	int number = 9;
	for (int i = 0; i <word_num; i++)
	{
		ans = ans + alphabet_sum[i] * number;
		number--;
	}


	printf("%d\n", ans);
	return 0;
}
