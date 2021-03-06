#include <bits/stdc++.h>
using namespace std;

int mcm(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        mn = min(mn, temp);
    }
    return mn;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int i = 1;
    int j = sizeof(arr) / sizeof(arr[0]) - 1;
    cout << mcm(arr, i, j);
}