#include<unordered_map>

int totalStrings(string s) 
{
    unordered_map<char,int>mpp;
    
    int n =s.length();
    int left=0,result=0;
    for(int right=0;right<n;right++)
    {
        mpp[s[right]]++;

        while(mpp.size()>2)
        {
            mpp[s[left]]--;
            if(mpp[s[left]]==0)
            {
                mpp.erase(s[left]);
            }
            left++;
        }
        result+=right-left+1;
    }

    return result;
}