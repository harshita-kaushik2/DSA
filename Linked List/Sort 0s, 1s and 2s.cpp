/*
Approach 1 : NAIVE => Count the number of 0s, 1s and 2s via traversal. Then go back to the head of the list and start overwriting
data of the nodes. 
*/
Node* sortList(Node *head){
    Node* temp = head;
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    while(temp != NULL){
        if(temp->data == 0) zeroCount++;
        else if(temp->data == 1)    oneCount++;
        else if(temp->data == 2)    twoCount++;
        temp = temp->next;
    }

    temp = head;
    for(int i=0; i<zeroCount; i++){
        temp->data = 0;
        temp = temp->next;
    }
     for(int i=0; i<oneCount; i++){
        temp->data = 1;
        temp = temp->next;
    }
     for(int i=0; i<twoCount; i++){
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}

/*
Approach 2 => Create 3 head dummy nodes for 0, 1 and 2. Then,also have a tail pointer to the head so that we can insert at 
tail operation. Now we traverse through the list and keep adding to the tail of respective lists.Now merge them taking care
that elements were added after dummy head in each list. *Check if list of 1 is empty or not* Delete dummy nodes.
*/

void insertAtTail(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
}
Node* sortList(Node *head){
    Node* zeroHead = new Node (-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node (-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node (-1);
    Node* twoTail = twoHead; 

    Node* curr = head;
    while(curr != NULL){        //Insert elements to respective lists while traversing
        int val = curr->data;
        if(val == 0){
            insertAtTail(zeroTail, curr);
        }
        else if(val == 1){
            insertAtTail(oneTail, curr);
        }
        else if(val == 2){
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }
    if(oneHead->next != NULL)                   //what if there were no 1s in the list. You cannot make 0 tail point to NULL
       zeroTail->next = oneHead->next;
    else 
        zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;                   //I fucked up at this. Forgot to add this and had TLE.
    
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}
