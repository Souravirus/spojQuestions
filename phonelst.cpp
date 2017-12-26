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

struct trieNode{
    trieNode *num[10];
    int childcnt;
    bool isPhone;
};

trieNode *getNode(){
    trieNode *temp = new trieNode();

    for (int i = 0; i< 10; i++){
        temp -> num[i] = NULL;
    }

    temp -> childcnt = 0;
    temp -> isPhone = false;
    return temp;
}

void insert(trieNode *root, string str){
    trieNode *curr = root;

    for(int i = 0; i < str.length(); i++){
        int index = str[i] - '0';
        if(curr -> num[index] == NULL){
            curr -> num[index] = getNode();
        }
        curr = curr -> num[index];
        curr -> childcnt++;
    }
    curr -> isPhone = true;
}

int search( trieNode *root){
    int flag = 0;
    for (int i = 0; i < 10; i++){
        if (root -> num[i]){
            if (root -> num[i] -> isPhone == true)
            {
                if (root -> num[i] -> childcnt > 1){
                    flag = 1;
                    break;
                }
            }
            int ans = search(root -> num[i]);
            if (ans == -1)
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1)
        return -1;
    else
        return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        trieNode *root = getNode();  

        for (int i = 0; i < N; i++){
            string str;
            cin >> str;
            insert(root, str); 
        }
        int ans = search(root);
        if (ans == -1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
	return 0;
}
