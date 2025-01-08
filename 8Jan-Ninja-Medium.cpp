int lengthOfNumber(int k)
{
	// Write your code here.
	int remainder=1;
	int digit=1;
	for(int i=0;i<k;i++)
	{
				
		if(remainder%k==0)
		{
			return digit;
		}
		remainder=(remainder*10+1)%k;


		digit++;
	}
	return -1;
}