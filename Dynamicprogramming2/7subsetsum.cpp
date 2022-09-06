#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 5,s = 5;
	int arr[n] = {1,2,3,4,5};
	int dp[n+1][s+1];
	For(i,s+1){
		dp[0][i] = false;
	}
	For(i,n+1){
		dp[i][0] = true;
	}
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= s;j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	For(i,n+1){
		For(j,s+1){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}
