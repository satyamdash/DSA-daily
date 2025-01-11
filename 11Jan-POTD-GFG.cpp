using namespace std;
#include <unordered_map>
#include <string>

// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) 
    {
        int n = s.length();
    unordered_map<char, int> charIndex; // Stores the last index of each character
    int start = 0, maxLength = 0;

    for (int end = 0; end < n; end++) {
        char currentChar = s[end];

        // If the character is already in the map and its index is within the current window
        if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= start) {
            // Move the start to the right of the last occurrence of currentChar
            start = charIndex[currentChar] + 1;
        }

        // Update the character's last index
        charIndex[currentChar] = end;

        // Update the maximum length
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
    }
};