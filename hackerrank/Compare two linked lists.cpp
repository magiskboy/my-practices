/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
    Node* tmpA = headA;
    Node* tmpB = headB;
    while (tmpA != NULL || tmpB != NULL){
        if ((tmpA != NULL && tmpB == NULL) || (tmpA == NULL && tmpB != NULL)) return 0;
        if (tmpA->data != tmpB->data) return 0;
        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }
    return 1;
}
