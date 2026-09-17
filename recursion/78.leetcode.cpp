class Solution {
public:
    void solve(int i,
               vector<int>& nums,
               vector<int>& path,
               vector<vector<int>>& ans) {

        // RULE 3:
        // We have made decisions for every element
        if (i == nums.size()) {
            ans.push_back(path);
            return;
        }

        // RULE 1:
        // Choice 1 → Take nums[i]
        path.push_back(nums[i]);

        solve(i + 1, nums, path, ans);

        // RULE 4:
        // Undo the choice
        path.pop_back();

        // RULE 1:
        // Choice 2 → Don't take nums[i]
        solve(i + 1, nums, path, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(0, nums, path, ans);

        return ans;
    }
};

// Time  → O(n × 2ⁿ)
// Space → O(n × 2ⁿ) including output
