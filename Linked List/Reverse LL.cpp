Question Link : https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897?source=youtube&campaign=Lovebabbarcodestudio_24thJan
/*
Approach 1 => Har node ko pakad ke peeche point karwana hai. 
*/
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)  {
    if(head == NULL || head->next == NULL)
    return head;

    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }
    return prev;
}

