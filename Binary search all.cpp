#include<bits/stdc++.h>
#define n 5
using namespace std;
int main()
{
    int target,lo,hi;

    //binary_search

    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(mid==target)
        {
            return mid;
        }
        else if(mid>target)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    //minimum x when f[x] is true when the sequence is F F F T T ...
    lo = 0, hi = n + 1;
    /// always take lo 1 smaller and hi 1 greater. Because for this cases:
    /// when lo = n - 1, hi = n and mid = lo + (hi - lo) / 2 = n - 1, then If
    /// mid = false then lo = n and the while loop condition is false. So, n is
    /// not checked. Here initially hi = n + 1 necessary.
    /// when lo = 1, hi = 2 and mid = lo + (hi - lo + 1) / 2 = 2, then If
    /// mid = false then hi = 1 and the while loop condition is false. So, 1 is
    /// not checked. Here initially lo = 0 necessary.
    while(lo<hi)
    {
        int mid=lo+(hi-lo)/2;
        if(mid==true)
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    //if a[lo]!=target then no such x for which f[x] is true.
    //here lo is the minimum x for which f[x] is true.

    //maximum x when f[x] is false when the sequence is F F F T T ...

    while(lo<hi)
    {
        int mid=lo+(hi-lo+1)/2;
        if(mid==true)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid;
        }
    }
    //if a[lo]!=target then no such x for which f[x] is false.
    //here lo is the maximum x for which f[x] is false.

    //If we want to avoid above implementation then we can use an extra
    //variable to store the optimal ans.Here we always use mid-1/mid+1 on
    //true/false both condition and use while(l<=r) and mid=lo+(hi-lo)/2
}
