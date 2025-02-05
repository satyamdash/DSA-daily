class Solution {
  public:
    // Function to find the height of a binary tree.
    int maxdepth(Node* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        
        int lh=maxdepth(node->left);
        int rh=maxdepth(node->right);
        
        
        return 1+max(lh,rh);
    }
    int height(Node* node) {
        
        return maxdepth(node)-1;
        
    }
};