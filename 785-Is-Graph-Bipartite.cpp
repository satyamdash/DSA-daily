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



//DFS

class Solution {
public:
    bool DFS(int start,vector<int>&colors,vector<vector<int>>& graph)
    {
        for(auto node:graph[start])
        {
            if(colors[node]==-1)
            {
                colors[node]=!colors[start];
                if(!DFS(node,colors,graph))
                {
                    return false;
                }
                
            }
            else if(colors[node]==colors[start])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> colors(n,-1);

        for(int begin=0;begin<n;begin++)
        {
            if(colors[begin]==-1)
            {
                colors[begin]=0;
                 if(!DFS(begin,colors,graph))
                 {
                    return false;
                 }
            }
        }
        return true;
    }
};