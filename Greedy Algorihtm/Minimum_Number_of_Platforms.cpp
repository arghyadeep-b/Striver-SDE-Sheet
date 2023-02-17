int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);
    int i = 1, j = 0;
    int plat = 1, maxi = 1;
    while (i < n)
    {
        if (dt[j] >= at[i])
        {
            plat++;
            maxi = max(plat, maxi);
            i++;
        }
        else
        {
            plat--;
            j++;
        }
    }
    return maxi;
}
// Time Complexity: O(2nlogn)+O(2n)
// Space Complexity: O(1)