class Solution {
  public:
  
    bool canplace(vector<int> &stalls, int k,int distance)
    {
            int count = 1;  // Place the first cow in the first stall
        int lastPosition = stalls[0];  // Position of the last placed cow
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= distance) {
                count++;  // Place the next cow
                lastPosition = stalls[i];
                if (count == k) return true;  // Successfully placed all cows
            }
        }
        return false;  // Could not place all cows
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        int best=0;
        
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(canplace(stalls,k,mid))
            {
                best=mid;
                low=mid+1;
                
            }
            else
            {
                high=mid-1;
                
            }
        }
        
        return best;
        
    }
};