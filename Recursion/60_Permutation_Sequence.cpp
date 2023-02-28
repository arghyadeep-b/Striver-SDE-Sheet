class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k = k - 1;
        while (true)
        {
            ans = ans + to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if (nums.size() == 0)
                break;

            k = k % fact;
            fact /= nums.size();
        } // The loop is taken in such a form as, if nums.size() becomes 0 inside the loop dividing fact by 0 would give error
        return ans;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)