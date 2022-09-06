#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
void print(vector<int> edges[], int n, int sv, bool *vis)
{
    cout << sv << " ";
    vis[sv] = true;
    For(i, n)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (!vis[i])
                print(edges, n, i, vis);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int e;
    cin >> n >> e;
    int m = n;
    vector<int> edges[m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
            cout << "FOR" << endl;
        }
    }
    for (int i = 0; i < e; i++)
    {
        cout << "for" << endl;
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *vis = new bool[n];
    For(i, n)
    {
        vis[i] = false;
    }
    print(edges, n, 0, vis);
    return 0;
}