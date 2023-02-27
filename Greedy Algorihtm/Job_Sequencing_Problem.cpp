#include <bits/stdc++.h>
bool comparator(vector<int> j1, vector<int> j2)
{
    return (j1[1] > j2[1]);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comparator);
    int n = jobs.size();
    int maxDL = 0;
    for (int i = 0; i < n; i++)
    {
        maxDL = max(maxDL, jobs[i][0]);
    }
    int arr[maxDL + 1];
    for (int i = 0; i <= maxDL; i++)
    {
        arr[i] = -1;
    }
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i][0]; j >= 1; j--)
        {
            if (arr[j] == -1)
            {
                arr[j] = i;
                profit += jobs[i][1];
                break;
            }
        }
    }
    return profit;
}
// Time Complexity: O(nlogn)+O(n*m)
// Space Complexity:O(M), M= maxDeadline