class Solution {
  public:
    Node *lowestcommonAncestor(Node* root, Node* n1, Node* n2)
    {
        if(root==NULL)
        {
            return NULL;
        }
        int curr=root->data;
        if(curr<n1->data && curr<n2->data)
        {
          return  lowestcommonAncestor(root->right,n1,n2);
        }
        else if(curr>n1->data && curr>n2->data)
        {
           return   lowestcommonAncestor(root->left,n1,n2);
        }
        return root;
        
    }
    Node* LCA(Node* root, Node* n1, Node* n2) {
        
        return lowestcommonAncestor(root,n1,n2);
    }
};
