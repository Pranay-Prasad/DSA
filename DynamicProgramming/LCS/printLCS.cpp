#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int dp[1001][1001];
string LCS(string x,string y,int a,int b)
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
    int i = a,j = b;
    string ans;
    while (i != 0 && j != 0)
    {
        if(x[i-1] == y[j-1])
        {
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            ans.push_back(x[i-1]);
            ans.push_back(y[i-1]);
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,y;
    cin>>x>>y;
    int a = x.length();
    int b = y.length();
    cout<<LCS(x,y,a,b)<<endl;
    return 0;
}