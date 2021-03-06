#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "

int debug = 0;

struct tree{
    int data;
    int childcnt;
    tree *left;
    tree *right;
};

tree *root = NULL;

void insert(tree *curr, tree *node){
    dout << "inside insert function"<<endl;
    int sum = 0;
    if(node->data < curr->data){
        dout << "when node data < curr data" << endl;

        if(curr -> left == NULL){
            dout << "when curr left is NULL " << endl;
            curr -> left = node;
            sum++;
            
        }
        
        else{
            dout << " when curr left is not null " << endl;
            insert(curr -> left, node);
            sum += curr -> left -> childcnt + 1;   
            dout << " for " << curr -> left -> data << " childcnt "<< curr -> left -> childcnt << endl;
        }
                
        if(curr -> right != NULL){
            sum += curr -> right -> childcnt + 1;
        }
        
        curr -> childcnt = sum;
        dout << " for "<< curr -> data << " childcnt "<< curr -> childcnt <<endl;
        return;
    }

    else if(node->data > curr->data){
        dout << "when node data > curr data" << endl;

        if(curr -> right == NULL){
            dout << "when curr right is NULL " << endl;
            curr -> right = node;
            sum++;
            
        }
        
        else{
           dout << " when curr right is not null " << endl;
           insert(curr -> right, node);
           sum += curr -> right -> childcnt + 1;
            dout << " for " << curr -> right -> data << " childcnt "<< curr -> right -> childcnt << endl;
        }
                
        if(curr -> left != NULL){
            sum += curr -> left -> childcnt + 1;
        }
        
        curr -> childcnt = sum;
        dout << " for "<< curr -> data << " childcnt "<< curr -> childcnt <<endl;
        return ;
    }
    
}

tree * minValueNode( tree *curr){
    tree *current= curr;

    while(current -> left != NULL)
        current = current -> left;

    return current;
}

tree* deleteNode(tree *root, int key){
    dout << "inside deleteNode  fn"<<endl;
    root -> childcnt--;

    if (root == NULL)
        return root;

    if (key  < root -> data){
        dout << "moving left" << endl;
        root -> left = deleteNode(root -> left, key);
    }

    else if (key > root -> data){
        dout << "moving right" << endl;
        root -> right = deleteNode( root -> right, key);
    }

    else{ 

        if (root -> left == NULL){
            dout << "because root left is Null moving right to top" << endl;
            tree *temp = root -> right;
            free(root);
            return temp;
        }
        
        else if (root -> right == NULL){
            dout << "because root right is Null moving left to top" << endl;
            tree *temp = root -> left;
            free(root);
            return temp;
        }
         
        tree *temp = minValueNode(root -> right);

        root -> data =temp -> data;
        root -> right = deleteNode(root -> right, temp -> data);
    }
    return root;
}

int Kpify(tree *curr, int pos, int target){
    int count = pos + 1;
    dout << "in Kpify count " << count << endl;

    if( curr -> left != NULL){
        count += curr -> left -> childcnt + 1;
        dout << "inside less than count "<< count <<endl;

        if (target < count){
            return Kpify(curr -> left, pos, target); 
        }
    }
    
    if ( target == count )
    {
        dout << "inside equal count " << endl; 
        return curr -> data;
    }

    else if (target > count )
    {
        dout << "inside greater than " << endl;
        return Kpify(curr -> right, count, target);
    }
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int Q;
    cin >> Q;

    set<int> myset;

    while (Q--){
        char type;
        cin >> type;
        int num;
        set<int> :: iterator its;

        if (type == 'I'){
            cin >> num;

            if (myset.find(num) == myset.end())
                myset.insert(num);

            tree *n =new tree;
            n->left = NULL;
            n->right = NULL;
            n->data = num;
            n->childcnt = 0;    

            if ( root == NULL){
                dout << "inserting at root"<<endl;
                root = n;
            }
            
            else{
                dout << "inserting when root is Not null" << endl;
                insert(root, n);
                dout << " root child" << root -> childcnt;
            }
        }
        
        if (type == 'D'){
            cin >> num;
            its = myset.find(num);
            if (its != myset.end()){
                dout << "deleting an element from tree "<<endl;
                myset.erase(num);
                root = deleteNode(root, num);
            }
            else
                dout << "not found" << endl;
        }
        
        if (type == 'C'){
            cin >> num;
            its = myset.lower_bound(num);
            cout << distance(myset.begin(), its) << endl;
        }

        if (type == 'K'){
            cin >> num;

            if (num <= myset.size() ){
                dout << "going to Kpify"<<endl;
                cout << Kpify(root, 0, num) << endl; 
            }

            else
                cout << "invalid" << endl;
        }
    }
	return 0;
}
