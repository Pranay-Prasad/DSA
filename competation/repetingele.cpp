#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int vec[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    const int N = 1e5 + 2;
    int idx[N];
    for (int i = 0; i < n; i++)
    {
        idx[i] = -1;
    }
    int min_in = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (idx[vec[i]] != -1)
        {
            min_in = min(min_in, idx[vec[i]]);
        }
        else
        {
            idx[vec[i]] = i;
        }
    }
    if (min_in == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << min_in + 1 << endl;
    }
    return 0;
}