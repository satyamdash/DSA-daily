#include<bits/stdc++.h>
using namespace std;
int count(string a,string b)
{
    int i=0;
    while((i<a.size() && i<b.size()) && (a[i]==b[i]))
    {
        i++;
    }
    return i;
}

int longestCommonPrefix(vector<string>Database,vector<string>X)
{
    int ans=0;
    int m=Database.size();
    int n=X.size();

    for(int j=0;j<n;j++)
    {
        for (int i = 0; i < m; i++) {
            ans+=count(Database[i], X[j]);
            if(X[j]==Database[i]) break;
        }
    }
    return ans;
}
