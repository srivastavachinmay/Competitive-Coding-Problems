#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

static int dp[1001][1001]; //n=101,cap=1001 constraints will be given in the question

int knapsack(int wt[], int val[], int cap, int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < cap + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][cap];
}
int main()
{
    int val[] = {1, 3, 4, 5, 7};
    int wt[] = {1, 5, 3, 7, 4};
    int cap = 10;
    int n = 5;

    cout << knapsack(wt, val, cap, n) << endl;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}