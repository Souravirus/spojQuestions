#include<bits/stdc++.h>
using namespace std;
#define INF 200001
typedef pair<int, int> iPair;
class Graph
{
	int V;
	list< pair<int, int> >*adj;
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	int  shortestPath(int s, int d);
	void modify();
};

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<iPair> [V];
}
void Graph:: addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}
int  Graph:: shortestPath(int src, int dest){
	vector<int>node(V, 0);
	priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
	vector<int> dist(V, INF);
	pq.push(make_pair(0, src));
	dist[src]=0;
	while(!pq.empty())
	{
	//	cout<<pq.top().second<<" "<<pq.top().first<<endl;
		int u=pq.top().second;
		if(node[u]==1)
		{
			pq.pop();	
			continue;
		}
	//	cout<<"After check"<<pq.top().second<<" "<<pq.top().first<<endl;
		node[u]=1;
		pq.pop();
		list<iPair >::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++)
		{
			int v= (*i).first;
			int weight= (*i).second;
			if(!node[v])
			{
	//			cout<<"dist[v] at checking"<<dist[v]<<endl;
				if(dist[v]> dist[u]+weight)
				{
					dist[v]=dist[u]+weight;
					pq.push(make_pair(dist[v], v));
	//				cout<<"pushed "<<v<<" "<<dist[v]<<endl;	
				}
			}
		}
	}
	return dist[dest];
}
int main(){
	int s, n, p, nr, cost, r;
	string name;
	string name2;
	cin>>s;
	while(s--){
		cin>>n;
		Graph g(n+1);	
		map<string, int> m;
		map<string, int> :: iterator itm;
		map<string, int> :: iterator itm2;
		for(int i=1;i<=n; i++){
			cin>>name;
			m.insert(pair<string, int>(name, i));
			cin>>p;
			for(int j=0;j<p;j++){
				cin>>nr>>cost;
				g.addEdge(i, nr, cost);
			}
		}	
		//g.modify();
		cin>>r;
		while(r--)
		{
			cin>>name>>name2;
			itm=m.find(name);
			itm2=m.find(name2);
			//cout<<itm->second<<" "<<itm2->second<<endl;
			int ans=g.shortestPath(itm->second, itm2->second);
			cout<<ans<<endl;
		}
	}
	return 0;
}
