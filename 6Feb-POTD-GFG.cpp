class Solution {
  public:
  
    Node *buildTreeRec(unordered_map<int,int>&mpp,vector<int> &preorder,int &preindex,
    int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
        
        int rootval=preorder[preindex];
        preindex++;
        Node *root=new Node(rootval);
        
        int index=mpp[rootval];
        root->left=buildTreeRec(mpp,preorder,preindex,left,index-1);
        root->right=buildTreeRec(mpp,preorder,preindex,index+1,right);
        
        
        return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) 
    {
        unordered_map<int,int>mpp;
        
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        int preindex=0;
        
        Node *root=buildTreeRec(mpp,preorder,preindex,0,inorder.size()-1);
        
        return root;
        
    }
};
