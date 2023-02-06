class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> dict(256, -1);
        int len = 0;
        int n = s.size();
        int left = 0, right = 0;
        while (right < n)
        {
            if (dict[s[right]] != -1)
            {
                left = max(dict[s[right]] + 1, left);
            }

            dict[s[right]] = right;
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)