#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> arr, int sum, int n)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (arr[n - 1] > sum)
    {
        return isSubsetSum(arr, sum, n - 1);
    }
    else if (arr[n - 1] <= sum)
    {
        return isSubsetSum(arr, sum, n - 1) || isSubsetSum(arr, sum - arr[n - 1], n - 1);
    }
}

int equalPartition(int N, vector<int> arr)
{
    int sum = 0;
    for (auto i : arr)
        sum += i;
    if (sum % 2)
        return 0;
    return isSubsetSum(arr, sum / 2, arr.size());
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
    if (equalPartition(N, arr))
        cout << "YES";
    else
        cout << "NO";
}