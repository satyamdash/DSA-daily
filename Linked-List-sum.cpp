Node *addTwoNumbers(Node *num1, Node *num2)
{
    int carry=0;
    int sum=0;
    Node *dummy=new Node(-1);
    Node *newnode=dummy;
    while(num1!=NULL || num2!=NULL ||carry!=0)
    {
        sum=carry;
        if(num1!=NULL)
        {
            sum+=num1->data;
            num1=num1->next;
        }

        if(num2!=NULL)
        {
            sum+=num2->data;
            num2=num2->next;
        }

        carry=sum/10;
        Node* node=new Node(sum%10);
        newnode->next=node;
        newnode=newnode->next;
    }

    return dummy->next;
}
