#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int sum, int n, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

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
        return dp[sum][n] = solve(arr, sum, n - 1, dp) || solve(arr, sum - arr[n - 1], n - 1, dp);
    }
}

bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(sum + 1, vector<int>(n + 1, -1));
    return solve(arr, sum, n, dp);
}

int equalPartition(int N, vector<int> arr)
{
    int sum = 0;
    for (auto i : arr)
        sum += i;
    if (sum % 2)
        return 0;
    return isSubsetSum(arr, sum / 2);
}

int main()
{
    int N;
    cout << "N = ";
    cin >> N;
    vector<int> arr(N);
    cout << "Enter the values: " << endl;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << equalPartition(N, arr);
}