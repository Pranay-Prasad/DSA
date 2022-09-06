#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
bool dp[1000][1000];
int solve(vi ar)
{
    int sum = 0;
    For(i,ar.size())
        sum += ar[i];
    for (int i = 1; i <= ar.size(); i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(ar[i-1] <= j)
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-ar[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    vi range;
    for(int i = 0; i <= sum;i++)
    {
        if(dp[ar.size()][i] == true)
            range.push_back(i);
    }
    int ans = INT_MAX;
    for(int i = 0; i < range.size()/2;i++)
        ans = min(ans,sum - 2*range[i]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    For(i,1000)
        dp[i][0] = true;
    For(i,1000)
        dp[0][i] = false;
    dp[0][0] = true;
    vi ar{1,2,7};
    cout<<solve(ar)<<endl;
    return 0;
}