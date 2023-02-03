class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        nums1.erase(nums1.begin() + m, nums1.end());             // Erasing all zeros
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end()); // Concatenating
        sort(nums1.begin(), nums1.end());

        // Time Complexity: O(n)
        // Space Complexity: O(1)
    }
};