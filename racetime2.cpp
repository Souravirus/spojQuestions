#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "

int debug=0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, Q;

    //Just scanning the number of elements in array and number of queries.
    cin >> N >> Q;
    int arr[N];

    //Scanning of array elements
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    //Finding the square root of N. So, that I can decompose the whole array into small but equal parts.
    int root = sqrt(N);
    int i = 0;
    vector<vector<int> >sqrtdec;
    vector<int>vect;

    //This while loop basically decompose the whole array into small parts. These small parts contain elements in sorted order.
    while(i < N){

        if(i%root==0 && i!=0){
            sort(vect.begin(), vect.end());
            sqrtdec.push_back(vect);
            vect.clear();
            dout<<" pushing in another vector now "<< arr[i] << endl;
            vect.push_back(arr[i]);
        }

        else{
            dout<<"pushing in vect "<< arr[i] <<endl;
            vect.push_back(arr[i]);
        }

        i++;
    }

    //Putting the last group of elements into the vector
    sort(vect.begin(), vect.end());
    sqrtdec.push_back(vect);
    vect.clear();
    char type;

    //Below I am going through each query
    for(int i = 0; i < Q; i++){
        cin >> type;
        int s, e, val;

        if(type == 'C'){
            cin >> s >> e >> val;
            int flag=0;
            int count=0;
            int j=s-1;

            while( j % root !=0){

                if(j == e-1)
                {
                    if(arr[j] <= val)
                        count++;
                    flag=1;
                    break;
                }

                if(arr[j] <= val){
                    count++;
                }
                
                j++;
            }

            if( flag != 1 ){

                while(j+root-1 <= e-1){
                    int vectIndex = j/root;

                    int arrIndex = upper_bound(sqrtdec[vectIndex].begin(), sqrtdec[vectIndex].end(), val) - sqrtdec[vectIndex].begin();

                    count+=arrIndex;
                    j = j+root;

                }
                
                for(int k = j; k <=e-1; k++)
                {
                    if(arr[k] <= val)
                    {
                        count++;
                    }
                }
            }
            cout<<count<<endl;
        }
        else{
            int pos, val;
            cin>>pos>>val;
            int changeVal=arr[pos-1];
            arr[pos-1]=val;
            int vectIndex = (pos-1)/root;

            int arrIndex = upper_bound(sqrtdec[vectIndex].begin(), sqrtdec[vectIndex].end(), changeVal)-sqrtdec[vectIndex].begin();


            sqrtdec[vectIndex][arrIndex-1]=val;
            sort(sqrtdec[vectIndex].begin(), sqrtdec[vectIndex].end());
        }
    }
	return 0;
}
