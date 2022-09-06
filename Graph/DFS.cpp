#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
const int N = 1e5 + 2;
vi adj[N];
bool vis[N];
void dfs(int node)
{
    //preorder
    vis[node] = 1;
    cout<<node<<" ";
    vi::iterator it;
    for(it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if(!vis[*it])
        {
            dfs(*it);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    For(i,N)
    {
        vis[i] = false;
    }
    int n,m;
    cin>>n>>m;
    int x,y;
    For(i,m)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    return 0;
}