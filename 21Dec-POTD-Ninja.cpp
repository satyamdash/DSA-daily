#include <bits/stdc++.h> 
int longestDangerousRange(vector<int>& height, int n)
{   
    int start=0;
    int ans=1;
    if(n<=2) return n;

    for(int end=1;end<n;end++)
    {
        if(end>1 &&
            ((height[end-2]<height[end-1] && height[end-1]>height[end]) || 
        (height[end-2]>height[end-1] && height[end-1]<height[end])))
        {
            ans=max(ans,end-start+1);
        }
        else if(height[end]==height[end-1])
        {
            start=end;
        }
        else
        {
            start=end-1;
        }
        ans=max(ans,end-start+1);
    }
    return ans;

}