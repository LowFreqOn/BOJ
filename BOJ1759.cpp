//BOJ 1759. 암호 만들기

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;

int L, C;
char arr[17];
int isVisited[17];

int cons(void)
{
	int cnt = 0;
	for (int i = 0; i < C; i++)
	{
		if (isVisited[i] == 1 && ((arr[i] != 'a') && (arr[i] != 'i') && (arr[i] != 'u') && (arr[i] != 'e') && (arr[i] != 'o')))
		{
			cnt++;
		}
		if (cnt == 2)
		{
			return 1;
		}
	}
	return 0;
}

int vow(void)
{
	int cnt = 0;
	for (int i = 0; i < C; i++)
	{
		if (isVisited[i] == 1 && ((arr[i] == 'a') || (arr[i] == 'i') || (arr[i] == 'u') || (arr[i] == 'e') || (arr[i] == 'o')))
		{
			cnt++;
		}
	}
	if (cnt>= 1)return 1;
	else return 0;
}


void Recursion(int depth, int lastidx)
{
	if (depth == L)
	{
		//printf("cons:%d vow:%d\n", cons(), vow());
		if (cons() && vow()) 
		{
			for (int i = 0; i < C; i++)
			{
				//printf("*%d ", isVisited[i]);
				if (isVisited[i])printf("%c", arr[i]);
			}
			printf("\n");
			return;
		}
	}
	for (int i = lastidx+1; i < C; i++)
	{
		isVisited[i] = 1;
		Recursion(depth + 1, i);
		isVisited[i] = 0;
	}
	return;
}

int main(void)
{
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++)
	{
		scanf(" %c", &arr[i]);
	}
	sort(arr, arr + C);
	Recursion(0, -1);

	return 0;
}

/* < 빠른 풀이>

char crypt[16],t;
char print[16];
int i,j,L,C;
f(i,c)
{
if(c==L)
{
int vowel=0,consonant=0;
for(i=0;i<L;i++)
{
if(print[i]=='a'||print[i]=='e'||print[i]=='i'||print[i]=='o'||print[i]=='u')vowel++;
else consonant++;
}
if(vowel>0&&consonant>1)puts(print);
return;
}
for(;i<C;i++)
{
if(crypt[i])
{
print[c]=crypt[i];
f(i+1,c+1);
}
}
}
main()
{
for(scanf("%d%d",&L,&C);i<C;i++)scanf(" %c",crypt+i);
for(i=0;i<C;i++)for(j=i;j>0;j--)if(crypt[j]<crypt[j-1]){t=crypt[j-1];crypt[j-1]=crypt[j];crypt[j]=t;}
f(0,0);
}
*/
