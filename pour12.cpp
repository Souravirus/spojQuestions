#include<bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;
ulli mini;
int gcd(int a, int b)
{
	if(a<b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	while(b>0)
	{
		int f=a%b;
		a=b;
		b=f;
	}
	return a;
}
ulli atob(int a, int b, int c){
	int vesa=0;
	int vesb=0;
	 ulli count=0;
	while(vesa!=c && vesb!=c && count<=mini)
	{
		if(!vesa)
		{
			vesa=a;
			count++;
		}
		else if(vesb==b)
		{
			vesb=0;
			count++;
		}
		else
		{
			if((b-vesb)<vesa)
			{
				vesa-=(b-vesb);
				vesb+=(b-vesb);
				count++;
			}
			else
			{
				vesb+=vesa;
				vesa-=vesa;
				count++;
			}
		}
	}
	return count;
}
int main(){
	int t, gc, a, b, c;
	ulli ab, ba;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		gc=gcd(a, b);
		if(c<=std::max(a, b))
		{
			if(c%gc==0)
			{
				mini=ULLONG_MAX;
				ab=atob(a, b, c);	
				mini=ab;
				ba=atob(b, a, c);
				cout<<std::min(ab, ba)<<endl;
			}
			else
				cout<<"-1"<<endl;
		}
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
