class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, long target)
    {
        vector<vector<int>> res;
        if (nums.empty())
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            long target_3 = target - nums[i];
            for (int j = i + 1; j < n - 2; j++)
            {

                long target_2 = target_3 - nums[j];

                int front = j + 1;
                int back = n - 1;
                while (front < back)
                {
                    long two_sum = nums[front] + nums[back];
                    if (two_sum < target_2)
                    {
                        front++;
                    }
                    else if (two_sum > target_2)
                    {
                        back--;
                    }
                    else
                    {

                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];

                        res.push_back(quad);

                        // Skipping duplicates of number3
                        while (front < back && nums[front] == quad[2])
                            ++front;
                        // Skipping duplicates of number4
                        while (front < back && nums[back] == quad[3])
                            --back;
                    }
                }
                // Skipping duplicates of number2
                while (j + 1 < n && nums[j + 1] == nums[j])
                    ++j;
            }
            // Skipping duplicates of number1
            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};
// Time Complexity: O(n^3)
// Space Complexity: O(1)