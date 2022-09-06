#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a) for (int i = 0; i < a; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
int get_comp(vector<vector<int>> &adj, vector<bool> &vis, int a)
{
    if (vis[a])
        return 0;
    vis[a] = true;
    int ans = 1;
    for (auto x : adj[a])
    {
        if (!vis[x])
        {
            ans += get_comp(adj, vis, x);
            vis[x] = true;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        vector<bool> vis(n+1, false);
        vi comp;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                comp.push_back(get_comp(adj, vis, i));
            }
        }
        for(auto x:comp){
        	cout<<x<<" ";
		}
		cout<<endl;
        cout<<comp.size()-1<<endl;
    }
    return 0;
}
