class Solution {
  public:

  //BFS APPROACH
  bool detect(int src, vector<vector<int>>& adj, vector<int>&vis) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false;
        // Code here
    }
};


//DFS APPROACH

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool DFS(int node,int parent, vector<vector<int>>& adj, vector<int>&vis) 
  {
      vis[node]=1;
      for(auto adjacent:adj[node])
      {
          
          if(!vis[adjacent])
          {
            if(DFS(adjacent,node,adj,vis)==true) return true;
          }
          else if(adjacent!=parent)
          {
              return true;
          }
      }
      // there's no cycle
      return false; 
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>vis(V,0);
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(DFS(i,-1, adj, vis)) return true; 
            }
        }
        return false;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
