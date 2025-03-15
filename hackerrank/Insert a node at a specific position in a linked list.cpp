/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
    Node* newNode = new Node();
    newNode->data = data;
    if (head == NULL){
        newNode->next = NULL;
        head = newNode;
        return head;
    }
    if (position == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* tmp = head;
    for (int i = 0; i < position - 1; i++){
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    return head;
}
