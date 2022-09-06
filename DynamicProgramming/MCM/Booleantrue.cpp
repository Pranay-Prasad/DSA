#include <bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<string,int>mp;
int solve(string s, int i, int j, bool is)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (is)
        {
            return s[i] == 'T' ? 1 : 0;
        }
        else
        {
            return s[i] == 'F' ? 1 : 0;
        }
    }
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    if(mp.find(temp) != mp.end())
        return mp[temp];
    int ans;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);
        if (s[k] == '&')
        {
            if (is == true)
                ans = ans + lt * rt;
            else
                ans = ans + lf * rt + lf * rf + lt * rf;
        }
        else if (s[k] == '|')
        {
            if (is == true)
                ans = ans + lt * rt + lf * rt + lt * rf;
            else
                ans = ans + lf * rf;
        }
        else if (s[k] == '^')
        {
            if (is == true)
                ans = ans + lf * rt + lt * rf;
            else
                ans = ans + lf * rf + lt * rt;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mp.clear();
    string s;
    cin >> s;
    int i = 0;
    int j = s.length()-1;
    cout << solve(s, i, j, true) << endl;
    return 0;
}