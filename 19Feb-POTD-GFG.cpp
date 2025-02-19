class Solution {
  public:
    Node* mergeTwo(Node* head1, Node* head2) {
    
    // Create a dummy node to simplify 
    // the merging process
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    // Iterate through both linked lists
    while (head1 != nullptr && head2 != nullptr) {
      
        // Add the smaller node to the merged list
        if (head1->data <= head2->data) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    // If any list is left, append it to
    // the merged list
    if (head1 != nullptr) {
        curr->next = head1;
    } else {
        curr->next = head2;
    }

    // Return the merged list starting
    // from the next of dummy node
    return dummy->next;
}

    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
         Node *res = nullptr;
    
    // One by one merge all lists with 
    // res and keep updating res
    for (Node *node : arr) 
        res = mergeTwo(res, node);
        
    return res;
    }
};
