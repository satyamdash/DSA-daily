using namespace std;
#include <algorithm>
#include <vector>

class Solution {
  public:
    Node* rotate(Node* head, int k) 
    {
        if (k == 0 || head == nullptr)
        return head;

    Node *curr = head;
    int len = 1;
  
      // Find the length of linked list
    while (curr->next != nullptr) {
        curr = curr->next;
        len += 1;
    }

      // Modulo k with length of linked list to handle
      // large values of k
    k %= len;
  
    if (k == 0)
        return head;
  
      // Make the linked list circular
    curr->next = head;

      // Traverse the linked list to find the kth node
    curr = head;
    for (int i = 1; i < k; i++)
        curr = curr->next;

      // Update the (k + 1)th node as the new head
    head = curr->next;
  
      // Break the loop by updating next pointer of kth node
    curr->next = nullptr;
    return head;
    }
};