class Solution {
public:
    string Count(string s)
    {
         string result = "";
        int count = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                result += to_string(count) + s[i - 1];
                count = 1;
            }
        }
        // Add last group
        result += to_string(count) + s.back();
        return result;
    }
    string countAndSay(int n) {
        string temp="1";
        if(n==1) return temp;
        else
        {
            while(n>1)
            {
                temp=Count(temp);
                n--;
            }
        }

        return temp;
    }
};