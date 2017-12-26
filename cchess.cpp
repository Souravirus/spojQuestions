#include<bits/stdc++.h>
using namespace std;

int arra[9][9];
int arrcheck[9][9];
void bfs(int a, int b)
{
	arrcheck[a][b]=1;
	int sum;
	if(arra[a][b]!=INT_MAX)
		sum=arra[a][b];
	else
		sum=0;
	if(a-2>=0 && b-1>=0)
	{
		int mul=sum+(a*(a-2))+(b*(b-1));
		if(mul<arra[a-2][b-1])
		{	
			arra[a-2][b-1]=mul;
			bfs(a-2, b-1);
		}
	}
	if(a-1>=0 && b-2>=0)
	{
		int mul=sum+(a*(a-1))+(b*(b-2));
		if(mul<arra[a-1][b-2])
		{
			arra[a-1][b-2]=mul;
			bfs(a-1, b-2);
		}
	}
	if(a-2>=0 && b+1<=7)
	{
		int mul=sum+(a*(a-2))+(b*(b+1));
		if(mul<arra[a-2][b+1])
		{
			arra[a-2][b+1]=mul;
			bfs(a-2, b+1);
		}
	}
	if(a-1>=0 && b+2<=7)
	{
		int mul=sum+(a*(a-1))+(b*(b+2));
		if(mul<arra[a-1][b+2])
		{
			arra[a-1][b+2]=mul;
			bfs(a-1, b+2);
		}
	}
	if(a+2<=7 && b-1>=0)
	{
		int mul=sum+(a*(a+2))+(b*(b-1));
		if(mul<arra[a+2][b-1])
		{
			arra[a+2][b-1]=mul;
			bfs(a+2, b-1);
		}
	}

	if(a+1<=7 && b-2>=0)
	{
		int mul=sum+(a*(a+1))+(b*(b-2));
		if(mul<arra[a+1][b-2])
		{
			arra[a+1][b-2]=mul;
			bfs(a+1, b-2);
		}
	}
	if(a+2<=7 && b+1<=7)
	{
		int mul=sum+(a*(a+2))+(b*(b+1));
		if(mul<arra[a+2][b+1])
		{
			arra[a+2][b+1]=mul;
			bfs(a+2, b+1);
		}
	}
	if(a+1<=7 && b+2<=7)
	{
		int mul=sum+(a*(a+1))+(b*(b+2));
		if(mul<arra[a+1][b+2])
		{
			arra[a+1][b+2]=mul;
			bfs(a+1, b+2);
		}
	}
}

int main(){
	int a, b, c, d;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF)
	{
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
			{
				arrcheck[i][j]=-1;
				arra[i][j]=INT_MAX;
			}
		}
		arra[a][b]=0;
		bfs(a, b);
		if(arrcheck[c][d]==1)
		cout<<arra[c][d]<<endl;
		else
			cout<<arrcheck[c][d]<<endl;
	}
	return 0;
}
