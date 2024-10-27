class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> strings;
        for(auto &str:strs)
        {
            string temp=str;
            sort(temp.begin(),temp.end());
            strings[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto& it:strings)
        ans.push_back(it.second);

        return ans;
    }
};