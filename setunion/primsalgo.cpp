#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
const int N = 1e5 + 2;
const int INF = 1e9;
int n, m;
vector<vector<int>> adj[N];
int cost = 0;
vi weights(N,INT_MAX),parent(N);
vector<bool>vis(n,false);
int find_min(int s)
{
    int minvertex = -1;
    for(int i = 0; i < s ; i++)
    {
        if(!vis[i] && (minvertex == -1 || weights[i] < weights[minvertex]))
            minvertex = i;
    }
    return minvertex;
}
void primsMST(int s)
{
    parent[0] = -1;
    weights[0] = 0;
    for(int i = 0; i < s; i ++)
    {
        int minVertex = find_min(s);
        vis[minVertex] = true;
        for (int j = 0; j < s; j++)
        {
            if(adj[minVertex][j] != 0)
        }
        

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    For(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    primsMST(0);

    return 0;
}