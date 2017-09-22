#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	char a[1000000];
	int prime[3050];
	for(int i=0; i<1000000; i++)
	{
		a[i]='0';
	}
	int prod;
	int count=0;
	int countpr=2;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		//cout<<n<<endl;
		while(n-1>=count)
		{
			//cout<<"hello"<<endl;
			prod=countpr;
			prime[count]=countpr;
			int i=1;
			while(prod<=1000000)
			{
				prod=countpr+;
				if(prod<1000000)
					a[prod]='1';
				i++;
			}
			countpr++;
			while(a[countpr]!='0')
			{
				countpr++;	
			}
			count++;
		}
		cout<<prime[n-1]<<endl;;	
	}
	return 0;
}
