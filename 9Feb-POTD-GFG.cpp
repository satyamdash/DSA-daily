class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    int findMaxi(Node *root,int &maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        int leftSum=max(0,findMaxi(root->left,maxi));
        int rightSum=max(0,findMaxi(root->right,maxi));
        maxi=max(maxi,leftSum+rightSum+root->data);
        
        return root->data+max(leftSum,rightSum);
    }
    int findMaxSum(Node *root) 
    {
        int maxi=INT_MIN;
        findMaxi(root,maxi);
        return maxi;
    }
};