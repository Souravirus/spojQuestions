#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "

using namespace std;
int debug = 1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int Q;
    cin >> Q;
    char type;
    set<int>myset;
    set<int>::iterator its;

    for(int i = 0; i < Q; i++){
        cin >> type;
        int num;

        if(type == 'I'){
            cin >> num;
            myset.insert(num);
        }
        
        else if(type == 'D'){
            cin >> num;
            its = myset.find(num);

            if(its != myset.end())
                myset.erase(num);
        }
        
        else if(type == 'K'){
            cin >> num;
            
            if(num <= myset.size()){
                int count=0;

                for(its = myset.begin(); its != myset.end(); its++){

                    if(count == num-1){
                       cout << *its << endl; 
                       break;
                    }

                    count++;
                }
            }

            else
                cout << "invalid" << endl;
        }

        else if(type == 'C'){
            cin >> num;
            its = myset.lower_bound(num);
            cout << distance(myset.begin(), its) << endl;
        }
        
        else if (type == 'K'){
            
        }
    }

	return 0;
}
