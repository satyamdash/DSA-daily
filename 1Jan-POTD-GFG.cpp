class Solution {
  public:
   vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> anagramGroups;
    
    for(auto str:strs)
    {
        string key=str;
        sort(key.begin(),key.end());
        
        anagramGroups[key].push_back(str);

    }
    vector<vector<string>>result;
    for(auto pair:anagramGroups)
    {
      result.push_back(pair.second);  
    }
    return result;
}
    vector<vector<string>> anagrams(vector<string>& arr) 
    {
        return groupAnagrams(arr);
    }
};