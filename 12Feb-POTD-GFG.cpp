class Solution {
  public:
  
    void Inorder(Node *root,vector<int>&Ans)
    {
        if(root==NULL)
        {
            return;
        }
        Inorder(root->left,Ans);
        Ans.push_back(root->data);
        Inorder(root->right,Ans);
        
    }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) 
    {
        vector<int>Ans;
        Inorder(root,Ans);
        
        std::priority_queue<int> maxHeap;

    for (int num : Ans) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();  // Remove the largest to keep only k smallest
        }
    }
    if(maxHeap.size()<k) return -1;
     return maxHeap.top();
    }
};