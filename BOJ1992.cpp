#include<iostream>
#include<string>
using namespace std;

int N;
char map[70][70];

void recursion(int N, int pos_x, int pos_y)
{
	/*if(N == 2)
	{
	for(int i = 0;i<2;i++)
	for(int j = 0;j<2;j++)
	cout<<map[pos_x +i][pos_y + j];
	return;
	}*/
	//if(N==1)
	//{
	//	cout<<map[pos_x][pos_y];
	//	return;
	//}

	bool flag = true;
	char init_char = map[pos_x + 0][pos_y +0];
	for(int i =  0;i<N/2;i++)
	{
		for(int j = 0;j<N/2;j++)
		{
			if(map[pos_x +i][pos_y + j]!=init_char)
			{
				flag = false;
					cout<<'(';
				recursion(N/2, pos_x + 0,pos_y + 0);
				cout<<')';
				break;
			}
		}
		if(!flag)break;
	}
	if(flag)
		cout<<init_char;

	flag = true;
	init_char = map[pos_x + 0][pos_y + N/2];
	for(int i = 0;i<N/2;i++)
	{
		for(int j = N/2;j<N;j++)
		{
			if(map[pos_x +i][pos_y + j]!=init_char)
			{
				flag = false;
					cout<<'(';
				recursion(N/2, pos_x + 0,pos_y + N/2);
				cout<<')';
				break;
			}
		}
		if(!flag)break;
	}
	if(flag)
		cout<<init_char;

	flag = true;
	init_char = map[pos_x + N/2][pos_y + 0];
	for(int i = N/2;i<N;i++)
	{
		for(int j = 0;j<N/2;j++)
		{
			if(map[pos_x +i][pos_y + j]!=init_char)
			{
				flag = false;
					cout<<'(';
				recursion(N/2, pos_x + N/2,pos_y + 0);
				cout<<')';
				break;
			}
		}
		if(!flag)break;
	}
	if(flag)
		cout<<init_char;

	flag = true;
	init_char = map[pos_x + N/2][pos_y + N/2];
	for(int i = N/2;i<N;i++)
	{
		for(int j = N/2;j<N;j++)
		{
			if(map[pos_x +i][pos_y + j]!=init_char)
			{
				flag = false;
					cout<<'(';
				recursion(N/2, pos_x + N/2, pos_y + N/2);
				cout<<')';
				break;
			}
		}
		if(!flag)break;
	}
	if(flag)
		cout<<init_char;
	return;		 
}

int main(void)
{
	cin>>N;
	for(int i =0;i<N;i++)
	{
		cin>>map[i];
	}
	bool flag = true;
	char in = map[0][0];
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			if(map[i][j] != in)
			{
				flag = false;
				cout<<'(';
				recursion(N,0,0);
				cout<<')';
				break;
			}

		}
					if(!flag)break;
	}
	if(flag)cout<<in<<'\n';
	return 0;
}

