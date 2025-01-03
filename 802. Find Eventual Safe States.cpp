using namespace std;
#include<vector>
class Solution {
public:
    bool DFScheck(int node, vector<vector<int>>&adj,vector<int>&Vis,vector<int>&PathVis,vector<int>&Check)
    {
        Vis[node]=1;
        PathVis[node]=1;
        Check[node]=0;
        
        for(auto it:adj[node])
        {
            if(!Vis[it])
            {
                if(DFScheck(it,adj,Vis,PathVis,Check)==true)
                {
                    return true;
                }
            }
            else if(PathVis[it])
            {
                return true;
            }
        }
        Check[node]=1;
        PathVis[node]=0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int V=graph.size();
        vector<int>Vis(V,0);
        vector<int>PathVis(V,0);
        vector<int>Check(V,0);
        vector<int>Safenodes;
        
        for(int i=0;i<V;i++)
        {
            if(!Vis[i])
            {
                DFScheck(i,graph,Vis,PathVis,Check);

            }
        }
        for(int i=0;i<V;i++)
        {
            if(Check[i])
            {
                Safenodes.push_back(i);
            }
        }
        return Safenodes;
    }
};