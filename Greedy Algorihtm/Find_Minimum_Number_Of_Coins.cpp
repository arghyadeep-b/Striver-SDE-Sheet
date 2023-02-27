#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    int coins[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int i = 0;
    int count = 0;
    while (amount)
    {
        if (amount >= coins[i])
        {
            amount -= coins[i];
            count++;
        }
        else
        {
            i++;
        }
    }
    return count;
}
// Time Complexity: O(n)
// Space Complexity: O(1)