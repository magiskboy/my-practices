/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    Node* tmp;
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL){
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    head = prev; 
    return head;
}
