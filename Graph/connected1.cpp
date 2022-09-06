#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
vector<bool> vis;
vector<vector<int>> adj;
vector<int> comp;
int get_comp(int idx)
{
    if (vis[idx])
    {
        return 0;
    }
    vis[idx] = true;
    int ans = 1;
    for (auto i : adj[idx])
    {
        if (!vis[i])
        {
            ans += get_comp(i);
            vis[i] = true;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, 0);
    For(i, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    For(i, n)
    {
        if (!vis[i])
        {
            comp.push_back(get_comp(i));
        }
    }
    // for(auto i : comp)
    // {
    //     cout<<i<<" ";
    // }
    ll ans = 0;
    for (auto i : comp)
    {
        ans += i * (n - i);
    }
    cout << (ans / 2) << endl;
    return 0;
}