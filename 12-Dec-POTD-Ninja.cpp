Node *replaceWithSum(Node *head)
{
	Node *newhead=NULL;
	Node *temp=head;
	Node *tail=NULL;

	int sum=0;
	bool hassegment=false;
	

	while(temp!=NULL)
	{
		if(temp->data==0)
		{
			if(sum!=0)
			{
				Node *newnode=new Node(sum);
				if(!newhead)
				{
					newhead=newnode;
				}
				else
				{
					tail->next=newnode;
				}
				tail=newnode;
				sum=0;
			}
			hassegment=true;
		}
		else
		{
			sum+=temp->data;
		}
		temp=temp->next;
	}
if(sum!=0)
			{
				Node *newnode=new Node(sum);
				if(!newhead)
				{
					newhead=newnode;
				}
				else
				{
					tail->next=newnode;
				}
			}

			if(!hassegment &&sum!=0)
			{
				return head;
			}

	return newhead?newhead:head;
}