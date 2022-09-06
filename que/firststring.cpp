#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // string str = "adsfjdgfdfygdst";
    // transform(str.begin(),str.end(),str.begin(),::toupper);
    // cout<<str<<endl;
    // string s = "31626";
    // sort(s.begin(),s.end(),greater<int>());
    // cout<<s<<endl;
    string s = "hscdddfsgausdbjasug";
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < 26; i++)
    {
        freq[s[i]-'a']++;
    }
    char ans = 'a';
    int maxF = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxF)
        {
            maxF = freq[i];
            ans = i+'a';
        }
        
    }
    cout<<ans<<" "<<maxF<<endl;
    return 0;
}