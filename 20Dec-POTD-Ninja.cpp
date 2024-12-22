#include <bits/stdc++.h> 
vector<int> linearProbing(vector<int> keys)
{
    int n=keys.size();
    vector<int>hashtable(n,-1);

    for(int i=0;i<n;i++)
    {
        int mod=keys[i]%n;
        while(hashtable[mod]!=-1)
        {
            mod=(mod+1)%n;
        }
        hashtable[mod]=keys[i];
        
    }
    return hashtable;
}