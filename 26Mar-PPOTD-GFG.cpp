//{ Driver Code Starts
#include<vector>
#include<string>
#include<sstream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool wordBreakRec(int ind, string &s, vector<string> &dictionary, vector<int> &dp)
{
    if (ind >= s.size())
    {
        return true;
    }
    if (dp[ind] != -1)
        return dp[ind];
    bool possible = false;
    for (int i = 0; i < dictionary.size(); i++)
    {
        string temp = dictionary[i];
        if (temp.size() > s.size() - ind)
            continue;
        bool ok = true;
        int k = ind;
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] != s[k])
            {
                ok = false;
                break;
            }
            else
                k++;
        }
        if (ok)
        {
            possible |= wordBreakRec(ind + temp.size(), s, dictionary, dp);
        }
    }
    return dp[ind] = possible;
}

bool wordBreak(string s, vector<string> &dictionary)
{
    int n = s.size();
    vector<int> dp(n + 1, -1);
    string temp = "";
    return wordBreakRec(0, s, dictionary, dp);
}
};