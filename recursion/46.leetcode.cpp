void solve(vector<int>& nums,
           vector<int>& path,
           vector<bool>& used,
           vector<vector<int>>& ans) {

    // Are all positions filled?
    if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
    }

    // Try every number
    for (int i = 0; i < nums.size(); i++) {

        // Already used? Don't choose it.
        if (used[i]) {
            continue;
        }

        // Choose
        path.push_back(nums[i]);
        used[i] = true;

        // Build the remaining positions
        solve(nums, path, used, ans);

        // Undo
        used[i] = false;
        path.pop_back();
    }
}


    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>path;
       vector<bool>used(nums.size(), false);
       solve(nums,path,used,ans);
       return ans; 
    }
};
