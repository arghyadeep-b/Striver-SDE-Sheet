class Solution
{
    void findSubsets(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
    {
        ans.push_back(ds);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ans, ds);
        return ans;
    }
};
// Time Complexity: O(2^n * n) ; 2^n for recursion, n for coping it into ds
// Space Complexity: O(2^n * k) ; k = avg length of each subset