class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1;
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (count == 0)
            {
                num = nums[i];
            }
            if (num != nums[i])
            {
                count--;
            }
            else
            {
                count++;
            }
        }
        return num;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)