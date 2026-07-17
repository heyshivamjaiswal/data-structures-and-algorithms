//Method 1 - Using hasing 
// num1 + num2 + num3 = 0 , num1 + num2 = -num3

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>st;
        for(int i = 0; i < n ; i++){
            set<int>hashset; //empty the set after every iteration to store the newer triplets

            for(int j=i+1; j<n ; j++){
                int third = -(nums[i] + nums[j]);
                if(hashset.find(third) != hashset.end()){ //if third element is in set
                    vector<int>temp = {nums[i] , nums[j] , third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};

//Method 2
//take 3 pointers fix the first one (i) , place 2nd one at (j+1) and third pointer at n-1
//move the j and k pointer , if sum < 0 j++ and if sum > 0 k-- , make sure pointer don't go out of array and avoid taking previous duplicate value
// TC: logN for sorting and O(n2) for nested loop 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        for(int i  = 0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i +1;
            int k = n - 1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int>temp = {nums[i] , nums[j] , nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};