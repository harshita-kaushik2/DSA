class Node {
public:
    int data;   
    Node* next;     
    Node* back;     

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
   // Create the head node with the first element of the array
    Node* head = new Node(arr[0]); 
   // Initialize 'prev' to the head node

    Node* prev = head;             
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node

        prev->next = temp;    
        // Move 'prev' to the newly created node for the next iteration
   
       prev = temp;         
     }
    // Return the head of the doubly linked list

    return head;  
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the current node
        cout << head->data << " "; 
        // Move to the next node
        head = head->next;         
    }
}

// Function to delete the head of the doubly linked list
Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; 
    }

   // Store the current head as 'prev'
    Node* prev = head;      
     // Move 'head' to the next node
    head = head->next;    

 // Set 'back' pointer of the new head to nullptr
    head->back = nullptr;   

 // Set 'next' pointer of 'prev' to nullptr
    prev->next = nullptr;  
    return head;          
}

// Function to delete the tail of the doubly linked list
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;  
    }
    
    Node* tail = head;
    while (tail->next != nullptr) {      // Traverse to the last node (tail)
        tail = tail->next; 
    }
    
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;  
    
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    
    cout << "Original Doubly Linked List: ";
    print(head);
    
    cout << "\n\nAfter deleting the tail node: ";
    head = deleteTail(head);
    print(head);

    return 0;
}
