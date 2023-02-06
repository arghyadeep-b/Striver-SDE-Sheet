class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int count = 0, maxCount = 0;
        set<int> hashSet;
        for (auto it : nums)
        {
            hashSet.insert(it);
        }
        for (auto it : nums)
        {
            if (!hashSet.count(it - 1))
            {
                count = 1;
                int curr_it = it;
                while (hashSet.count(curr_it + 1))
                {
                    count++;
                    curr_it++;
                }
                maxCount = max(count, maxCount);
            }
        }
        return maxCount;
    }
};
// Time Complexity: O(n)+O(n)+O(n)
// Space Complexity: O(n)