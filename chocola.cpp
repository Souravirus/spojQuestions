#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;

int debug = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;
    
    while(T--){
        int xi, yi;
        cin >> xi >> yi;
        int x[xi], y[yi];

        for(int i = 0; i < xi - 1; i++){
            cin >> x[i];
        }
        
        for(int i = 0; i< yi - 1; i++){
            cin >> y[i];
        }
        
        sort(x, x + xi-1, greater<int>());
        sort(y, y + yi-1, greater<int>());

        /*dout << "printing x " <<endl;
        for(int i = 0; i< xi -1 ; i++)
            cout << x[i] << endl;
        dout << "printing y" <<endl;
        for(int i = 0; i< yi -1 ; i++
            cout << y[i] << endl;
            */
        int countx = 0, county = 0, sum = 0, divx = 1, divy = 1;

        while(countx != xi-1 || county != yi-1){

            if(countx != xi-1 && county != yi-1){

                if(x[countx] >= y[county]){
                    dout << "in first of first"<<endl;
                    dout << x[countx]<<endl;
                    sum += x[countx] * divy;
                    divx++;
                    countx++;
                }

                else{
                    dout << "in second of first"<<endl;
                    dout << y[county] << endl;
                    sum += y[county] * divx;
                    divy++;
                    county++;
                }

            }
            
            else if(countx == xi - 1){
                dout << "in second" << endl;
                dout << y[county] << endl;
                sum += y[county] * divx;
                divy++;
                county++;
            }

            else if(county == yi - 1){
                dout << "in third" << endl;
                dout << x[countx] << endl;
                sum += x[countx] *divy;
                divx++;
                countx++;
            }
            dout << "one cycle finished" <<endl;
        }
        dout << "outside "<<endl;
        cout << sum << endl;
    }

	return 0;
}
