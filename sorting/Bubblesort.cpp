#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
1> Scan the array and compare the element with next element
2> if greater swap them
Time complexity = O(n^2)

*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 6;
    int arr[n] = {2, 7, 4, 1, 5, 3};
    for (int i = 0; i < n; i++)
    {
        bool flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}