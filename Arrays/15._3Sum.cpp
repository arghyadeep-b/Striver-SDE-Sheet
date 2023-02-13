class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int l, r;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            l = i + 1;
            r = n - 1;
            int req = -nums[i];
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum < req)
                {
                    l++;
                }
                else if (sum > req)
                {
                    r--;
                }
                else
                {
                    vector<int> sol = {nums[i], nums[l], nums[r]};
                    ans.push_back(sol);

                    while (l < r && nums[l] == sol[1])
                        l++;
                    while (l < r && nums[r] == sol[2])
                        r--;
                }
            }
            while (i + 1 < n - 2 && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: 3*k //k=no. of triplets