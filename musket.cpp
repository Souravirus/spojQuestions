#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	int n;
	while(t--)
	{
		cin>>n;
		int A[n+1][n+1];
		int count=1;
		int B[n+1];
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				cin>>A[i][j];
			}
		}
		for(int i=1; i<=n; i++)
		{
			int j=i+2;
			int win=i+1;
			while((i+j-1)%n!=i)
			{
				if(A[win][(i+j)%n]==1)
					win=(i+j)%n;	
				j++;
			}
			if(win==i)
			{
				B[count]=win;
				count++;
			}
		}
		for(int i=1; i<count; i++)
			cout<<B[i]<<endl;
	}
	return 0;
}
