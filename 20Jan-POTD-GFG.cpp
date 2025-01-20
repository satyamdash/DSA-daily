using namespace std;
#include <vector>

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) 
    {
        Node* temp1=head1;
        Node*temp2=head2;
        
        Node* node=new Node(-1);
        Node*newhead=node;
        while(temp1!=NULL && temp2!=NULL)
        {
            Node* newnode;
            if(temp1->data<=temp2->data)
            {
                newnode=new Node(temp1->data);
                temp1=temp1->next;
            }
            else
            {
                newnode=new Node(temp2->data);
                temp2=temp2->next;
            }
            node->next=newnode;
            node=node->next;
            
            
        }
        
        while(temp1!=NULL)
        {
            Node* newnode=new Node(temp1->data);
            node->next=newnode;
            node=node->next;
            temp1=temp1->next;
        }
        
        while(temp2!=NULL)
        {
            Node* newnode=new Node(temp2->data);
            node->next=newnode;
            node=node->next;
            temp2=temp2->next;
        }
        
        
        return newhead->next;
    }
};