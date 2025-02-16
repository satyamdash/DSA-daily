class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        queue<Node*>q;
        vector<int>arr;
        q.push(root);
        
        while(!q.empty())
        {
        
            Node *nnode=q.front();
            q.pop();
            if (nnode == nullptr) {
            arr.push_back(-1);
            continue;
            }
            arr.push_back(nnode->data);
            q.push(nnode->left);
            q.push(nnode->right);
        }
        return arr;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // base case
   if (arr[0]==-1) return nullptr;
   
   // create root node and push 
   // it into queue
   Node* root = new Node(arr[0]);
   queue<Node*> q;
   q.push(root);
   
   int i = 1;
   while (!q.empty()) {
       Node* curr = q.front();
       q.pop();
       
       // If left node is not null
       if (arr[i]!=-1) {
           Node* left = new Node(arr[i]);
           curr->left = left;
           q.push(left);
       }
       i++;
       
       // If right node is not null
       if (arr[i]!=-1) {
           Node* right = new Node(arr[i]);
           curr->right = right;
           q.push(right);
       }
       i++;
   }
   
   return root;
    }
};