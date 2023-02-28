class Solution
{
    void combinationGenerator(int ind, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds, int target, int sum)
    {
        if (sum == target)
        {
            ans.push_back(ds);
            return;
        }
        if (ind == candidates.size())
        {
            return;
        }
        if (sum > target)
        {
            return;
        }
        else
        {
            ds.push_back(candidates[ind]);
            combinationGenerator(ind, candidates, ans, ds, target, sum + candidates[ind]);
            ds.pop_back();
        }
        combinationGenerator(ind + 1, candidates, ans, ds, target, sum);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        combinationGenerator(0, candidates, ans, ds, target, 0);
        return ans;
    }
};
// Time Complexity: O(2^t * k); k:= avg length, t:=target
// Space Complexity: O(k*n);  n:= no. of combinations