class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int m=2;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int a=dominoes[i][0];
                int b=dominoes[i][1];
                int c=dominoes[j][0];
                int d=dominoes[j][1];

                if((a==c && b==d) || (a==d && b==c))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};


//2nd Approach

class Solution {
public:
struct hash_pair {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        unordered_map<pair<int, int>, int, hash_pair> mpp;
        
        int ans=0;

        for (auto& dom : dominoes) {
            sort(dom.begin(), dom.end());
            pair<int, int> p = {dom[0], dom[1]};
            ans += mpp[p]; // If exists, add the count
            mpp[p]++;      // Add current domino
        }
        return ans;
    }
};