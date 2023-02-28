class Solution
{
    void palindromeGenerator(int ind, string s, vector<vector<string>> &ans, vector<string> &ds)
    {
        if (ind == s.length())
        {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < s.length(); i++)
        {
            if (isPalindrome(s, ind, i))
            {
                ds.push_back(s.substr(ind, i - ind + 1));

                palindromeGenerator(i + 1, s, ans, ds);
                ds.pop_back();
            }
        }
    }
    bool isPalindrome(string str, int start, int end)
    {
        while (start <= end)
        {
            if (str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> ds;
        palindromeGenerator(0, s, ans, ds);
        return ans;
    }
};
// Time Complexity: O(2^n *k *(n/2))
// Space Complexity: O(k*x)