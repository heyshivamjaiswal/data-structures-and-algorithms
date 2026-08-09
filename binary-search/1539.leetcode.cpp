// 1539 = Kth Missing Positive

// At index i:
// missing = arr[i] - (i + 1)

// missing < k
// → not enough missing
// → go RIGHT

// missing >= k
// → enough missing
// → go LEFT

// After binary search:
// answer = left + k


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0;
        int right = n-1;

        while(left <= right){
            int mid = left+(right-left)/2;

            int missing = arr[mid] - (mid+1);

            if(missing < k){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left+k;
    }
};