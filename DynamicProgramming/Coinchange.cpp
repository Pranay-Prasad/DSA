#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a) for(int i = 0;i<a;i++)
#define For(i,a,b) for(int i = a; i < b ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
int solve(vector<int>&coins,int s){
	int dp[coins.size()+1][s+1];
	FOR(i,coins.size()+1){
		dp[i][0] = 1;
	}
	FOR(i,s+1){
		dp[0][i] = 0;
	}
	for(int i = 1; i <= coins.size();i++){
		for(int j = 1;j <= s;j++){
			if(coins[i-1] <= j){
				dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[coins.size()][s];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,s;
	cin>>n>>s;
	//n == size of array, s = total sum;
	vector<int>coins(n);
	FOR(i,n) cin>>coins[i];
	cout<<solve(coins,s)<<endl;
    return 0;
}

