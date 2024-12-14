vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{

    int n=A.size();
    int m=B.size();
    
    // if(n+m<C) return -1;
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    priority_queue<tuple<int,int,int>>MaxHeap;
    
    MaxHeap.push(make_tuple(A[0]+B[0],0,0));
    
    
    set<pair<int,int>>visited;
    
    visited.insert({0,0});
    
    vector<int>Ans;
    
    while(C--)
    {
        auto [CurrentSum,i,j]=MaxHeap.top();
        MaxHeap.pop();
        Ans.push_back(CurrentSum);
        
        if(i+1<n && visited.find({i+1,j})==visited.end())
        {
            MaxHeap.push(make_tuple(A[i+1]+B[j],i+1,j));
            visited.insert({i+1,j});
        }
        
        if(j+1<m && visited.find({i,j+1})==visited.end() )
        {
            MaxHeap.push(make_tuple(A[i]+B[j+1],i,j+1));
            visited.insert({i,j+1});
        }
    }
    
    return Ans;
}