#include <bits/stdc++.h> 
vector<vector<int>>printPattern(int n)
{
	int first=1;
	int totalnumbers=2*n;
	int last=n*(n+1);

	vector<vector<int>>Ans;


	for(int i=0;i<n;i++)
	{
		vector<int>temp;
		int mid=totalnumbers/2;
		for(int i=0;i<mid;i++)
		{
			temp.push_back(first++);
		}
		
		for(int i=0;i<mid;i++)
		{
			temp.push_back(last--);
		}
		sort(temp.begin(),temp.end());
		Ans.push_back(temp);
		totalnumbers-=2;

    }
	return Ans;
}