using namespace std;
#include<vector>

class Solution {
  public:
  
    bool DFScheck(int node, vector<vector<int>>&adj,vector<int>&Vis,vector<int>&PathVis)
    {
        Vis[node]=1;
        PathVis[node]=1;
        
        for(auto it:adj[node])
        {
            if(!Vis[it])
            {
                if(DFScheck(it,adj,Vis,PathVis)==true)
                {
                    return true;
                }
            }
            else if(PathVis[it])
            {
                return true;
            }
        }
        PathVis[node]=0;
        
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) 
    {
        vector<int>Vis(V,0);
        vector<int>PathVis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!Vis[i])
            {
                if(DFScheck(i,adj,Vis,PathVis)==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};