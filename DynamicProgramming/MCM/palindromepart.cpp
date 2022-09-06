#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
bool isPalindrome(string String, int i, int j)
{
    while (i < j)
    {
        if (String[i] != String[j])
            return false;
        i++;
        j--;
    }
    return true;
}
//Recursion
int solve(string s, int i, int j)
{
    if (i > j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = (solve(s, i, k) + solve(s, k + 1, j)) + 1;
        ans = min(ans, temp);
    }
    return ans;
}
//memoization
int dp[1001][1001];
int solve2(string &s, int i, int j)
{
    memset(dp, -1, sizeof(dp));
    if (i > j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        if (dp[i][k] != -1)
            left = dp[i][k];
        else
        {
            left = solve2(s, i, k);
            dp[i][k] = left;
        }
        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
        {
            right = solve2(s, k + 1, j);
            dp[k + 1][j] = right;
        }
        int temp = (left + right) + 1;
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int i = 0;
    int j = s.length() - 1;
    cout << solve(s, i, j) << endl;
    return 0;
}