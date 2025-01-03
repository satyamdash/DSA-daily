using namespace std;
#include<vector>

int threePointer(vector<int>& X, vector<int>& Y, vector<int>& Z)
{  
    int i=0,j=0,k=0; 
    int l=X.size();
    int m=Y.size();
    int n=Z.size();

    int global_mini=INT_MAX;

    while (i < l && j < m && k < n) 
    {
      int a = X[i];
      int b = Y[j];
      int c = Z[k];
      int maxi = max(abs(a - b), abs(b - c));
       maxi=max(maxi, abs(c - a));
       global_mini=min(global_mini,maxi);

       if(a<=b && a<=c)
       {
           i++;
       }
       else if(b<=a && b<=c)
       {
           j++;
       }
       else if(c<=a && c<=b)
       {
           k++;
       }
    }


    return global_mini;
}
