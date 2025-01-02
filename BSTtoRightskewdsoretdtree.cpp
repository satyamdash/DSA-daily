

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

#include<vector>
void PushinOrder(TreeNode<int>*root,vector<int>&sorted)
{
    if(root==NULL)
     {
         return;
     }
     PushinOrder(root->left,sorted);
     sorted.push_back(root->data);
     PushinOrder(root->right,sorted);

}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>sorted;
    PushinOrder(root ,sorted);
    TreeNode<int>* newnode=new TreeNode<int>(sorted[0]);
    TreeNode<int>* current=newnode;

    for(int i=1;i<sorted.size();i++)
    {
        current->right=new TreeNode<int>(sorted[i]);
        current->left=NULL;
        current=current->right;
    }
    return newnode;
}
