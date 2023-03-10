class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for (auto it : nums)
        {
            sum += it;
            maxi = max(sum, maxi);
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxi;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)