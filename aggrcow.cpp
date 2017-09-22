#include<bits/stdc++.h>
using namespace std;
int F(int a[],int N, int mid, int C)
{
	int lastPos=a[0];
	int count=1;
	for(int i=1; i<N; i++)
	{
		if(a[i]-lastPos>=mid){
			count++;	
			if(count==C)
				return 1;
			lastPos=a[i];
		}
	}
	return 0;
}
int main()
{
	int t, N, C;
	cin>>t;
	while(t--)
	{
		cin>>N>>C;
		int a[N];
		for(int i=0; i<N; i++)
		{
			cin>>a[i];
		}
		sort(a, a+N);
		int start=0, end=a[N-1]-a[0];
		while(end-start>1)
		{
			int mid=(start+end)>>1;
			(F(a,N,  mid, C)?start:end)=mid;
		}
		cout<<start<<endl;
	}
	return 0;
}
