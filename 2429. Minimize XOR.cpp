class Solution {
public:
    static bool comp(const pair<int,int>&a,pair<int,int>&b)
    {
        return a.second<b.second;
    }
    int countsetbits(int n)
    {
        int cnt=0;
        while(n>0)
        {
            if(n&1)
            {
                cnt++;
            }
            n=n>>1;
        }
        return cnt;
    }
    int minimizeXor(int num1, int num2) 
    {
       int targetSetBits = countsetbits(num2); // Count how many set bits num2 has
        int result = 0;                         // This will store the final answer

        // Step 1: Try to use the set bits in num1 (from most significant bit to least significant bit)
        for (int bit = 31; bit >= 0 && targetSetBits > 0; --bit) {
            if (num1 & (1 << bit)) {           // If the current bit in num1 is set (1)
                result |= (1 << bit);          // Set the same bit in the result
                targetSetBits--;               // Reduce the count of required set bits
            }
        }

        // Step 2: If there are still set bits needed, set the remaining bits starting from the least significant bit
        for (int bit = 0; bit < 32 && targetSetBits > 0; ++bit) {
            if (!(result & (1 << bit))) {      // If the current bit in the result is not set (0)
                result |= (1 << bit);          // Set this bit in the result
                targetSetBits--;               // Reduce the count of required set bits
            }
        }

        return result;
    }
};