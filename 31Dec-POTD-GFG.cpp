class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) 
    {
        if(arr.size()==0) return 0;
        int maxi=0;
        unordered_set<int>st(arr.begin(),arr.end());
        for(int num:st)
        {
            if(st.find(num-1)==st.end())
            {
                int currentnum=num;
                int currentcount=1;
                
                while(st.find(currentnum+1)!=st.end())
                {
                    currentcount++;
                    currentnum++;
                }
                maxi=max(maxi,currentcount);
            }
            
        }
        return maxi;
    }
};