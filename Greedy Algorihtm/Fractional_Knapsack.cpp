#include <bits/stdc++.h>
bool comp(pair<int, int> item1, pair<int, int> item2)
{
    double r1 = (double)item1.second / (double)item1.first;
    double r2 = (double)item2.second / (double)item2.first;
    return (r1 > r2);
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    double ans = 0;
    int i = 0;
    sort(items.begin(), items.end(), comp);
    while (w && i < n)
    {
        if (items[i].first <= w)
        {
            ans += items[i].second;
            w -= items[i].first;
        }
        else
        {
            // int diff=w-items[i].second;
            ans += (w * (double)items[i].second) / (double)items[i].first;
            break;
        }
        i++;
    }
    return ans;
}
// Time Complexity: O(nlogn)
// Space Complexity: O(1);