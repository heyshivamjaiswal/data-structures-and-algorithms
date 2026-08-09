//METHOD 1 (BRUTE FORCE) O(m*n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == target)
                return true;
            }
        }
        return false;
    }
};


//Method 2 (optimal) O(nlog(m*n))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            int row = mid / cols;
            int col = mid % cols;

            if(matrix[row][col] == target)
                return true;

            if(matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};