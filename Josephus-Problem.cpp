#include <bits/stdc++.h> 

int predictTheWinner(int n, int k) 
{
    int winner=0;
    for(int i=2;i<=n;i++)
    {
        winner=(winner+k)%i;
    }

    return winner+1;

}

//Recursive approach

class Solution {
public:

    int findindxwinner(int n,int k)
    {
        if(n==1) return 0;
        int idx=findindxwinner(n-1,k);
        idx=(idx+k)%n;

        return idx;

    }
    int findTheWinner(int n, int k) 
    {
       int resultidx=findindxwinner(n,k);

       return resultidx+1;
    }
};