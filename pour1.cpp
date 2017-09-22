#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, a, b, c, ans, ansa, ansb;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if(b>a){
			int temp=a;
			a=b;
			b=a;
		}
		if(c>a){
			cout<<"-1"<<endl;
		}
		else{
			if(c<b){
				if(c==0)
					cout<<"0";
				else if(a-b==c)
				{
					cout<<"2";
				}
				else
				{
					int q=a/b;
					int r=a%b;
					if(r)
						ans=b*(q+1);
					else
						ans=b*q;
					int temp=ans-a;
					if(temp==c)
						cout<<(q+1)*2<<endl;
					else
						cout<<"-1"<<endl;
				}	
			}
			else{
				ansa=INT_MAX;
				ansb=INT_MAX;
				if(!(c%b))
				{
					if(c==b)
						ansb=1;
					else
						ansb=(c/b)*2;
				}
				if(!((a-c)%b))
				{
					ansa=((a-c)/b)*2;
					if(c==a)
						ansa=1;
				}
				if(ansb<ansa)
					cout<<ansb<<endl;
				else
					cout<<ansa<<endl;
			}
		}
	}
	return 0;
}
