#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    char str[100005];

    while(scanf("%s", str) != EOF){
        string s = str;
        string temp, perm, tTemp;
        int point = s.length()-1;
        int pointTemp;
        int i = 0;
        while(i < s.length()){
            if(s[point] != s[i]){
                if(tTemp.length() > 0){
                    for(int j = 0; j < temp.length()-tTemp.length(); j++){
                        perm+=temp[j];
                    }
                    temp = "";
                    point = s.length()-1;
                    i -= tTemp.length();
                    tTemp = "";
                }
                else{
                    perm += s[i];
                    i++;
                }
            }
            
            else{
                temp+=s[point];

                if(temp.size() == 1){
                    pointTemp = 0;
                }

                else if(temp.size() > 1){
                    if(s[point] == temp[pointTemp]){
                        tTemp += temp[pointTemp];
                        pointTemp++;
                    }
                    else{
                        tTemp = "";
                        pointTemp = 0;
                    }
                }
                point--;
                i++;
            }
        }
        reverse(perm.begin(), perm.end());
        s+= perm;
        cout << s << endl;
    }
	return 0;
}
