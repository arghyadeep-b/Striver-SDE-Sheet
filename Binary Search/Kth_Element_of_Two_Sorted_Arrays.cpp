int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    if (m > n)
        return ninjaAndLadoos(row2, row1, n, m, k);

    int low = max(0, k - n), high = min(k, m);
    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int left1 = (cut1 == 0) ? -2e9 : row1[cut1 - 1];
        int left2 = (cut2 == 0) ? -2e9 : row2[cut2 - 1];
        int right1 = (cut1 == m) ? 2e9 : row1[cut1];
        int right2 = (cut2 == n) ? 2e9 : row2[cut2];

        if (left1 > right2)
            high = cut1 - 1;
        else if (left2 > right1)
            low = cut1 + 1;
        else
            return max(left1, left2);
    }
    return 0;
}
// Time Complexity: O(log(min(m,n)))
// Space Complexity: O(1)