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
    
    int val = isSubsetSum(arr, sum, n);
    if(val == 1) cout << "Yes";
    else cout << "No";
}