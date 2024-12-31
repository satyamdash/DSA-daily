class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int n=letters.size();
      int s=0;
      int e=n-1;  

      while(s<=e)
      {
         int m=(s+e)/2;

         if(letters[m]<=target)
         {
            s=m+1;
         }
         else
         {
            e=m-1;
         }
      }
      return letters[s%n];
    }
};