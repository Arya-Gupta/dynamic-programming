// TC - O(2^N) because we have a choice to choose or not choose each of the N elements
// SC - O(N) stack space

#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    return max(knapSack(W, wt, val, n - 1), val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1));
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
