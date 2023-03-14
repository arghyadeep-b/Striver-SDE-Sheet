#include <bits/stdc++.h>
double multiply(double m, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= m;
    }
    return ans;
}
double findNthRootOfM(int n, int m)
{
    double i = 0, j = m;
    double mid = 0.0;

    while (j - i > 1e-7)
    {
        mid = (i + j) / 2.0;
        if (multiply(mid, n) > m)
        {
            j = mid;
        }
        else
        {
            i = mid;
        }
    }
    return i;
}
// Time Complexity: O(n*log(m* 10^6))
// Space Complexity: O(1)