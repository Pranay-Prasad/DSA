#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int dp[101][101]; //memoized
int solve(int e,int f)
{
    memset(dp,-1,sizeof(dp));
    if(f == 0 || f == 1)
        return f;
    if(e == 1)
        return f;
    int ans = INT_MAX;
    if(dp[e][f] != -1) //memoized
        return dp[e][f];
    for(int k = 1 ; k <= f ;k++)
    {
        int low,high;
        if(dp[e-1][k-1] != -1)
            low = dp[e-1][k-1];
        else
        {
            low = solve(e-1,k-1);
            dp[e-1][k-1] = low;
        }
        if(dp[e][f-k] != -1)
            high = dp[e][f-k];
        else
        {
            high = solve(e,f-k);
            dp[e][f-k] = high;
        }
        int temp = 1 + max(low,high);
        ans = min(ans,temp);
    }
    return dp[e][f] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int f,e;
    cin>>f>>e;
    cout<<solve(e,f)<<endl;
    return 0;
}