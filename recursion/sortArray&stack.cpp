// Take the last element out → sort everything else → put that element back in its correct position.

// SORT
//  │
//  ├── remove last
//  │
//  ├── SORT the remaining elements
//  │
//  └── INSERT removed element 


// INSERT
//  │
//  ├── Is temp bigger than last?
//  │       │
//  │       ├── YES → put temp at end
//  │       │
//  │       └── NO  → remove last
//  │                  INSERT temp
//  │                  put removed element back

// Ex:- [5,2,4]
// sort() goes DOWN first

// [5,2,4]
//    ↓ remove 4

// [5,2]
//    ↓ remove 2

// [5]
//    ↓
//  STOP

//  Now recursion comes BACK UP:

//  [5]
//  ↓
// insert 2

// [2,5]
//  ↓
// insert 4

// [2,4,5]


#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& v, int temp) {
    // If vector is empty or temp belongs at the end
    if (v.size() == 0 || v.back() <= temp) {
        v.push_back(temp);
        return;
    }

    // Remove the last element temporarily
    int val = v.back();
    v.pop_back();

    // Insert temp into the correct position
    insert(v, temp);

    // Put the removed element back
    v.push_back(val);
}

void sort(vector<int>& v) {
    // Base case
    if (v.size() <= 1)
        return;

    // Remove the last element
    int temp = v.back();
    v.pop_back();

    // Sort the remaining vector
    sort(v);

    // Insert removed element in its correct position
    insert(v, temp);
}

int main() {
    vector<int> v = {5, 2, 4, 1, 3};

    sort(v);

    for (int x : v)
        cout << x << " ";

    return 0;
}

//Similar problem

#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int>& st, int temp) {
    // If stack is empty or temp belongs on top
    if (st.empty() || st.top() <= temp) {
        st.push(temp);
        return;
    }

    // Remove the top element temporarily
    int val = st.top();
    st.pop();

    // Insert temp into the correct position
    insert(st, temp);

    // Put the removed element back
    st.push(val);
}

void sortStack(stack<int>& st) {
    // Base case
    if (st.size() <= 1)
        return;

    // Remove the top element
    int temp = st.top();
    st.pop();

    // Sort the remaining stack
    sortStack(st);

    // Insert removed element into its correct position
    insert(st, temp);
}

int main() {
    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

//Template 
int temp = st.top();
st.pop();

recursiveCall();

st.push(temp);