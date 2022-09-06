//knapsack using recursion
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
int knapsack(int val[], int w[], int W, int n)
{
    vi ans;
    if (n == 0 || W == 0)
        return 0;
    if (w[n-1] > W)
    {
        return knapsack(val, w, W, n - 1);
    }
    else
        return max(val[n-1] + knapsack(val, w, W - w[n-1], n - 1), knapsack(val, w, W, n - 1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int val[5] = {100, 2, 3, 4, 10};
    int weight[5] = {20, 5, 8, 9, 11};
    int W = 20;
    cout << knapsack(val, weight, W, 5) << endl;
    return 0;
}