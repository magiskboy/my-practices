void Print(struct Node* head){
    if (head == NULL) return;
    std::cout << head->data << std::endl;
    Print(head->next);
}