using namespace std;
#include<vector>
#include<stack>
#include<string>
class Solution {
public:
    string robotWithString(string s) {
        
        string ans="";
        vector<int>freq(26,0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        stack<char>st;
        for(auto c:s)
        {
            st.push(c);
            freq[c - 'a']--;

            char smallest='a';
            while(smallest<='z' && freq[smallest-'a']==0)
            {
                smallest++;
            }

            while(!st.empty() && st.top()<=smallest)
            {
                ans+=st.top();
                st.pop();
            }

        }
        while(!st.empty())
            {
                ans+=st.top();
                st.pop();
            }
        return ans;
        
    }
};