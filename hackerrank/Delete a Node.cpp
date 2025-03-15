/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
     if (position == 0){
         Node* tmp = head;
         head = tmp->next;
         delete tmp;
         tmp = NULL;
         return head;
    }
    Node* tmp = head;
    for (int i = 0; i < position - 1; i++){
        tmp = tmp->next;
    }
    Node* tmp2 = tmp->next;
    tmp->next = tmp2->next;
    delete tmp2;
    tmp2 = NULL;
    tmp = NULL;
    return head;
}
