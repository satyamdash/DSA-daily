class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    
    void mirror(Node* node) 
    {
        if (node == nullptr)
        return ;
    
        queue<Node*> q;
        q.push(node);
        
        // Traverse the tree, level by level
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
          
            // Swap the left and right subtree
            swap(curr->left, curr->right);
          
            // Push the left and right node to the queue
            if(curr->left != nullptr)
              q.push(curr->left);
            if(curr->right != nullptr)
              q.push(curr->right);
        }
    }
};



   