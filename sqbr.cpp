#include<bits/stdc++.h>
using namespace std;
int ans_query(int n, int k, int *arr, int count){
	int open=k;
	if(count==0)
	{
		int debt=0;
		for(int i=0; i<n; i++)
		{
			if(open<n/2)	
			{
				if(i==0)
					arr[i]=1;
				else
					arr[i]=2;
				open++;
			}
			if(arr[i]==1 || arr[2])
			{
				debt++;
			}
			else 
			{
				debt--;	
			}
		}
		if(debt!=0)
			return count
	}
	
}
int main(){
	int t, n, k, o, ans;
	while(t--)
	{
		cin>>n>>k;
		n=n*2;
		int arr[n+1];
		for(int i=1; i<=k; i++)
		{
			cin>>o;
			arr[o]=1;	
		}
		int flag=0;
		int prev=0;
		if(arr[n]==1)
			cout<<"0"<<endl;
		else
			cout<<ans_query(n, k, arr, 0)<<endl;
	}
	return 0;
}
