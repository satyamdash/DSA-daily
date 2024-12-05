#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) 
    {
        string s3=s2+s2;
        if (s1.length() != s2.length()) {
        return false;
    }
        if (s3.find(s1) != string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

