#include <cstddef>
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *firstNode(Node *head)
{
    Node *slow=head;
    Node *fast=head;

    while(fast && fast->next)
    {

        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }
    if (!fast || !fast->next) {
        return NULL;
    }

    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }

    return slow;
}