#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int dp[1001][1001];
int solve(string x,string y,int l)
{
    For(i,1001)
        dp[i][0] = 0;
    For(i,1001)
        dp[0][i] = 0;
    if(l == 0 )
        return 0;
    for(int i = 1; i<= l;i++)
    {
        for(int j = 1; j<=l;j++)
        {
            if(x[i-1] == y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[l][l];
}
//cabcbcad
//dacbcbac
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    string b = s;
    reverse(b.begin(),b.end());
    int l = s.length();
    cout<<solve(s,b,l)<<endl;
    return 0;
}