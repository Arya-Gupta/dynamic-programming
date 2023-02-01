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
    return dp[sum][n] = solve(arr, sum, n - 1, dp) || solve(arr, sum - arr[n - 1], n - 1, dp);
}

bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(sum + 1, vector<int>(n + 1, -1));
    return solve(arr, sum, n, dp);
}

int main()
{
    int n, sum;
    cout << "Enter sum: ";
    cin >> sum;
    cout << "Enter the length of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter numbers in array:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int val = isSubsetSum(arr, sum);
    if(val == 1) cout << "Yes";
    else cout << "No";
}