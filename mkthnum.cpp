#include<bits/stdc++.h>
using namespace std;

struct node{
	node *left;
	node *right;
	int val;
	node(){}
	node(node* l, node* r, int v)
	{
		left=l;
		right=r;
		val=v;
	}
};

void build(node *n, int low, int high, int pos) 
{
	if(low==high && low==pos)
	{
		n->val=1;
		return;
	}
	else if(low== high)
	{
		n->val=0;
		return;
	}
	int mid=(low+high) /2;
	n->left=new node(NULL, NULL, 0);
	n->right=new node(NULL, NULL, 0);
	build(n->left, low, mid, pos);
	build(n->right, mid+1, high, pos);
	n->val= n->left->val+ n->right->val;
}

void upgrade(node *prev, node *cur, int low, int high, int idx)
{
	//cout<<"idx"<<idx<<endl;
	if(idx>high || idx<low || low>high)
	{
		//cout<<"hello1"<<endl;
		return;
	}
	if(low==high && low==idx )
	{
		//cout<<"hello2"<<endl;
		cur->val=1;
	//	cout<<"low"<<low<<"val="<<cur->val<<endl;
		return;
	}
	else if(low==high)
	{
		//cout<<"hello3"<<endl;
		cur->val=0;
	//	cout<<"low"<<low<<"val="<<cur->val<<endl;
		return;
	}
	int mid=(low+high)/2;
	//cout<<"low"<<low<<""<<"high"<<high<<endl;
	//cout<<"hello a"<<endl;
	if(idx<=mid)
	{
	//	cout<<"hello b"<<endl;
		cur->right=prev->right;
		cur->left=new node(NULL, NULL, 0);
	//	cout<<"hello4"<<endl;
		upgrade(prev->left, cur->left, low, mid, idx);
	}
	else
	{
	//	cout<<"hello c"<<endl;
		cur->left=prev->left;
	//	cout<<"hello d"<<endl;
		cur->right=new node(NULL, NULL, 0);
	//	cout<<"hello5"<<endl;
		upgrade(prev->right, cur->right, mid+1, high, idx); 
	}
	cur->val=(cur->left->val)+ (cur->right->val);
	//	cout<<"low"<<low<<"high"<<high<<"val="<<cur->val<<endl;
}

int query(node *i, node* j, int k, int low, int high)
{
	//cout<<"k"<<k<<endl;
	if(low==high && (j->val)-(i->val)==k)
	{
		//cout<<"low"<<(j->val)-(i->val)<<endl;
		return low;
	}
	int mid=(low+high) /2;
	if((j->left->val)-(i->left->val)>=k)
	{
		//cout<<"going in left of"<<low<<" "<<high<<endl;
		return query(i->left, j->left, k, low, mid);
	}
	else{
		//cout<<"going in right of"<<low<<" "<<high<<endl;
		k=k-((j->left->val)-(i->left->val));
		//cout<<"k changed to "<<k<<endl;
		return query(i->right, j->right, k, mid+1, high);
	}
}

int query0(node *i, int k, int low, int high){
	
	if(low==high && (i->val)==k)
	{
		return low;
	}
	int mid=(low+high) /2;
	if((i->left->val)>=k)
	{
		return query0(i->left, k, low, mid);
	}
	else
	{
		k-=(i->left->val);
		return query0(i->right, k, mid+1, high);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	vector<pair<int, int> >a;
	vector<pair<int, int> >b;
	vector<pair<int, int> >::iterator itv1;
	vector<pair<int, int> >::iterator itv2;
	node *version[n];
	pair<int, int> foo;
	int num;
	for(int i=0;i<n; i++)
	{
		cin>>num;
		foo=make_pair(num, 0);
		a.push_back(foo);
		foo=make_pair(num, i);	
		b.push_back(foo);
	}
	sort(b.begin(), b.end());
	int cnt=0;
	for(itv2=b.begin(); itv2!=b.end(); itv2++)
	{
		a[itv2->second].second=cnt;
		//cout<<"itv2->first"<<itv2->first<<endl;
		//cout<<a[itv2->second].first<<a[itv2->second].second<<endl;
		cnt++;
	}
	node* root=new node(NULL, NULL, 0);
	build(root, 0, n-1, a[0].second); 
	version[0]=root;	
	for(int i=1; i<n; i++)
	{
		version[i]=new node(NULL, NULL, 0);
		upgrade(version[i-1], version[i], 0, n-1, a[i].second);	
	//	cout<<"hello"<<endl;
	}
	
	int qi, qj, qk;
	int ap;
	for(int i=0; i<m; i++)
	{
		cin>>qi>>qj>>qk;
		if(qi!=1)
			ap=query(version[qi-2], version[qj-1], qk, 0, n-1 );
		else
			ap=query0(version[qj-1], qk, 0, n-1);
	//	cout<<"ap"<<ap<<endl;
		cout<<b[ap].first<<endl;	
		//cout<<"hello"<<endl;
	}
	return 0;
}
