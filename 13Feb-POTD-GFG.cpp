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
    bool findSum(vector<int>&Ans,int target)
    {
        unordered_set<int> s;
        
        for(int i=0;i<Ans.size();i++)
        {
           int temp= target-Ans[i];
            
            if(s.find(temp)!=s.end())
            {
                return true;
            }
            s.insert(Ans[i]);
        }
        
        return false;
    }
    bool findTarget(Node *root, int target) {
        vector<int>Ans;
        Inorder(root,Ans);
        return findSum(Ans,target);
    }
};