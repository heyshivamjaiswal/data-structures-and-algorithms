class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& candidates, int target, int start, int remain) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }
        if (remain < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            // skip duplicates at the same tree depth
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // pruning: since sorted, no point going further
            if (candidates[i] > remain) break;

            path.push_back(candidates[i]);
            backtrack(candidates, target, i + 1, remain - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, target);
        return res;
    }
};
