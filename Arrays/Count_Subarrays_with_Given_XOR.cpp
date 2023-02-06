int subarraysXor(vector<int> &arr, int x)
{
    map<int, int> freq;
    int count = 0;
    int xorr = 0;
    for (auto it : arr)
    {
        xorr = xorr ^ it;
        if (xorr == x)
        {
            count++;
        }
        if (freq.find(xorr ^ x) != freq.end())
        {
            count += freq[xorr ^ x];
        }
        freq[xorr] += 1;
    }
    return count;
}
// Time Complexity: O(nlog)
// Space Complexity: O(n)