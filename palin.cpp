#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		int flage=1;
		cin>>s;
		int len=s.length();
		if(len%2==0)
		{
			int flag9=0;
			for(int i=0;i<len;i++){
				if(s[i]!='9')
				{
					flag9=1;
					break;
				}
			}
			if(!flag9){
				s[0]='1';
				for(int i=1;i<len;i++)
					s[i]='0';
				s+='1';
			}
			else{
				for(int i=0;i<len/2;i++){
					if(i==len/2-1){
						if(s[i]==s[len-i-1])
						{
							if(flage==1)
							{
								if(s[i]=='9'){
									int k=i-1;	
									while(s[k]=='9'){
										s[k]='0';
										s[len-k-1]='0';
										k--;
									}
									s[k]=s[k]+1;
									s[len-k-1]++;
									s[i]='0';
									s[len-i-1]='0';
								}
								else{
									s[i]++;
									s[len-i-1]=s[i];
								}
							}	
						}
						else if(s[i]<s[len-i-1])
						{
							s[i]++;
							s[len-i-1]=s[i];
						}
						else if(s[i]>s[len-i-1]){
							s[len-i-1]=s[i];
						}
					}
					else{
						if(s[i]<s[len-i-1]){
							s[len-i-1]=s[i];
							flage=1;
						}
						else if(s[i]>s[len-i-1]){
							s[len-i-1]=s[i];
							flage=0;
						}
					}
				}
			}
		}
		else{
			
			int flag9=0;
			for(int i=0;i<len;i++){
				if(s[i]!='9')
				{
					flag9=1;
					break;
				}
			}
			if(flag9==0){
				s[0]='1';
				for(int i=1;i<len;i++)
					s[i]='0';
				s+='1';
			}
			else{
				for(int i=0;i<=len/2;i++){
					if(i==len/2){
						if(flage==1)
						{
							if(s[i]=='9'){
								int k=i-1;	
								while(s[k]=='9'){
									s[k]='0';
									s[len-k-1]='0';
									k--;
								}
								s[k]=s[k]+1;
								s[len-k-1]++;
								s[i]='0';
							}
							else{
								s[i]++;
							}	
						}
					}
					else{
						if(s[i]<s[len-i-1]){
							s[len-i-1]=s[i];
							flage=1;
						}
						else if(s[i]>s[len-i-1]){
							s[len-i-1]=s[i];
							flage=0;
						}
					}
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
