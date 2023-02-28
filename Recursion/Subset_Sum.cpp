#include <bits/stdc++.h>
void subsetSumHelper(int ind, vector<int> &num, int n, vector<int> &ans, int sum)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }
    subsetSumHelper(ind + 1, num, n, ans, sum + num[ind]); // pick
    subsetSumHelper(ind + 1, num, n, ans, sum);            // not picked
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    subsetSumHelper(0, num, num.size(), ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
// Time Complexity: O(2^n)+O(2^n log(2^n))
// Space Complexity: O(2^n)