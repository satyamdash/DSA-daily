#include <bits/stdc++.h> 
int fun(vector<int> &billboards, vector<int> &revenue, int i, int lp,int x,int currentrevenue)
{
    if(i>=billboards.size())
    {
        return currentrevenue;
    }
    //skip
    int skip=fun(billboards,revenue,i+1,lp,x,currentrevenue);

    //incude
    int include=0;
    if(billboards[i]-lp>x)
    {
        include=fun(billboards,revenue,i+1,billboards[i],x,currentrevenue+revenue[i]);
    }
    return max(include,skip);
}
int highwayBillboard(vector<int> &billboards, vector<int> &revenue, int m, int x)
{

   return fun(billboards,revenue,0,-x,x,0);

}