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
    vector<int>dist(n+1,inf);
    vector<bool>vis(n+1,false);
    vector<vector<pair<int,int>>> graph(n+1);
    For(i,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int src;
    cin>>src;
    dist[src] = 0;
    set<pair<int,int>>s;
    //{weight,vertex}
    s.insert({0,src});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for(auto i : graph[x.second])
        {
            if(dist[i.first] > dist[x.second] + i.second)
            {
                s.erase({dist[i.first],i.first});
                dist[i.first] = dist[x.second] + i.second;
                s.insert({dist[i.first],i.first});
            }
        }
    }
    for(int i = 1; i<=n;i++)
    {
        if(dist[i] < inf)
            cout<<dist[i]<<" ";
        else
            cout<<-1<<" ";
    }
    return 0;
}