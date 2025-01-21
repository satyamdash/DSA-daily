//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) 
    {
        if (!head || k == 1) {
        return head;
    }

    stack<Node*> st; 
    Node *curr = head; 
    Node *prev = nullptr; 
  
    while (curr != nullptr) { 
  
        // Terminate the loop when either
          // current == NULL or count >= k 
        int count = 0; 
        while (curr != nullptr && count < k) { 
            st.push(curr); 
            curr = curr->next; 
            count++; 
        } 
  
        // Now pop the elements from the stack one by one 
        while (!st.empty()) { 
            
            // If the final list has not been started yet
            if (prev == nullptr) { 
                prev = st.top(); 
                head = prev; 
                st.pop(); 
            } else { 
                prev->next = st.top(); 
                prev = prev->next; 
                st.pop(); 
            } 
        } 
    } 
  
    // Set the next pointer of the 
      // last node to NULL
    prev->next = nullptr; 
  
    return head; 
    }
};