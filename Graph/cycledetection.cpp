//undirected
//keep on traversing the graph.
//if you found and edge pointing to an already visited node
//except the parent node, a cycle is found.
#include <bits/stdc++.h>
using namespace std;
bool iscycle(int src,vector<int>adj[],vector<bool>&vis,int par)
{
	vis[src] = true;
	for (auto i : adj[src])
	{
		if(i != par)
		{
			if(vis[i])
				return true;
			if(!vis[i] && iscycle(i,adj,vis,src))
				return true;
		}
	}
	return false;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>adj[n];
	for(int i = 0; i <m ;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool>vis(n,false);
	bool cycle = false;
	for(int i = 0; i < n ; i ++)
	{
		if(!vis[i] && iscycle(i,adj,vis,-1))
		{
			cycle = true;
		}
	}
	if(cycle)
		cout<<"yes"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
