class Solution {
public:
    
    int differenceOfSums(int n, int m) {
        int totalsum=(n*(n+1))/2;
        if(m>n) return totalsum;
        int k=n/m;
        return totalsum-m*(k*(k+1));

    }
};