class Solution {
public:
    
    int Divisible(int n, int m)
    {
        int result=0;
        for(int i=1;i<=n;i++)
        {
            if(i%m==0)
            {
                result+=i;
            }
        }
        return result;
    }
    int differenceOfSums(int n, int m) {
        int totalsum=(n*(n+1))/2;
        if(m>n) return totalsum;
        int sum=Divisible(n,m);

        return totalsum-2*sum;

    }
};