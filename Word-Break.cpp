#include <bits/stdc++.h>
#include<vector>
vector<string> wordBreakHelper(const string &s, unordered_set<string>&dict) 
{
    vector<string> result;

    if(s.empty())
    {
        result.push_back("");
        return result;
    }
        for (int i = 1; i <= s.length(); ++i) {
        string word = s.substr(0, i); // Take the prefix
        if (dict.find(word) != dict.end()) { // Check if it's a valid word
            vector<string> remainingSentences = wordBreakHelper(s.substr(i), dict);
            for (const string &sentence : remainingSentences) {
                result.push_back(word + (sentence.empty() ? "" : " " + sentence));
            }
        }
    }
    return result;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
     unordered_set<string> dict(dictionary.begin(), dictionary.end());
    return wordBreakHelper(s, dict);
};
