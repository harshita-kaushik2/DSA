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
        cout << head->data << " ";  
        head = head->next;         
    }
}

// Function to insert a new node with value 'k' at the end of the doubly linked list
Node* insertAtTail(Node* head, int k) {
    Node* newNode = new Node(k);

    if (head == nullptr) {  // If the doubly linked list is empty, set 'head' to the new node
        return newNode;
    }

    Node* tail = head;
    while (tail->next != nullptr) {     // Traverse to the end of the doubly linked list
        tail = tail->next;
    }

    tail->next = newNode;   // Connect the new node to the last node in the list
    newNode->back = tail;

    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

cout << "Doubly Linked List Initially: " << endl;
    print(head);


    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
     // Insert a node with value 10 at the end
    head = insertAtTail(head, 10);
    print(head);

    return 0;
}
