/*  https://leetcode.com/problems/first-bad-version/  */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) 
{
    if(n == 0) return 1;
    long long int l = 0, r = n - 1;
    while(l <= r)
    {
        long long int mid = (l + r) / 2;
        if(isBadVersion(mid)) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
