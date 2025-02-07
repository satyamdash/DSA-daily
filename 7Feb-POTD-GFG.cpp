class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void inOrderRec(Node* root, vector<int>&Ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        inOrderRec(root->left,Ans);
        Ans.push_back(root->data);
        inOrderRec(root->right,Ans);
    }
    vector<int> inOrder(Node* root) 
    {
        vector<int>Ans;
        inOrderRec(root,Ans);
        
        return Ans;
    }
};