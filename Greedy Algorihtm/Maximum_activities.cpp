//! Concept is correct but code is not working
struct ACT
{
    int s;
    int e;
    int pos;
};
bool static comparator(struct ACT a1, struct ACT a2)
{
    if (a1.e < a2.e)
        return true;
    else if (a1.e > a2.e)
        return false;
    else if (a1.pos < a2.pos)
        return true;
    return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    struct ACT act[n];
    for (int i = 0; i < n; i++)
    {
        act[i].s = start[i];
        act[i].e = finish[i];
        act[i].pos = i + 1;
    }

    sort(act, act + n, comparator);
    int count = 1;
    int limit = act[0].e;
    for (int i = 1; i < n; i++)
    {
        if (act[i].s > limit)
        {
            count++;
            limit = act[i].e;
        }
    }
    return count;
}
// Time Complextiy: O(nlogn)
// Space Complexity: O(n)