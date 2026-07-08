//Approach 1 
// Map

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
            if(freq[num] > 1){
                return true;
            }
        }
        return false;
    }
};


//Approach 2
// Set

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        for(int num: nums){
            if(seen.find(num) != seen.end())
                return true;
                seen.insert(num);
        }
        return false;
    }
};