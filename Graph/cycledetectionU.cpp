//directed graph
#include <bits/stdc++.h>
using namespace std;
bool iscycle(int src,vector<int>adj[],vector<int>&stack,vector<bool>&vis)
{
    stack[src] = 1;
    if(!vis[src])
    {
        vis[src] = true;
        for(auto i : adj[src])
        {
            if(!vis[i] && iscycle(i,adj,stack,vis))
            {
                return true;
            }
            if(stack[i])
                return true;
        }
    }
    stack[src] = false;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<int>adj[n];
	for(int i = 0; i <m ;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
    bool cycle  = false;
    vector<int> stack(n,0);
    vector<bool>vis(n,false);
    for (int i = 0; i < n; i++)
    {
        if(!vis[i] && iscycle(i,adj,stack,vis))
            cycle = true;

    }
	if(cycle)
		cout<<"yes"<<endl;
	else
		cout<<"NO"<<endl;
    return 0;
}