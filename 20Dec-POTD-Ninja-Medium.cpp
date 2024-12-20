Node *rotate(Node *head, int k) 
{
   if(!head ||k==0) return head;
   Node* endnode=head;
   int count=1;

   while(endnode->next!=NULL) 
   {
        count++;
        endnode=endnode->next;
   }  

   if(k%count==0) return head;
      k=k%count;
   endnode->next=head;

     Node* newTail=head;
     int steps=count-k;
    for(int i=1;i<steps;i++)
    {
      newTail=newTail->next;     
    }
    Node* newhead=newTail->next;
    newTail->next=NULL;

    return newhead;
}