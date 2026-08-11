

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node gives us a fixed starting point
        // so we don't need a special case for the first node.
        ListNode* dummy = new ListNode(-1);

        // temp always points to the last node
        // in our merged list.
        ListNode* temp = dummy;

        // Keep going while at least one list has nodes.
        while (list1 != nullptr || list2 != nullptr) {

            // If list1 is empty, take from list2.
            if (list1 == nullptr) {
                temp->next = list2;
                break;
            }

            // If list2 is empty, take from list1.
            if (list2 == nullptr) {
                temp->next = list1;
                break;
            }

            // Take the smaller current value.
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            // Move temp to the newly added node.
            temp = temp->next;
        }

        // Dummy itself isn't part of the answer.
        return dummy->next;
    }
};