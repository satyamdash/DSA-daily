#include <bits/stdc++.h>

bool CheckValid(string word,map<int, vector<char>> &mpp,string &Sequence)
{
	if(word.size()!=Sequence.length()) return false;
	for(int i=0;i<word.size();i++)
	{
		int digit=Sequence[i]-'0';
		if(mpp.find(digit)==mpp.end()) return false;
		vector<char>ValidChars=mpp[digit];

		if(find(ValidChars.begin(),ValidChars.end(),word[i])==ValidChars.end())
		{
			return false;
		}
		
	}
	return true;
}

vector<string> phoneCode(vector<string> Words, string &Sequence, int W) {
  map<int, vector<char>> mpp;

        mpp[2]={'a','b','c'};
		mpp[3]={'d','e','f'};
		mpp[4]={'g','h','i'};
		mpp[5]={'j','k','l'};
		mpp[6]={'m','n','o'};
		mpp[7]={'p','q','r','s'};
		mpp[8]={'t','u','v'};
		mpp[9]={'w','x','y','z'};

		vector<string>Ans;

		for(auto ss:Words)
		{
			if(CheckValid(ss,mpp,Sequence))
			{
				Ans.push_back(ss);
			}
		}

		return Ans;
}