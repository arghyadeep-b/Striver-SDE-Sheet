#include <bits/stdc++.h>
#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    sort(arr.begin(), arr.end());
    int m, r;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[0] != 1)
        {
            m = 1;
        }
        else if (arr[i] + 2 == arr[i + 1])
        {
            m = arr[i] + 1;
        }
        if (arr[i] == arr[i + 1])
        {
            r = arr[i];
        }
        if (arr[arr.size() - 1] != n)
        {
            m = n;
        }
    }
    return {m, r};
}
