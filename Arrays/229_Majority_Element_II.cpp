class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int num1 = 0, num2 = 0;
        int c1 = 0, c2 = 0;
        for (auto it : nums)
        {
            if (num1 == it)
                c1++;
            else if (num2 == it)
                c2++;
            else if (c1 == 0)
            {
                num1 = it;
                c1 = 1;
            }
            else if (c2 == 0)
            {
                num2 = it;
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        int count1 = 0, count2 = 0;
        int n = nums.size();
        for (auto it : nums)
        {
            if (it == num1)
                count1++;
            else if (it == num2)
                count2++;
        }
        if (count1 > n / 3)
            ans.push_back(num1);
        if (count2 > n / 3)
            ans.push_back(num2);

        return ans;
    }
};
// Time Complexity: O(n)+O(n)
// Space Complexity: O(1)