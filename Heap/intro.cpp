#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a) for (int i = 0; i < a; i++)
void heapify(vector<int> &a, int n, int i)
{
    int max_ind = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[max_ind])
    {
        max_ind = l;
    }
    if (r < n && a[r] > a[max_ind])
    {
        max_ind = r;
    }
    if (max_ind != i)
    {
        swap(a[i], a[max_ind]);
        heapify(a, n, max_ind);
    }
}
void heapsort(vector<int> &a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    heapsort(a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}