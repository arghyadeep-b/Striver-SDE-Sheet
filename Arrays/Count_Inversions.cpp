#include <bits/stdc++.h>
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
    long long count_inv = 0;
    long long i = left;
    long long j = mid;
    long long k = left;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count_inv += (mid - i); // Since all the elements in the left subarray from i will be greater
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (long long i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return count_inv;
}
long long mergeSort(long long arr[], long long temp[], long long left, long long right)
{
    long long mid, count_inv = 0;
    if (right > left)
    {
        mid = (left + right) / 2;

        count_inv += mergeSort(arr, temp, left, mid);
        count_inv += mergeSort(arr, temp, mid + 1, right);

        count_inv += merge(arr, temp, left, mid + 1, right);
    }
    return count_inv;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    long long temp[n];
    long long ans = mergeSort(arr, temp, 0, n - 1);
    return ans;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(n);