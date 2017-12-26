#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;

struct trieNode{
    trieNode *children[26];
    bool word;
};

trieNode *getNode(){
    trieNode *temp = new trieNode();
    temp -> word = false; 
    for(int i=0; i < 26; i++){
        temp -> children[i] = NULL;
    }

    return temp;
}

void insert(trieNode *root, string str){
    trieNode *curr = root;

    for (int i = 0; i < str.length(); i++){
        int index = str[i] - 'a';
        if (curr -> children[index] == NULL)
            curr -> children[index] = getNode();
        curr = curr -> children[index];
    }
    curr -> word = true; 
}

int printWords(trieNode *curr, string str){
    int flag = -1;
    if(curr == NULL)
        return -1 ;
    else{

        for(int i = 0; i < 26; i++){

            if(curr -> children[i] != NULL){
                char a = 'a' + i;

                if(curr -> children[i] -> word == true){
                   cout << str + a<< endl;
                }
                 
                printWords(curr -> children[i], str + a); 
                flag = 1;
            }

        }

    }
    return flag;
}

int search(trieNode *root, string str){
   trieNode *curr = root; 

   for (int i = 0; i < str.length(); i++){
        int index = str[i] - 'a';
        if (curr -> children[index] == NULL)
            return -1;
        curr = curr -> children[index];
   }
   return printWords( curr, str);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;
    trieNode *root = getNode();    

    while(T--){
        string str;
        cin >> str;
        insert(root, str);
    }

    int Q;
    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        string str;
        cin >> str;
        cout << "Case #" << i << ":" << endl;
        int result = search( root, str); 
        if(result == -1)
            cout << "No match." << endl;
    }

	return 0;
}
