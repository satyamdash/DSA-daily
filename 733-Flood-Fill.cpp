class Solution {
public:
    void DFS(int sr, int sc, int color,vector<vector<int>>& ans,int n,int m,int inicolor)
    {
        ans[sr][sc]=color;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && ans[nrow][ncol]!=color && ans[nrow][ncol]==inicolor)
            {
                DFS(nrow,ncol,color,ans,n,m,inicolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        vector<vector<int>>ans=image;
        int inicolor=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        DFS(sr,sc,color,ans,n,m,inicolor);

        return ans;
    }
};