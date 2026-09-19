// ## LC 22 — Generate Parentheses

// ### Intuition

// Build the string one bracket at a time.

// At every step ask:

// "Can I add '('?"
// "Can I add ')'?"
class Solution {
public:

    void solve(int n,
               int open,
               int close,
               string& path,
               vector<string>& ans) {

        // Complete string
        if (path.size() == 2 * n) {
            ans.push_back(path);
            return;
        }

        // RULE 1:
        // We still have '(' available
        if (open < n) {
            path.push_back('(');

            solve(n, open + 1, close, path, ans);

            path.pop_back();
        }

        // RULE 2:
        // We have an unmatched '('
        if (close < open) {
            path.push_back(')');

            solve(n, open, close + 1, path, ans);

            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string path;

        solve(n, 0, 0, path, ans);

        return ans;
    }
};



// ### Rule 1

// open < n

// → Can add '('

// ### Rule 2

// close < open

// → Can add ')'

// Why?

// Because every ')' must close an existing '('.

// ### Base condition

// path.size() == 2 * n

// → complete answer
// → save path

// ### Backtracking

// push
// ↓
// recurse
// ↓
// pop

// ### Memory Trigger

// '(' → limited by n

// ')' → limited by open brackets

// The most important rule:

// close < open
