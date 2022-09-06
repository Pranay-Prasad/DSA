#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
int dp[100][100];
int solve(int val[], int wt[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
        }
    }
    return dp[n][w];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int val[5] = {20, 200, 3, 4, 10};
    int wt[5] = {10, 11, 8, 9, 11};
    int W = 20;
    cout << solve(val, wt, W, 5) << endl;
    return 0;
}