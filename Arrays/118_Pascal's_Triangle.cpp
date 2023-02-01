class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    row.push_back(1);
                }
                else
                {
                    int t = ans[i - 1][j - 1] + ans[i - 1][j];
                    row.push_back(t);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
// Time Complexity- O(n^2)
// Space Complexity- O(n^2)