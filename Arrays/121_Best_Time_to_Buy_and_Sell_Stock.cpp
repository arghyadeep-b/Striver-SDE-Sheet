class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, min = prices[0], maxi = prices[0];
        int r = 1, l = 0;
        while (r < prices.size())
        {
            if (prices[r] < min)
            {
                min = prices[r];
                l = r;
                maxi = min;
            }
            else if (prices[r] > maxi)
            {
                maxi = prices[r];
            }
            ans = max(ans, (maxi - min));
            r++;
        }
        return ans;
    }
};
// Time Complexity- O(n)
// Space Complexity- O(1)