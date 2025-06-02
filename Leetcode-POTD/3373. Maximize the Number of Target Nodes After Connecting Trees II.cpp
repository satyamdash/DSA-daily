#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>>getadj(vector<vector<int>>& edges)
    {
        int N=edges.size()+1;
        vector<vector<int>>adjlist(N);
        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        return adjlist;
    }
    void dfs(int curr,int parent,vector<vector<int>> &adjlist,vector<int>&markA, int &zeroMarkednodeA,int &oneMarkednodeA)
    {
        if(markA[curr]==0)
        {
            zeroMarkednodeA++;
        }
        else
        {
            oneMarkednodeA++;
        }

        for(auto &ngbr:adjlist[curr])
        {
            if(parent!=ngbr)
            {
                markA[ngbr]=(markA[curr]==0) ? 1:0;
                dfs(ngbr,curr,adjlist,markA,zeroMarkednodeA,oneMarkednodeA);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>>adjlist1=getadj(edges1);
        vector<vector<int>>adjlist2=getadj(edges2);

        int N=edges1.size()+1;
        int M=edges2.size()+1;

        int zeroMarkednodeA = 0;
        int oneMarkednodeA = 0;
        vector<int>markA(N,-1);
        markA[0]=0;
        
        dfs(0,-1,adjlist1,markA,zeroMarkednodeA,oneMarkednodeA);

        vector<int>markB(M,-1);
        markB[0]=1;
        int zeroMarkednodeB = 0;
        int oneMarkednodeB = 0;

        dfs(0,-1,adjlist2,markB,zeroMarkednodeB,oneMarkednodeB);
        int maxelement=max(zeroMarkednodeB,oneMarkednodeB);

        vector<int>result(N,0);

        for(int i=0;i<N;i++)
        {
            result[i]=(markA[i]==0 ? zeroMarkednodeA : oneMarkednodeA)+maxelement;
        }

        return result;
    }
};