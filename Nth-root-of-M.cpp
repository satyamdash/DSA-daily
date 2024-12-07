double mult(double mid,double n)
{
  double Ans=1.0;

  for(int i=0;i<n;i++)
  {
    Ans=Ans*mid;
  }
  return Ans;
}

int NthRoot(int n, int m)
{
 double l=1;
 double h=m;

 double eps=1e-6;

 while((h-l)>eps)
 {
   double mid=(l+h)/2.0;
   if(mult(mid,n)<m)
   {
     l=mid;
   }
   else
   {
     h=mid;
   }
 }
    int intH = static_cast<int>(round(h));
    if (fabs(mult(intH, n) - m) < eps)
    {
        return intH;
    }
    return -1;
  
}