#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int dp[100][100];
void solve(int arr[],int diff,int n)
{
    int sum = 0;
    For(i,n)
        sum += arr[i];
    int minSum = (sum + diff)/2;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1; j <= minSum;j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int ans = 0;
    for(int i = 0;i <= n;i++)
    {
        if(dp[i][minSum] == true)
            ans++;
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    For(i,100)
        dp[i][0] = true;
    For(i,100)
        dp[0][i] = false;
    dp[0][0] = true;
    int arr[4] = {1,1,2,3};
    int diff = 1;
    solve(arr,diff,4);
    return 0;
}