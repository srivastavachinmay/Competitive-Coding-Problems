#include <bits/stdc++.h>
using namespace std;

bool lcs(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m]==n?true:false;
}

int main()
{
    string x = "AXY";
    string y = "ADXCPY";
    int n = x.length();
    int m = y.length();
    cout << lcs(x, y, n, m);
}