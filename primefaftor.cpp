//prime factorization using seve
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n != 1)
    {
        int smallest = spf(n);
        cout << smallest << endl;
        n /= smallest;
    }
    return 0;
}
int spf(int n)
{
    if (n % 2 == 0)
    {
        return 2;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return n;
}