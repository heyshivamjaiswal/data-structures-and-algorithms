// Before reaching middle:

// ┌──────────────┐
// │ Call 1       │
// │ temp = 5     │
// └──────────────┘
//        ↓
// ┌──────────────┐
// │ Call 2       │
// │ temp = 4     │
// └──────────────┘
//        ↓
// ┌──────────────┐
// │ Call 3       │
// │ delete 3     │
// └──────────────┘


// Then boxes are removed backwards:

// Call 3 finishes
//        ↓
// Call 2 resumes
//        ↓
// push(4)
//        ↓
// Call 1 resumes
//        ↓
// push(5)

#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int>& st, int k) {

    // Middle element reached
    if (k == 1) {
        st.pop();
        return;
    }

    // Save the top element
    int temp = st.top();
    st.pop();

    // Go deeper
    deleteMiddle(st, k - 1);

    // Reconstruct the stack
    st.push(temp);
}

int main() {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int k = st.size() / 2 + 1;

    deleteMiddle(st, k);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}