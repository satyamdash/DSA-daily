class Solution {
  public:
  bool isLeaf(Node *node) {
    return node->left == nullptr && node->right == nullptr;
}

// Function to collect the left boundary nodes
void collectBoundaryLeft(Node *root, vector<int> &res) {
    if (root == nullptr)
        return;

    Node *curr = root;
    while (!isLeaf(curr)) {
        res.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// Function to collect the leaf nodes using Morris Traversal
void collectLeaves(Node* root, vector<int>& res) {
    Node* current = root;

    while (current) {
        if (current->left == nullptr) {
          
            // If it's a leaf node
            if (current->right == nullptr) 
                res.push_back(current->data);
            
            current = current->right;
        } 
          else {
          
            // Find the inorder predecessor
            Node* predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } 
              else {
                  // If it's predecessor is a leaf node
                if (predecessor->left == nullptr) 
                    res.push_back(predecessor->data);
                
                predecessor->right = nullptr;
                current = current->right;
            }
        }
    }
}

// Function to collect the right boundary nodes
void collectBoundaryRight(Node *root, vector<int> &res) {
    if (root == nullptr)
        return;

    Node *curr = root;
    vector<int> temp;
    while (!isLeaf(curr)) {
      
        temp.push_back(curr->data);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; --i)
        res.push_back(temp[i]);
}

    vector<int> boundaryTraversal(Node *root) {
         vector<int> res;

    if (!root)
        return res;

    // Add root data if it's not a leaf
    if (!isLeaf(root))
        res.push_back(root->data);

    // Collect left boundary
    collectBoundaryLeft(root->left, res);

    // Collect leaf nodes
    collectLeaves(root, res);

    // Collect right boundary
    collectBoundaryRight(root->right, res);

    return res;
    }
};