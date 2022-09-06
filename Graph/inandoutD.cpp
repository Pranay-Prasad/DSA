#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
const int N = 1e5 + 5;
vi adj[N];
void solve(int n)
{
    vector<int> out;
    for (int i = 1; i <= n; i++)
    {
        out.push_back(adj[i].size());
    }
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    For(i, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    solve(n);
    return 0;
}