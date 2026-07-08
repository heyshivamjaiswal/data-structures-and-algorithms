//Approach one
// • Observation: All anagrams become identical after sorting.
// • Use the sorted string as the HashMap key.
// • Store the original strings in a vector for that key.
// • Pattern: unordered_map<string, vector<string>> (Key → Group of values)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string str : strs){
            string keys = str;

            sort(keys.begin(), keys.end());
            mp[keys].push_back(str);
        }
        vector<vector<string>>ans;
         for(auto it : mp){
            ans.push_back(it.second);
         }
         return ans;
    }
};