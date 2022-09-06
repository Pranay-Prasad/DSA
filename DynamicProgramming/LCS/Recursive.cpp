#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int LCS(string x,string y,int a,int b)
{
    if(a == 0 || b == 0)
        return 0;
    if(x[a] == y[b])
        return 1+LCS(x,y,a-1,b-1);
    else
        return max(LCS(x,y,a-1,b),LCS(x,y,a,b-1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x = "abcdefgr";
    string y = "abcduifghr";
    int a = x.size();
    int b = y.size();
    cout<<LCS(x,y,a,b)<<endl;
    return 0;
}