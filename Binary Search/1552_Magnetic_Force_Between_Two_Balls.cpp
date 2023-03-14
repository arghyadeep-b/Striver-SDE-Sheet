// Similar to Aggressive Cows
class Solution
{
    bool isPossible(vector<int> &position, int m, int mid)
    {
        int count = 1;
        int last = position[0];
        for (int i = 1; i < position.size(); i++)
        {
            if (position[i] - last >= mid)
            {
                count++;
                last = position[i];
            }
        }
        return count >= m ? true : false;
    }

public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int low = 1, high = position[position.size() - 1] - position[0];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isPossible(position, m, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
// Time Complexity: O(nlog n)
// Space Complexity: O(1)