#include <bits/stdc++.h>
using namespace std;

int count(vector<int> arr, int sum, int n)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    if (arr[n - 1] > sum)
    {
        return count(arr, sum, n - 1);
    }
    else if (arr[n - 1] <= sum)
    {
        return count(arr, sum, n - 1) + count(arr, sum - arr[n - 1], n - 1);
    }
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