class Solution {
  public:
    Node *cloneLinkedList(Node *head) 
    {
        unordered_map<Node*, Node*> mp;
    Node *curr = head;
  
    // Traverse original linked list to store new 
      // nodes corresponding to original linked list
    while (curr != NULL) {
        mp[curr] = new Node(curr->data);
        curr = curr->next;
    }
    
      curr = head;
      
    // Loop to update the next and random pointers 
      // of new nodes 
    while (curr != NULL) {
        
          // Update the next pointer of new node
          mp[curr]->next = mp[curr->next];
      
          // Update the random pointer of new node
          mp[curr]->random = mp[curr->random];
      
          curr = curr->next;
    }
  
    // Return the head of the clone
    return mp[head];
    }
};