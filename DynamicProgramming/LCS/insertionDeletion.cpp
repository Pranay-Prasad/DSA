#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
int dp[1001][1001];
void operation(string x, string y, int a, int b)
{
    int insert, del;
    int maxx = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 0;
        }
    }
    For(i, a + 1)
    {
        For(j, b + 1)
        {
            maxx = max(maxx, dp[i][j]);
        }
    }
    if(a == 1 && b == 1)
    {
        if(x[a-1] == y[b-1])
            maxx = 1;
        else
            maxx = 0;
    }
    cout<<a<<" "<<b<<" "<<maxx<<endl;
    del = a - maxx;
    insert = b - maxx;
    cout << insert << " " << del << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    For(i, 1001)
        dp[i][0] = 0;
    For(i, 1001)
        dp[0][i] = 0;
    string x, y;
    cin >> x >> y;
    int a = x.length();
    int b = y.length();
    operation(x, y, a, b);
    For(i,a+1)
    {
        For(j,b+1)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}