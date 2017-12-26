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
    lli T;
    cin >> T;

    while(T--){
        lli num;
        cin >> num;
        
        int upto = sqrt(num) + 1;
        int flag = 0;
        
        for(int i = 2; i < upto; i++){

            if(num%i == 0){
                flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            cout << "YES" << endl;
        }

        else
            cout << "NO" << endl;

    }

	return 0;
}
