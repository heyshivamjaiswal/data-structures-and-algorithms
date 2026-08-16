

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insert(ListNode*sorted , ListNode*node){
        if(sorted == nullptr || node->val <= sorted->val){
        node->next = sorted;
        return node;
        }

        ListNode*curr = sorted;
        while(curr->next != nullptr && curr->next->val < node->val){
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
        return sorted;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode*sorted = insertionSortList(head->next);

        head->next = nullptr;

        return insert(sorted, head);
    }
};

// Complexity	
// Time	O(n²)
// Space	O(n) — recursion stack

// Insertion sort is naturally O(n²) because each new element may need to 
// scan the already-sorted portion. 
// Recursion doesn't magically improve that.