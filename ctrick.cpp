#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		int count=0;
		for(int i=1; i<=n; i++)
		{
			int pos=(count+i)%n;
			a[pos]=i;
			count=pos;
		}
	}
	return 0;
}
