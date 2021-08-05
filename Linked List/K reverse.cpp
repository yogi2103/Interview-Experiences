Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* smallhead=reverseLinkedList(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallhead;
}

Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(k==0 || head==NULL || head->next==NULL){
        return head;
    }
    Node* curr=head;
    int l=k;
    while(k>1 && curr->next!=NULL){
        curr=curr->next;
        k--;
    }
    Node* secondhalf=curr->next;
    curr->next=NULL;
    Node* reverse=reverseLinkedList(head);
    head->next=kReverse(secondhalf,l);
    return reverse;
}
