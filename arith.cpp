#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--)
	{
		string s, opn1="", opn2="";
		char opr;
		int carr;
		cin>>s;
		for(int i=0; i<s.length(); i++)
		{
			if(s[i]=='+' || s[i]=='-' || s[i]=='*')
			{
				opn1+=s.substr(0, i-1);
				opn2+=s.substr(i+1);
				opr=s[i];
			}
		}
		if(opr=='+'){
			
		}
	}
}
