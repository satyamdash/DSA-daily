using namespace std;
#include<vector>
#include<stack>

bool validStackPermutation(vector<int> &first, vector<int> &other){
	stack<int>s;
	int j=0;

	for(int i=0;i<first.size();i++)
	{
		s.push(first[i]);


		while(!s.empty() && s.top()==other[j])
		{
			s.pop();
			j++;
		}
	}

	return s.empty() && j==other.size();

}