#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int num[] = {1,2,3};
int solve(int n)
{
    int dp[n+1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(auto x : num)
        {
            // cout<<dp[i-x]<<endl;
            dp[i+x] += dp[i];
        } 
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}