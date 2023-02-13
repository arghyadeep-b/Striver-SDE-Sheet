class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxi = 0, count = 0;
        for (auto it : nums)
        {
            if (it != 1)
            {
                count = 0;
            }
            else
            {
                count++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)