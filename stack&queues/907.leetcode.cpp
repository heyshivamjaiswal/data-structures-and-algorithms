// METHOD 1 brute force (generate all possible arrays)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0; 
        int n = arr.size();
        int mod = (1e9+7);

        for(int i = 0; i<n; i++){
            int mini = arr[i];
            for(int j = i; j <n ;j++){
                mini = min(mini , arr[j]);
                sum = (sum + mini)%mod;
            }
        }
        return sum;
    }

};