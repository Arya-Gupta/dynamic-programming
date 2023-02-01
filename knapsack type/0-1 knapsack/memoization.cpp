#include <bits/stdc++.h>
using namespace std;

int solve(int W, vector<int> wt, vector<int> val, int n, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (dp[W][n] != -1)
    {
        return dp[W][n];
    }
    if (wt[n - 1] > W)
    {
        return dp[W][n] = solve(W, wt, val, n - 1, dp);
    }
    return dp[W][n] = max(solve(W, wt, val, n - 1, dp), val[n - 1] + solve(W - wt[n - 1], wt, val, n - 1, dp));
}

int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
    return solve(W, wt, val, n, dp);
}

int main()
{
    int n, w;
    cout << "n = ";
    cin >> n;
    cout << "capacity of knapsack W = ";
    cin >> w;
    vector<int> val(n);
    vector<int> wt(n);

    cout << "Enter the values: " << endl;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    cout << "Enter the weights: " << endl;
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Maximum total value in knapsack is " << knapSack(w, wt, val, n);
}
