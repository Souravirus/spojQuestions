#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;

class line{
    public:
        int startx, starty, endx, endy;
        line(int startx, int starty, int endx, int endy){
            this->startx = startx;
            this-> starty = starty;
            this-> endx = endx;
            this->endy = endy;
        }
};

vector<line> ll;
vector<line> ul;
vector<pair<int, int> >vect;

void createLower(int n, int i){

    if(i == -1){
        line lowerFirst =   
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vect.clear();
        vect.resize(n);
        ll.clear();
        ul.clear();

        for(int i = 0; i < n; i++){
            int first, second;
            cin >> first >> second;
            vect[i].first = first;
            vect[i].second = second;
        }
        
        sort(vect.begin(), vect.end());
        
        createLower(n, -1);  
    }

	return 0;
}
