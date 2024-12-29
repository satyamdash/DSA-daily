class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) 
    {
        if(a.size()>b.size())
        {
            return intersectionWithDuplicates(b,a);
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int>Ans;
        
        int l1=0;
        int l2=0;
        
        while(l1 < a.size() && l2 < b.size())
        {
            if(a[l1]==b[l2])
            {
                 if (Ans.empty() || Ans.back() != a[l1]) {
                    Ans.push_back(a[l1]);
                }
                l1++;
                l2++;
            }
            else if(a[l1]<b[l2])
            {
                l1++;
            }
            else
            {
                l2++;
            }
            
        }
        
        return Ans;
    
    }
};