class Solution {
public:
    int minDeletions(string str) 
    {
        unordered_map<char,int>mpp;
   for(auto ch:str)
   {
       mpp[ch]++;
   }

    vector<int>frequencies;

    for(auto pair:mpp)
    {
        frequencies.push_back(pair.second);
    }

    sort(frequencies.rbegin(),frequencies.rend());
    int deletions=0;
    int prevfreq=frequencies[0];
    for(int i=1;i<frequencies.size();i++)
    {
        if(frequencies[i]>=prevfreq)
        {
            int newfreq=max(0,prevfreq-1);
            deletions+=frequencies[i]-newfreq;
            prevfreq=newfreq;
        }
        else
        {
           prevfreq=frequencies[i]; 
        }
    }
    return deletions;  
    }
};