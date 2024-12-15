#include <bits/stdc++.h> 
int countCustomers(vector<int> &arr, int k)
{
    int n=arr.size();
    int ans=0;
   vector<int>check(10001,0);

   for(int i=0;i<n;i++)
   {
       if(check[arr[i]]==0)
       {
            if(k>0)
           {
               k--;
               check[arr[i]]=1;
           }
           else
           {
               ans++;
               check[arr[i]]=-1;
           }

       }
       else if(check[arr[i]]==1)
       {
           k++;
           check[arr[i]]=0;
       }
       else if(check[arr[i]]==-1)
       {
           continue;
       }

   } 
   return ans;
}