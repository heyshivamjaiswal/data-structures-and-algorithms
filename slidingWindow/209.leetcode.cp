//METHOD 1 (BRUTE FORCE)
//GENERATE ALL POSSIBLE STRING

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        for(int i = 0; i<n; i++){
            int currentSum = 0;
            for(int j=i; j<n; j++){
                currentSum+=nums[j];
                if(currentSum >= target){
                    minLen = min(minLen , j-i+1);
                      break;
                }
            }
        }
        return minLen == INT_MAX? 0 : minLen;
    }
};

//METHOD 2

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0; 
        int sum = 0;
        int ans = INT_MAX;
        for(int right = 0; right < n; right++){
            sum +=nums[right];

            while(sum >= target){
                ans = min(ans, right-left+1);
                sum -=nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};