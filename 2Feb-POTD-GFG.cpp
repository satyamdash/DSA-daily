class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>>Ans;
        
        queue<Node *>q;

        q.push(root);
        
        while(!q.empty())
        {
            int len=q.size();
            vector<int>level;
            for(int i=0;i<len;i++)
            {
                Node *node= q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
                
            }
            Ans.push_back(level);
        }
        return Ans;
    }
};