using namespace std;
#include<vector>
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>vec;
        int n1=nums1.size();
        int n2=nums2.size();

        int xor1=0;
        int xor2=0;
        for(auto num:nums1)
        {
            xor1^=num;
        }

        for(auto num:nums2)
        {
            xor2^=num;
        }

        int result=0;

        if(nums2.size()%2==1)
        {
            result^=xor1;
        }

        if(nums1.size()%2==1)
        {
            result^=xor2;
        }
        return result;
    }
};