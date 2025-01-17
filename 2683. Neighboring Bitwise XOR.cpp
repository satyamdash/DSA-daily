using namespace std;
#include<vector>
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int n=derived.size();
        vector<int>Ans(n,0);

        int xor1=0;
        for(int i=0;i<n;i++)
        {
           xor1^=derived[i];
        }

        if(xor1==1)
        {
            return false;
        }
        return true;

    }
};