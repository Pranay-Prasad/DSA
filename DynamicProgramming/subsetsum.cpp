#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
const int N = 1000;
bool dp[N][N];
int solve(int arr[],int n,int w)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 0; i <= w; i++)
        dp[0][i] = false;
    if(n == 0 && w > 0)
        return 0;
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < w+1 ;j++)
        {
            if(arr[i-1] > j )
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }
    for(int i = 0;i <= w;i++)
        cout<<dp[n-1][0]<<" ";
    return dp[n][w];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    For(i,n)
        cin>>arr[i];
    int w = 0;
    For(i,n)
        w += arr[i];
    bool ans = solve(arr,n,w);
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}