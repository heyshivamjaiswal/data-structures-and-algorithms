// 347. Top K Frequent Elements

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// • ans[i] stores the left product in the first pass.
// • suffix stores the right product in the second pass.
// • Final answer = left product × right product.
// • Assign first, then update prefix/suffix (to exclude the current element).

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
       vector<int>res(n);

       for(int i=0; i<n; i++){
        int prod = 1;
        for(int j = 0; j<n; j++){
            if(i != j){
                prod *= nums[j];
            }
            res[i] = prod;
        }
       } 
       return res;
    }
};



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};