#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
bool dp[1000][1000];
bool solve(vi arr)
{
    int sum = 0;
    for(int i = 0; i < arr.size();i++)
        sum += arr[i];
    if(sum % 2 != 0)
        return false;
    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 1; j <= sum/2; j++)
        {
            if(arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
        }
    }
    return dp[arr.size()][sum/2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if(j == 0)
                dp[i][j] = false;
            else if(i == 0)
                dp[i][j] = true;
        }
        
    }
    dp[0][0] = true;
    vi arr{1,5,3};
    bool ans = solve(arr);
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}