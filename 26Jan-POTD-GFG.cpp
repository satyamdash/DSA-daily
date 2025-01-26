class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) 
    {
        
    // hash set to hash addresses of
    // the linked list nodes
    unordered_set<Node *> st;

    // pointer to prev node
    Node *prev = nullptr;
    while (head != nullptr) {

        // if node not present in the map,
        // insert it in the map
        if (st.find(head) == st.end()) {
            st.insert(head);
            prev = head;
            head = head->next;
        }
      
        // if present, it is a cycle, make
        // last node's next pointer NULL
        else {
            prev->next = nullptr;
            break;
        }
    }
    }
};