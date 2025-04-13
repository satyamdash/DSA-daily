class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; // even indices: 0, 2, 4...
        long long oddCount = n / 2;        // odd indices: 1, 3, 5...

        long long result = modPow(5, evenCount, MOD) * modPow(4, oddCount, MOD) % MOD;
        return (int)result;
    }
};