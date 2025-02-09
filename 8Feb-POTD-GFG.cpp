class Solution {
  public:
  bool isLeaf(Node *node) 
    {
        return node->left == nullptr && node->right == nullptr;
    }
    
    void LeftBoundary(Node *root,vector<int>&res)
    {
        Node*cur=root->left;
        
        while(cur)
        {
            if (!isLeaf(cur)) {
                res.push_back(cur->data);
            }
            if(cur->left!=NULL)
            {
                cur=cur->left;
            }
            else
            {
                cur=cur->right;
            }
        }
    }
    
    void RightBoundary(Node *root,vector<int>&res)
    {
        Node *cur=root->right;
        vector<int>temp;
        while(cur)
        {
            if(!isLeaf(cur))
            {
                temp.push_back(cur->data);
            }
            if(cur->right)
            {
                cur=cur->right;
            }
            else
            {
                cur=cur->left;
            }
        }
        
        reverse(temp.begin(),temp.end());
        res.insert(res.end(), temp.begin(), temp.end());
        
    }
    void addLeaf(Node *root,vector<int>&res)
    {
        if(root==NULL)
        {
            return;
        }
        
        addLeaf(root->left,res);
        if(isLeaf(root))
        {
            res.push_back(root->data);
        }
        addLeaf(root->right,res);
    }
    
    vector<int> boundaryTraversal(Node *root) 
    {
        vector<int>res;
        if(root==NULL) return res;
        if (!isLeaf(root)) {
            res.push_back(root->data);
        }
        
        LeftBoundary(root,res);
        addLeaf(root,res);
        RightBoundary(root,res);
        
        
        return res;

    }
};