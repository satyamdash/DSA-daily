using namespace std;
#include<vector>
#include<stack>
vector<int> answerQueries(vector<vector<int>> &queries, int limit) 
{
    stack<int>st;
    vector<int>result;
    vector<int>elements(limit,0);

    for(auto query:queries)
    {
        int operation=query[0];

        if(operation==1)
        {
            int val=query[1];
            if (st.size() < limit) 
            {
              st.push(val);
              elements[st.size()-1]=val;
            }
        }
        else if(operation==2)
        {
            if(st.empty())
            {
                result.push_back(-1);
            }
            else
            {

                result.push_back(elements[st.size()-1]);
                st.pop();
            }
        }
        else if(operation==3)
        {
            int K=query[1];
            int Y=query[2];
            K=min(K,(int)st.size());

           for(int i=0;i<K;i++)
           {
               elements[i]+=Y;
           }
        }
    }

    return result;
}