class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        
        for(int i = 0; i < strs.size(); i++) {
            
            string s = strs[i];
            sort(s.begin(), s.end());   // sort characters
            
            mp[s].push_back(strs[i]);   // store original string
        }
        
        vector<vector<string>> ans;
        
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};