#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
void solve(vector<vector<int>> adj, vector<int> &col, vector<bool> &vis, bool &valid, int d, int s)
{
    if (col[d] != -1 && col[d] != s)
    {
        valid = false;
        return;
    }
    col[d] = s;
    if (vis[d])
        return;
    vis[d] = true;
    for (auto x : adj[d])
        solve(adj, col, vis, valid, x, s xor 1);
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
        vector<int> col(n+1, -1);
        vector<bool> vis(n+1, false);
        bool valid = true;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                solve(adj, col, vis, valid, i, 0);
        }
        if (valid)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}