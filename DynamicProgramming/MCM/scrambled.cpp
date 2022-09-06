#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
unordered_map<string, bool> mp; //memoized
bool solve(string a, string b)
{
    if (a.length() != b.length())
        return false;
    int n = a.length();
    if (a == b || n == 0)
        return true;
    string x = a, y = b;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (x != y)
        return false;
    string key = (a + " " + b);   // memoized
    if (mp.find(key) != mp.end()) //memoized
        return mp[key];
    bool flag = false; //memoized
    for (int i = 1; i < n; i++)
    {
        if (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i)))
        {
            flag = true; //memoized
            return true;
        }
        if (solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i)))
        {
            flag = true; //memoized
            return true;
        }
    }
    mp[key] = flag; // memoized
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x, y;
    cin >> x >> y;
    bool ans = solve(x, y);
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "NO" << endl;
    return 0;
}