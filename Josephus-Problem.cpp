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