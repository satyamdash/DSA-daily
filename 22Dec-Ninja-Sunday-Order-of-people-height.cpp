#include<algorithm>
bool comparator(const pair<int,int>&a,const pair<int,int>&b)
{
	return a.first>b.first || (a.first==b.first && a.second<b.second);
}
vector<int> findOrder(vector<int> & height, vector<int> & infront) 
{
	// Write your code here.
	vector<pair<int,int>>people;
	int n=height.size();

	for(int i=0;i<n;i++)
	{
		people.push_back({height[i],infront[i]});
	}

	sort(people.begin(),people.end(),comparator);

	vector<int>ans;

	for(auto it:people)
	{
		ans.insert(ans.begin()+it.second,it.first);
	}
	return ans;
}