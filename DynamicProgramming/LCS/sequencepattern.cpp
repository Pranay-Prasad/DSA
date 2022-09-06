#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int dp[1001][1001];
bool LCS(string x,string y,int a,int b)
{
    For(i,1001)
        dp[i][0] = 0;
    For(i,1001)
        dp[0][i] = 0;
    if(a == 0 || b ==0)
        return 0;
    for(int i = 1; i<= a;i++)
    {
        for(int j = 1; j<=b;j++)
        {
            if(x[i-1] == y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    if(a == dp[a][b])
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,y;
    cin>>x>>y;
    int a = x.length();
    int b = y.length();
    bool ans = LCS(x,y,a,b);
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}