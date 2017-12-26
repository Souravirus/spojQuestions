#include<bits/stdc++.h>
#define root 0
#define N 100100
#define level 18
using namespace std;
vector<int> A[N], C[N];
vector<int>:: iterator itv;
int sub[N];
int parent[N][level], baseArray[N], ptr, posInBase[N];
int chainNo, chainInd[N], chainHead[N];
int st[N*6], qt[N*6];
int depth[N], otherEnd[N];

void dfs(int pos , int df){
	vector<int>:: iterator itvi;
	depth[pos]=df;
	for(itvi=A[pos].begin();itvi!=A[pos].end(); itvi++)
	{
		if(*itvi>pos)
		{
			parent[*itvi][0]=pos;
			dfs(*itvi, df+1);
			//below I have used to find the subtree size
			sub[pos]+=sub[*itvi];	

			sub[pos]++;
		}
	}
}

void hld(int curNode, int cost)
{
	if(chainHead[chainNo]==-1)
	{
		chainHead[chainNo]=curNode;
	}
	chainInd[curNode]=chainNo;
	posInBase[curNode]=ptr;
	baseArray[ptr]=cost;
	ptr++;
	int sc=-1, ncost;
	for(int i=0; i<A[curNode].size();i++)
	{
		if(curNode<A[curNode][i])
		{
			if(sc==-1|| sub[sc]<sub[A[curNode][i]])
			{
				sc=A[curNode][i];
				ncost=C[curNode][i];
			}
		}
	}
	if(sc!=-1)
		hld(sc, ncost);
	
	for(int i=0; i<A[curNode].size(); i++)
	{
		if(curNode<A[curNode][i])
		{
			if(sc!=A[curNode][i])
			{
				chainNo++;
				hld(A[curNode][i], C[curNode][i]);
			}
		}
	}
}

void make_tree(int cur, int s, int e)
{
	if(s==e-1){
		st[cur]=baseArray[s];
		return ;
	}
	int c1=(cur<<1), c2=c1+1, m=(s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[cur]=st[c1]> st[c2] ? st[c1] : st[c2];
}

void sparseMatrix(int n)
{
	for(int i=1; i<level; i++)
	{
		for(int node=1; node<n; node++)
		{
			if(parent[node][i-1]!=-1)
			{
				parent[node][i]=parent[parent[node][i-1]][i-1];
			}
		}
	}
}

int lca(int u, int v)
{
	if(depth[v]<depth[u])
		swap(u, v);
	int diff=depth[v]-depth[u];
	for(int i=0; i<level; i++)
		if((diff>>i) & 1)
			v=parent[v][i];
	if(u==v)
		return u;
	for(int i=level-1; i>=0; i--)
		if(parent[u][i] != parent[v][i])
		{
			u=parent[u][i];
			v=parent[v][i];
		}
	return parent[u][0];
}

void query_tree(int cur, int s, int e, int S, int E) {
	if(s >= E || e <= S) {
		qt[cur] = -1;
		return;
	}
	if(s >= S && e <= E) {
		qt[cur] = st[cur];
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	query_tree(c1, s, m, S, E);
	query_tree(c2, m, e, S, E);
	qt[cur] = qt[c1] > qt[c2] ? qt[c1] : qt[c2];
}

int query_up(int u, int v){
	if(u==v)
		return 0;
	int uchain, vchain=chainInd[v], ans=-1;
	while(1){
		uchain=chainInd[u];
		if(uchain==vchain){
			if(u==v)
				break;
			query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
			if(qt[1]>ans)
				ans=qt[1];
			break;
		}
		query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
		if(qt[1]>ans) ans=qt[1];
		u=chainHead[uchain];
		u=parent[u][0];
	}
	return ans;
}

void query(int u, int v){
	int lcaq=lca(u, v);
	int ans=query_up(u, lcaq);
	int temp=query_up(v, lcaq);
	if(temp>ans)
		ans=temp;
	cout<<ans<<endl;
}

void update_tree(int cur, int s, int e, int x, int val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		st[cur] = val;
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m, e, x, val);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
}

void change(int i, int val){
	int u=otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
}
int main(){
	int t, n, a, b, c;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ptr=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<18; j++)
			{
				parent[i][j]=-1;
			}
		}
		for(int i=0; i<n; i++)
		{
			A[i].clear();
			C[i].clear();
			sub[i]=0;	
			chainHead[i]=-1;
			
		}
		for(int i=0; i<n-1; i++)
		{
			cin>>a>>b>>c;
			A[a-1].push_back(b-1);
			A[b-1].push_back(a-1);
			C[a-1].push_back(c);
			C[b-1].push_back(c);
			otherEnd[i]=max(a-1, b-1);
		}
		chainNo=0;
		dfs(root, 0);
		hld(root, -1);
		make_tree(1, 0, ptr);
		sparseMatrix( n);
		while(1){
			string s;
			cin>>s;
			if(s[0]=='D')
				break;
			int qa, qb;
			cin>>qa;
			cin>>qb;	
			if(s[0]=='Q')
			{
				query(qa-1, qb-1);
			}
			else{
				change(qa-1, qb);
			}
		}
	}
	return 0;
}
