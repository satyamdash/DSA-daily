#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int beststartingpoint(string word,int n)
    {
        int i = 0; //best starting point
        int j = 1; //keep moving to find the best starting point

        while(j < n) {
            int k = 0;

            //skipping equal characters
            while( j+k < n && word[i+k] == word[j+k]) {
                k++;
            }

            if(j+k < n && word[j+k] > word[i+k]) {
                i = j; //updating best starting point
                j = j+1;
            } else {
                j = j + k + 1; //skipping already checked characters
            }
        }

        return i;
    }
    string answerString(string word, int numFriends) {
        
        int n=word.length();
        int maxlen=n-numFriends+1;
        if(numFriends==1) return word;

        int i=beststartingpoint(word,n);
        maxlen=min(maxlen,n-i);


        return word.substr(i,maxlen);
        
    }
};