class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
        {
            return intervals;
        }
        vector<vector<int>> ans;
        vector<int> row;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int j = 1; j < intervals.size(); j++)
        {
            if (intervals[j][0] < start && intervals[j][1] > end)
            {
                start = intervals[j][0];
            }
            if (intervals[j][0] <= end && end <= intervals[j][1])
            {
                end = intervals[j][1];
            }
            else if (intervals[j][0] > end)
            {
                row.push_back(start);
                row.push_back(end);

                ans.push_back(row);
                row.clear();
                start = intervals[j][0];
                end = intervals[j][1];
            }
        }
        row.push_back(start);
        row.push_back(end);

        ans.push_back(row);
        return ans;
    }
    // Time Complexity: O(n)
    // Space Complexity: O(n^2)
};