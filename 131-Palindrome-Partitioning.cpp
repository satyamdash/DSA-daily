class Solution {
public:
    bool isPalindrome(const string& s) 
    {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        return s == reversed;
    }
    void fun(int ind,string s,vector<vector<string>>&Ans,vector<string>&temp)
    {
        if(ind==s.length())
        {
            Ans.push_back(temp);
        }

        for (int i = ind; i < s.length(); i++) 
        {
            string substring = s.substr(ind, i - ind + 1); 
            if (isPalindrome(substring)) 
            { 
                temp.push_back(substring); // Include the substring in the current partition
                fun(i + 1, s, Ans, temp);  // Recur for the remaining string
                temp.pop_back();           // Backtrack
            }
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>Ans;
        vector<string> temp;

        fun(0,s,Ans,temp);
        return Ans;
    }
};