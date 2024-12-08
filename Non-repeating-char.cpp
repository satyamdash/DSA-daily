class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) 
    {
        int n=s.length();
        
        vector<int> freq(256, 0);
        
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(freq[s[i]]==1)
            {
                return s[i];
            }
        }
        return '$';
    }
};