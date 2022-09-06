#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int dp[1001][1001];
int LCS(string x,string y,int a,int b)
{
    memset(dp,-1,sizeof(dp));
    if(a == 0 || b == 0)
        return 0;
    if(dp[a][b] != -1)
        return dp[a][b];
    if(x[a] == y[b])
        return dp[a][b] = 1+LCS(x,y,a-1,b-1);
    else
        return dp[a][b] = max(LCS(x,y,a-1,b),LCS(x,y,a,b-1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,y;
    cin>>x>>y;
    int a = x.length();
    int b = y.length();
    cout<<" jdfb: "<<x[a-1]<<" ";
    cout<<LCS(x,y,a,b)<<endl;
    
    return 0;
}