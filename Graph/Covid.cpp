#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a) for (int i = 0; i < a; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    int one = 0;
    vector<pair<int,int>>zero;
    FOR(i,n)
    {
        FOR(j,m)
        {
            cin>>mat[i][j];
            if(mat[i][j] == 1)
                one++;
            else if(mat[i][j] == 0)
                zero.push_back({i,j});
        }
    }
    int ans = 0;
    int idx = 0;
    while (one > 0)
    {
        cout<<zero[idx].first<<" "<<zero[idx].second<<endl;
        int i = zero[idx].first;
        int j = zero[idx].second;
        if(mat[i-1][j] == 1)
        {
            mat[i-1][j] = 0;
            one--;
        }
        if(mat[i-1][j-1] == 1)
        {
            mat[i-1][j-1] = 0;
            one--;
        }
        if(mat[i][j+1] == 1)
        {
            mat[i][j+1] = 0;
            one--;
        }
        if(mat[i+1][j+1] == 1)
        {
            mat[i+1][j+1] = 0;
            one--;
        }
        ans++;
        idx++;
    }
    
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}