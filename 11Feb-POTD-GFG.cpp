// } Driver Code Ends
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isValidBST(Node* root,int min_val,int max_val)
    {
        if(root==NULL)
        {
            return true;
        }
        
        if(root->data>=max_val || root->data<=min_val) return false;
        
        return isValidBST(root->left,min_val,root->data) && isValidBST(root->right,root->data,max_val);
        
        
    }
    bool isBST(Node* root){
       return isValidBST(root,INT_MIN,INT_MAX);
    }
};
