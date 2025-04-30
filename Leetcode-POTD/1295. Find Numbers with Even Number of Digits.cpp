class Solution {
public:
    bool isevenDigits(int num)
    {
        int digits=0;
        while(num>0)
        {
            num=num/10;
            digits++;
        }

        if(digits%2==0) return true;

        return false;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto &num:nums)
        {
            if(isevenDigits(num))
            {
                count++;
            }
        }

        return count;
        
    }
};