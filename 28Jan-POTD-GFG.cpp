class Solution {
  public:
    
    void FindPerm(int i,vector<bool>&used,string &s,unordered_set<string>&st,string curr)
    {
        if(i==s.size())
        {
            st.insert(curr);
        }
        
        for(int j=0;j<s.size();j++)
        {
            if(!used[j])
            {
                used[j]=true;
                curr.push_back(s[j]);
                FindPerm(i+1,used,s,st,curr);
                
                used[j]=false;
                curr.pop_back();
                
            }
        }
        
    }
    
    vector<string> findPermutation(string &s) 
    {
        unordered_set<string>st;
        vector<bool>used(s.size(),false);
        string curr;
        FindPerm(0,used,s,st,curr);
        vector<string>Ans(st.begin(),st.end());
        
        
        return Ans;
    }
};