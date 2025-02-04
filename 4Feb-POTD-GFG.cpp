class Solution {
  public:
  int height(Node* node,int &diameter)
    {
        if(node==NULL)
        {
            return 0;
        }
        
        int lh=height(node->left,diameter);
        int rh=height(node->right,diameter);
        
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
    
    int diameter(Node* root) {
        int diameter=0;
        height(root,diameter);
        
        return diameter;
    }
};