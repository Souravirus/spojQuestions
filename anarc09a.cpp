#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	lli countind=1;
	cin>>s;
	while(s[0]!='-')
	{
		int tcount=0;
		int counto=0;
		int countc=0;
		for(int i=0; i<s.length(); i++)
		{
			if(s[i]=='}' && counto==0)
			{
				tcount++;
				counto++;
			}
			else if(s[i]=='}')
				counto--;
			else if(s[i]=='{')
				counto++;
			if(s.length()-i-1 <counto)
			{
				if(s[i]=='{')
				{
					tcount++;
				}
				counto--;
			}
		}
		cout<<countind<<". "<<tcount<<endl;
		cin>>s;
		countind++;
	}
	return 0;
}
