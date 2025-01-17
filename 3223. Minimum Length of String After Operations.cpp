using namespace std;
#include<unordered_map>
#include<string>
class Solution {
public:
    int minimumLength(string s) 
    {
        unordered_map<char,int>mpp;

        for(auto ch:s)
        {
            mpp[ch]++;
        }

        int deletecount=0;

        for(auto pair:mpp)
        {
            int freq=pair.second;

            if(freq%2==1)
            {
                deletecount+=freq-1;
            }
            else
            {
                deletecount+=freq-2;
            }
        }

        return s.size()-deletecount;
    }
};