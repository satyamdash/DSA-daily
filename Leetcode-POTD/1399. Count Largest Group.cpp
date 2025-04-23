class Solution {
public:
    int sumofDigits(int num)
    {
        int tt=0;
        while(num>0)
        {
            tt+=num%10;
            num=num/10;
        }
        return tt;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mpp;
        int maxsize=0;
        for(int i=1;i<=n;i++)
        {
            int sum=sumofDigits(i);
            mpp[sum]++;
            maxsize=max(maxsize,mpp[sum]);
        }
        int count=0;
        for(auto pair:mpp)
        {
            if(pair.second==maxsize)
            {
                count++;
            }
        }
       

        return count;

    }
};