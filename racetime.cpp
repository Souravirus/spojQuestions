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

int binSearch(vector<vector<int> >sqrtdec, int vectIndex, int a, int s, int e, int min){
    dout<<"inside binSearch s:"<< s << "e:" << e << endl;
    int mid = (s+e)/2;
    dout<<"mid"<<mid<<endl; 

    if(s > e)
    {
        dout<<"inside chutiya condition"<<endl;
        return min;
    }

    if(s == e){
        dout<<"inside condition where s=e"<<endl;

        if(sqrtdec[vectIndex][s]<=a){
            dout<<"Here sqrtdec <= asqrtdec[vectIndex][s]:"<<sqrtdec[vectIndex][s]<<endl;
            return s;
        }

        else{
            dout<<"Here sqrtdec > sqrtdec[vectIndex][s]:"<<sqrtdec[vectIndex][s]<<endl;
            return min;
        }
    }

    else if(sqrtdec[vectIndex][mid] <= a){
        dout<<"inside condition where sqrtdec <= a:"<<sqrtdec[vectIndex][mid]<<endl;
        min = mid;
        return binSearch(sqrtdec, vectIndex, a, mid+1, e, min);
    }

    else{
        dout<<"inside condition where sqrtdec > a:"<<sqrtdec[vectIndex][mid]<<endl;
        return binSearch(sqrtdec, vectIndex, a, s, mid-1, min);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    int arr[N];

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int root = sqrt(N);
    dout<<"root"<<root<<endl;
    int i = 0;
    vector<vector<int> >sqrtdec;
    vector<int>vect;

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

    sort(vect.begin(), vect.end());
    sqrtdec.push_back(vect);
    vect.clear();
    char type;

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
                    dout<<"Sorry first mod cannot be found enc the e"<<endl;
                    if(arr[j] <= val)
                        count++;
                    flag=1;
                    break;
                }

                if(arr[j] <= val){
                    dout<<"counting first to find starting index"<<endl;
                    count++;
                    dout<<"count"<<count<<endl;
                }
                
                j++;
            }

            if( flag != 1 ){

                while(j+root-1 <= e-1){
                    dout<<"inside while loop to binary search"<<endl;
                    int vectIndex = j/root;
                    dout<<"vectIndex here:"<<vectIndex<<endl;
                    int arrIndex = binSearch(sqrtdec, vectIndex, val, 0, root-1, -1);
                    dout<<"arrIndex here:"<<arrIndex<<endl;
                    if(arrIndex!=-1){
                        count += (arrIndex+1);
                        dout<<"count"<<count<<endl;
                    }
                    j = j+root;
                    dout<<"current j:"<<j<<endl;
                }
                
                for(int k = j; k <=e-1; k++)
                {
                    if(arr[k] <= val)
                    {
                        dout<<"increasing count for last k:"<<k<<" arr[k]:"<<arr[k]<<endl;
                        count++;
                    }
                }
                dout<<"count"<<count<<endl;
            }
            cout<<count<<endl;
        }
        else{
            int pos, val;
            cin>>pos>>val;
            int changeVal=arr[pos-1];
            arr[pos-1]=val;
            int vectIndex = (pos-1)/root;
            int arrIndex=binSearch(sqrtdec, vectIndex, changeVal, 0, sqrtdec[vectIndex].size()-1, -1);
            dout<<"vectIndex"<<vectIndex<<endl;
            dout<<"arrIndex"<<arrIndex<<endl;
            sqrtdec[vectIndex][arrIndex]=val;
            sort(sqrtdec[vectIndex].begin(), sqrtdec[vectIndex].end());
        }
    }
	return 0;
}
