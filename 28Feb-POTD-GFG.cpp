class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        
        stack<int>st;
        int n=arr.size();
        
        for(auto ch:arr)
        {
            if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
            {
                if(!st.empty())
                {
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    
                    if(ch=="+")
                    {
                        st.push(b+a);
                    }
                    else if(ch=="-")
                    {
                        st.push(b-a);
                    }
                    else if(ch=="*")
                    {
                        st.push(b*a);
                    }
                    else
                    {
                        st.push(b/a);
                    }
                }
            }
            else
            {
                st.push(stoi(ch));
            }
        }
        
        return st.top();
    }
};