class Solution {
  public:
  void findInorder(Node* curr, vector<int>&inorder){
    if(curr == nullptr) return;
  
      // Recursively store left subtree
    findInorder(curr->left, inorder);
  
      // Store the current node's data
    inorder.push_back(curr->data);
  
      // Recursively store right subtree
    findInorder(curr->right, inorder);
}

// Recursive function to correct the BST by replacing
// node values with sorted values
void correctBSTUtil(Node* root, vector<int> &inorder, int &index){
    if(root == nullptr) return;
      
      // Recursively fill the left subtree
    correctBSTUtil(root->left, inorder, index);
  
      // Replace the current node's data with 
      // the correct value from the sorted array
    root->data = inorder[index];
    index++;
      
      // Recursively fill the right subtree
    correctBSTUtil(root->right, inorder, index);
}
    void correctBST(Node* root) {
        // add code here.
         vector<int> inorder;
    findInorder(root, inorder);
  
      // Sort the vector to get the correct order of 
      // elements in a BST
    sort(inorder.begin(), inorder.end());
  
    int index = 0;
    correctBSTUtil(root, inorder, index);
    }
};
