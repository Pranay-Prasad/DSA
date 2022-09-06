#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
const int N = 1e5,mod = 1e9 + 7;
vector<int>dp(N,mod);
int solve(int x)
{
    if(x <= 3)
        return x;
    if(dp[x] != mod)
        return dp[x];
    for(int i = 1; i*i <= x; i++)
    {
        dp[x] = min(dp[x],1 + solve(x-i*i));
    }
    return dp[x];
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