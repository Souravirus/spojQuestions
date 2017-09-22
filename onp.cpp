#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	string s;
	cin>>T;
	while(T--){
		cin>>s;
		stack<char>st;
		string t="";
		for(int i=0;i<s.length(); i++){
			if(s[i]=='(')
				st.push('(');
			else if(s[i]=='+' )
			{
				while(st.top()=='*' || st.top()=='-' || st.top()=='/' || st.top()=='^'){
					t+=st.top();	
					st.pop();
				}
				st.push('+');
			}
			else if(s[i]=='-' ){
				
				while(st.top()=='*' ||  st.top()=='/' || st.top()=='^'){
					t+=st.top();	
					st.pop();
				}
				st.push('-');
			}
			else if(s[i]=='*' )	
			{
				while( st.top()=='/' || st.top()=='^'){
					t+=st.top();	
					st.pop();
				}
				st.push('*');
			}
			else if(s[i]=='/' )	
			{
				while( st.top()=='^'){
					t+=st.top();	
					st.pop();
				}
				st.push('/');
			}
			else if(s[i]=='^')
				st.push('^');
			
			else if(s[i]==')'){
				while(st.top()!='(')
				{
					t+=st.top();
					st.pop();
				}
				st.pop();
			}
			else
				t+=s[i];
		}
		cout<<t<<endl;
	}
	return 0;
}
