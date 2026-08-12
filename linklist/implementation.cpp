#include <iostream>

using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next; 
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

void addNode(ListNode* &head, ListNode* &tail, int val){
    ListNode* temp = new ListNode(val);
    if(tail == NULL){
        head = temp;
    }else {
        tail->next = temp;
    }
    tail = temp;
}

ListNode* deleteHead(ListNode* head){
    if(head == NULL) return NULL;
    return head -> next;
}

ListNode* deleteTail(ListNode* &head){
    if(head == NULL && head -> next == NULL) return NULL;
    
    ListNode* prev = head;
    ListNode* curr = head -> next;

    while(curr -> next != NULL){
        prev = curr;
        curr = curr -> next;
    }
    
    prev -> next = curr -> next;

    return head;
}

void print(ListNode* head){
    while(head != NULL){
        cout<<head->val<<" -> ";
        head = head -> next;
    }
    cout<<endl;
} 

int main() {

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int i = 0; i < 10; i++){
        addNode(head, tail, i + 1);
    }

    // head = deleteHead(head);
    head = deleteTail(head);
    head = deleteTail(head);

    print(head);

    return 0;
}