class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        vector<vector<int>>Ans;
        
        queue<Node *>q;

        q.push(node);
        
        while(!q.empty())
        {
            int len=q.size();
            vector<int>level;
            for(int i=0;i<len;i++)
            {
                Node *nnode= q.front();
                q.pop();
                level.push_back(nnode->data);
                if(nnode->left!=NULL)
                {
                    q.push(nnode->left);
                }
                if(nnode->right!=NULL)
                {
                    q.push(nnode->right);
                }
                
            }
            Ans.push_back(level);
        }
        return Ans.size()-1;
    }
};