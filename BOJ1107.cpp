//BOJ 1107.리모컨

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>	

using namespace std;

int goal, M;
int broken[12];
int cur_min = 100000000;
int cur_min_num = 100000000;

int broken_check(int a)
{
	if (a == 0)
	{
		if (broken[0] == 1)return -1;
		else return 1;
	}
	while (a != 0)
	{
		int rest = a % 10;
		for (int i = 0; i < 10; i++)
			if (broken[rest] == 1) return -1;
		a = a / 10;
	}
	return 1;
}

int main(void)
{
	scanf("%d", &goal);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int n;
		scanf("%d", &n);
		broken[n] = 1;
	}

	//abs(goal-i)가 최소가 되는 지점 + 자리수
	
	for (int i = 0; i <= 1000000; i++)
	{
		if (broken_check(i) == 1)
		{
			if (abs(goal - i) < cur_min)
			{
				cur_min = abs(goal - i);
				cur_min_num = i;
			}
		}
	}

	//digit 구하는 과정
	int digit_cnt = 0;
	if (cur_min_num == 0)digit_cnt = 1;

	while (cur_min_num != 0)
	{
		cur_min_num = cur_min_num / 10;
		digit_cnt++;
	}
	//printf("cur_min:%d digit_cnt:%d\n", cur_min,digit_cnt);

	int ans = cur_min + digit_cnt;
	ans = min(abs(goal - 100), ans);

	printf("%d\n", ans);
	return 0;
}

/* 다른 
#include <cstdio>

int min(int a,int b) { return a<b?a:b; }
int abs(int n) { return n>0?n:-n; }

int main()
{
	int n,m,t,cnt;
	scanf("%d %d",&n,&m);
	int ans=abs(n-100);
	bool b[10],flag; for(int i=0;i<10;i++) b[i]=true;
	while(m--) scanf("%d",&t),b[t]=false;
	for(int i=n;i<=1000000;i++)
	{
		flag=true,cnt=0,t=i;
		while(true)
		{
			if(!b[t%10]) { flag=false; break; }
			t/=10,cnt++;
			if(t==0) break;
		}
		if(flag) { ans=min(ans,cnt+i-n); break; }
	}
	for(int i=n;i>=0;i--)
	{
		flag=true,cnt=0,t=i;
		while(true)
		{
			if(!b[t%10]) { flag=false; break; }
			t/=10,cnt++;
			if(t==0) break;
		}
		if(flag) { ans=min(ans,cnt+n-i); break; }
	}
	printf("%d\n",ans);
	return 0;
}
*/
