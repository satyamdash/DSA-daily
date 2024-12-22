Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* temp1=first;
    Node<int>* temp2=second;
    Node<int>* dummy=new Node<int>(-1);
    Node<int>* temp=dummy;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<=temp2->data)
        {
            Node<int>* newnode=new Node<int>(temp1->data);
            temp->next=newnode;
            temp1=temp1->next;
        }
        else
        {
            Node<int>* newnode=new Node<int>(temp2->data);
            temp->next=newnode;
            temp2=temp2->next;
        }
        temp=temp->next;
        
    }
    while(temp1!=NULL)
    {
        Node<int>*  newnode=new Node<int>(temp1->data);
        temp->next=newnode;
        temp1=temp1->next;
        temp=temp->next;
    }

    while(temp2!=NULL)
    {
        Node<int>* newnode=new Node<int>(temp2->data);
        temp->next=newnode;
        temp2=temp2->next;
        temp=temp->next;
    }

    return dummy->next;
}