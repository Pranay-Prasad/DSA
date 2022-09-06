//unbounded knapsack
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
int solve(vector<int>&price,vector<int>&length,int n){
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= n;j++){
			if(length[i-1] <= j){
				dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<int>price(n),length(n);
	For(i,n){
		cin>>price[i];
		cin>>length[i];
	}
	cout<<solve(price,length,n);
    return 0;
}
