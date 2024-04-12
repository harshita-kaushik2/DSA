class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode dummy(0); // Create a dummy node to simplify edge cases
        dummy.next = head;
        ListNode* prevLeft = &dummy;
        ListNode* rightNode = &dummy;

        // Find the node just before left and the node at right
        for (int i = 0; i < left - 1; ++i) {
            prevLeft = prevLeft->next;
        }
        for (int i = 0; i < right; ++i) {
            rightNode = rightNode->next;
        }

        // Store pointers to the nodes involved in the reversal
        ListNode* leftNode = prevLeft->next;
        ListNode* afterRight = rightNode->next;

        // Disconnect the portion to be reversed from the list
        prevLeft->next = nullptr;
        rightNode->next = nullptr;

        // Reverse the portion between left and right
        ListNode* prev = nullptr;
        ListNode* curr = leftNode;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Reattach the reversed portion to the list
        prevLeft->next = rightNode;
        leftNode->next = afterRight;

        return dummy.next;
    }
};
