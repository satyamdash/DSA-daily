#include <bits/stdc++.h>
using namespace std;

// Function to perform prime factorization and update factor counts
void factorize(int n, unordered_map<int, int>& factorCounts, int sign) {
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factorCounts[i] += sign;
            n /= i;
        }
    }
    if (n > 1) {
        factorCounts[n] += sign;
    }
}

// Calculate maximum possible moves
int maximumMoves(int a, int b) {
    if (a <= b) return 0;

    // Count prime factors for the range (b+1, a]
    unordered_map<int, int> factorCounts;
    for (int i = b + 1; i <= a; ++i) {
        factorize(i, factorCounts, 1);
    }

    // Total count of prime factors
    int totalMoves = 0;
    for (const auto& factor : factorCounts) {
        totalMoves += factor.second;
    }

    return totalMoves;
}