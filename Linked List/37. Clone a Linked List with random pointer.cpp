// METHOD 1 => USING EXTRA SPACE = TC : o(2N) sc : O(N) ------------------------------------------------------------------>
Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> map;

    Node* itr = head;
    while(itr) {
        map[itr] = new Node(itr->val);
        itr=itr->next;
    }

    itr = head;
    while(itr) {
        map[itr]->next = map[itr->next];
        map[itr]->random = map[itr->random];
        itr = itr->next;
    }
    return map[head];
}

// METHOD 2 => POINTER MANIPULATION & NO EXTRA SPACE = RC : O(3N) SC : O(1) --------------------------------------------->
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* original = head; // itr for original
        Node* cloned = nullptr; // itr for cloned
        Node* temp = nullptr; // temporary for node creation

        // First pass: clone nodes and link them next to origial
        while(original) {
            temp = new Node(original->val);
            temp->next = original->next;
            original->next=temp;
            original = temp->next;
        }

        original = head;
        Node* newHead = head->next;

        // Second pass: Assign random pointers to cloned nodes
        while(original) {
            if(original->random)    original->next->random = original->random->next;
            
            else  original->next->random = nullptr;
            
            original = original->next->next; // skip copy
        }
        
        original = head;

        // Third Pass: Seperate original and cloned 
        while(original) {
            temp = original->next; 
            original->next = temp->next; 
            original = original->next;

            if(original)     temp->next = original->next;
            else        temp->next = nullptr;
        }
    return newHead;
    }
};