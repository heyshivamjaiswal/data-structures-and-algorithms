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






// ## LeetCode 46 — Permutations

// ### Intuition

// We have empty positions:

// [_, _, _]

// At every position:
// → try every UNUSED number.

// Example:

// [_,_,_]
//    ↓
// choose 1

// [1,_,_]
//    ↓
// choose 2

// [1,2,_]
//    ↓
// choose 3

// [1,2,3]

// Save it.

// Then BACKTRACK:
// remove 3
// remove 2
// try 3 instead

// → [1,3,2]

// ### Rules

// 1. Try every number at every level.

// 2. A number cannot be used twice
//    in the same permutation.
//    → used[]

// 3. Complete path:
//    path.size() == nums.size()
//    → save path.

// 4. After recursion:
//    undo the choice.

// ### Pattern

// choose
// ↓
// mark used
// ↓
// recurse
// ↓
// unmark
// ↓
// pop

// ### Memory Trigger

// PERMUTATION =
// "Who goes in this position?"

// Not:
// "Should I take this number?"
