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
    // set<int>s;
    // multiset<int>s;
    unordered_set<int>s;
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(5);
    for(auto i : s)
        cout<<i<<" ";
    cout<<endl;
    s.erase(s.find(3));
    for(auto i : s)
        cout<<i<<" ";
    return 0;
}