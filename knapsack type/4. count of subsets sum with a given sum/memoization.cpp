#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int sum, int n, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    if (dp[sum][n] != -1)
    {
        return dp[sum][n];
    }
    if (arr[n - 1] > sum)
    {
        return dp[sum][n] = solve(arr, sum, n - 1, dp);
    }
    else if (arr[n - 1] <= sum)
    {
        return dp[sum][n] = solve(arr, sum, n - 1, dp) + solve(arr, sum - arr[n - 1], n - 1, dp);
    }
}

int count(vector<int> arr, int sum, int n)
{
    vector<vector<int>> dp(sum + 1, vector<int>(n + 1, -1));
    return solve(arr, sum, n, dp);
}

int main()
{
    int N, X;
    cout << "N = ";
    cin >> N;
    vector<int> arr(N);
    cout << "Enter the values: " << endl;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << "X = ";
    cin >> X;
    cout << "There are " << count(arr, X, N) << " possible subsets with sum " << X;
}