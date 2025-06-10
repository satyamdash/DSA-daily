using namespace std;
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
class Solution {
public:
     unordered_map<int,int>mpp;
    int maxDifference(string s) {
        for(auto &ch:s)
        {
            mpp[ch-'a']++;
        }
        int even_min=9999999;
        int odd_max=-1;

        for(auto &it:mpp)
        {
            if(it.second%2==0)
            {
                if(it.second<even_min)
                {
                    even_min=it.second;
                }
            }
            else
            {
                if(it.second>odd_max)
                {
                    odd_max=it.second;
                }
            }
        }

        return odd_max-even_min;
    }
};