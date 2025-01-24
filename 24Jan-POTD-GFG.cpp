class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) 
    {
        Node *slow=head;
        Node *fast=head;
        
        while(fast->next!= NULL && fast->next->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};