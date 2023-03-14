// Similar question for Allocate Minimum Number of Pages
class Solution
{
    bool isAllocationPossible(vector<int> &weights, int days, int barrier)
    {
        int need = 1, load = 0;
        for (auto it : weights)
        {
            if (it > barrier)
                return false;
            if (it + load <= barrier)
            {
                load += it;
            }
            else
            {
                need++;
                load = it;
            }
        }
        return need > days ? false : true;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = INT_MAX, high = 0;
        int res;
        for (auto it : weights)
        {
            low = min(low, it);
            high += it;
        }

        while (low < high)
        {
            int mid = (high + low) / 2;
            if (isAllocationPossible(weights, days, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
// Time Complexity: O(nlog n)
// Space ComplexitY: O(1)