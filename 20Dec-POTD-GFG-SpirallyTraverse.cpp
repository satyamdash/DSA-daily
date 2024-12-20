class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) 
    {
        vector<int>Ans;
        int row=mat.size();
        int col=mat[0].size();
        int left=0;
        int right=col-1;
        int top=0;
        int down=row-1;
        
        while(top<=down && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                Ans.push_back(mat[top][i]);
            }
            top++;
            
            for(int i=top;i<=down;i++)
            {
                Ans.push_back(mat[i][right]);
            }
            right--;
            if(top<=down)
            {
                for(int i=right;i>=left;i--)
                {
                    Ans.push_back(mat[down][i]);
                }
                down--;
            }
            if(left<=right)
            {
                for(int i=down;i>=top;i--)
                {
                    Ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return Ans;
    }
};