#include <bits/stdc++.h> 

int toggleKBits(int n, int k) 
{
   int mask=(1<<k)-1;
   return n^mask;
}