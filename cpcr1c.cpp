#include<bits/stdc++.h>
typedef unsigned long long int ulli;
using namespace std;
vector<ulli>a;
int main()
{
	ulli u, v;
	string s;
	string ::iterator its; 
	ulli count=0;
	ulli newvalue=0;
	ulli s_size=0, diff=1, countdigits=1, others, counttraverse=0;
	a.push_back(0);
	while(count<=100000){		
			int temp=a[count];
			count++;
			if(diff==10)
			{
				countdigits*10;
				diff=0;
				counttraverse=0;
			}
			others=count-(diff*countdigits);
			temp+=a[others]+diff;		
			if(counttraverse==countdigits)
			{
				diff++;
			}
			counttraverse++;
			a.push_back(temp);
	}
	cin>>u>>v;
	while(u!=-1 && v!=-1){
	
		cout<<a[v]-a[u-1]<<endl;
		cin>>u>>v;
	}
	return 0;
}
