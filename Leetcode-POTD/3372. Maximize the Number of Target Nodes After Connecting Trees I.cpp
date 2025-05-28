class Solution {
public:
    int dfs(int curr,unordered_map<int,vector<int>>&adjlist,int d,int parentnode)
    {
        if(d<0)
        {
            return 0;
        }
        int count=1;

        for(auto &ngbr:adjlist[curr])
        {
            if(ngbr!=parentnode)
            {
                count+=dfs(ngbr,adjlist,d-1,curr);
            }
        }

        return count;
    }
    vector<int>findCount(vector<vector<int>>& edges,int d)
    {
               int N = edges.size() + 1;
        unordered_map<int, vector<int>> adjlist;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        vector<int> result(N, 0); 

        for (int i = 0; i < N; ++i) {
            result[i] = dfs(i, adjlist, d, -1);
        }

        return result;

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> result1 = findCount(edges1, k);
        vector<int> result2 = findCount(edges2, k - 1);

        int maxTree2 = *max_element(result2.begin(), result2.end());

        int N = edges1.size() + 1;  // FIX: N is number of nodes

        for (int i = 0; i < N; ++i) {
            result1[i] += maxTree2;
        }

        return result1;
    }
};