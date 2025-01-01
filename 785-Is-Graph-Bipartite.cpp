#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> colors(n,-1);

        for(int begin=0;begin<n;begin++)
        {
            if (colors[begin] != -1) continue; 
            queue<int>q;
            q.push(begin);
            colors[begin]=0;

            while(!q.empty())
            {
                int node=q.front();
                q.pop();

                for(int it:graph[node])
                {
                    if(colors[it]==-1)
                    {
                        colors[it] = !colors[node];
                        q.push(it);
                    }
                    else if(colors[it]==colors[node])
                    {
                        return false;
                    }
                }
            }

        }
        return true;
    }
};