#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int dp[1000][1000];
int solve(vi ar,int sum)
{
    int n = ar.size();
    for(int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(ar[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-ar[i-1]];
        }
        
    }
    return dp[n][sum];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    For(i,1000)
        dp[0][i] = 0;
    For(i,1000)
        dp[i][0] = 1;
    // dp[0][0] = 1;
    vi arr{1,2,3};
    int sum = 3;
    cout<<solve(arr,sum)<<endl;
    return 0;
}