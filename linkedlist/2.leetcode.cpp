// 
Dummy = fake starting node.

// curr starts at dummy.

// Create answer:
// curr->next = new Node(value)
// curr = curr->next

// Return:
// dummy->next

// Time: O(max(n,m)) because every node is processed once. 
// Space: O(max(n,m)) for the output list, or O(1) auxiliary space excluding the output.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummyNode = new ListNode(-1);
        ListNode * temp = dummyNode;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = carry;

            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum +=l2->val;
                l2 = l2->next;
            }

            carry = sum/10;
            int lastDigit = sum%10;
            temp->next = new ListNode(lastDigit);
            temp = temp->next;
        }
        return dummyNode->next;
    }
};