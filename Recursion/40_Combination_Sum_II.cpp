class Solution
{
    void combinationGenerator(int ind, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds, int target)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < candidates.size(); i++)
        {
            if (i > ind && candidates[i - 1] == candidates[i])
                continue;
            if (candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            combinationGenerator(i + 1, candidates, ans, ds, target - candidates[i]);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        combinationGenerator(0, candidates, ans, ds, target);
        return ans;
    }
};
// Time Complexity: O(2^n * k); k:= avg length of combinations
// Space Complexity: O(k*x); x:= no. of combinations generated