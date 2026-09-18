class Solution {
public:

    void solve(int i,
               vector<int>& candidates,
               int target,
               vector<int>& path,
               vector<vector<int>>& ans) {

        // RULE 3
        // We found a valid combination
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        // No candidates left
        if (i == candidates.size()) {
            return;
        }

        // RULE 4
        // Current candidate is too large
        if (candidates[i] > target) {
            return;
        }

        // RULE 5
        // TAKE current candidate
        path.push_back(candidates[i]);

        // Stay at i because we can reuse the number
        solve(i,
              candidates,
              target - candidates[i],
              path,
              ans);

        // RULE 7
        // Undo our choice
        path.pop_back();

        // RULE 6
        // DON'T TAKE current candidate
        solve(i + 1,
              candidates,
              target,
              path,
              ans);
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(0, candidates, target, path, ans);

        return ans;
    }
};

        //      CURRENT NUMBER
        //             |
        //      ┌──────┴──────┐
        //      ↓             ↓
        //    TAKE          DON'T TAKE
        //      ↓             ↓
        //   push()         nothing
        //      ↓             ↓
        // target - num     same target
        //      ↓             ↓
        //   same i          i + 1
        //      ↓             ↓
        //  recursive       recursive
        //   explore          explore
        //      ↓
        //   pop()


// RULE 1:
// TAKE current number
// → add it to path
// → subtract it from target
// → STAY at same index
// → because we can reuse it

// RULE 2:
// DON'T TAKE current number
// → don't add anything
// → target stays same
// → MOVE to next index

// RULE 3:
// After TAKE:
// → explore
// → POP
// → undo that choice

// RULE 4:
// target == 0
// → current path is a valid answer
// → SAVE it
