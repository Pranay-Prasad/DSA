#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
const int inf = 1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj;
    For(i,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }
    int src;
    cin>>src;
    vector<int> dist(n,inf);
    dist[src] = 0;
    for(int i = 0; i < n-1;i++)
    {
        for(auto e : adj)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v],w + dist[u]); 
        }
    }
    for(auto i : dist)
    {
        cout<<i<<" ";
    }
    return 0;
}