// Problem	                  Traverse	           Pop Condition
// Next Greater Right	      Right → Left	        <=
// Next Smaller Right	      Right → Left	        >=
// Next Greater Left	      Left → Right	        <=
// Next Smaller Left	      Left → Right         	>=

// 1. Next Greater Element to Right (NGR)

vector<int> nextGreaterRight(vector<int>& arr) {
    int n = arr.size();

    stack<int> st;
    vector<int> ans(n);

    // Traverse from Right -> Left
    for (int i = n - 1; i >= 0; i--) {

        // Remove all smaller/equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is empty, no greater element exists
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }

    return ans;
}

// 2. Next Smaller Element to Right (NSR)

vector<int> nextSmallerRight(vector<int>& arr) {
    int n = arr.size();

    stack<int> st;
    vector<int> ans(n);

    // Traverse from Right -> Left
    for (int i = n - 1; i >= 0; i--) {

        // Remove all greater/equal elements
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is empty, no smaller element exists
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }

    return ans;
}

// 3. Next Greater Element to Left (NGL)

vector<int> nextGreaterLeft(vector<int>& arr) {
    int n = arr.size();

    stack<int> st;
    vector<int> ans(n);

    // Traverse from Left -> Right
    for (int i = 0; i < n; i++) {

        // Remove all smaller/equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is empty, no greater element exists
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }

    return ans;
}

// 4. Next Smaller Element to Left (NSL)

vector<int> nextSmallerLeft(vector<int>& arr) {
    int n = arr.size();

    stack<int> st;
    vector<int> ans(n);

    // Traverse from Left -> Right
    for (int i = 0; i < n; i++) {

        // Remove all greater/equal elements
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is empty, no smaller element exists
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }

    return ans;
}