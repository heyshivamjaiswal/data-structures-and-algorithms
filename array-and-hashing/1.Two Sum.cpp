//Approach 1
//Brute force

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0 ; i< nums.size(); i++){
            for(int j = 0 ; j < nums.size() ; j++){
                if(j == i) continue;
                if(nums[j] + nums[i] == target)
                return{i,j};
            }
        }
    return {};
    }
};

//Approach 2
//Using map 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int>mp;

        for(int i = 0; i< nums.size(); i++){
            int remain = target - nums[i];

            if(mp.find(remain) != mp.end()){
                return {mp[remain], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};