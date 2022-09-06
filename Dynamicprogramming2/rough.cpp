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
    vector<vector<int>>vec;
    vec.push_back({3,7,3});
    vec.push_back({2,5,1});
    vec.push_back({1,5,2});
    sort(vec.begin(),vec.end());
    for(auto x:vec){
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    }
    return 0;
}