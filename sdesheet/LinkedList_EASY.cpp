#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node* child;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->child = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *reverse(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node *reveseRecurrsive(Node *head)
{
    if (head->next == nullptr or head == nullptr)
        return head;

    Node *newHead = reveseRecurrsive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

Node* middle(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* mergeLL(Node* list1, Node* list2) {

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next; 
    }

    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    return dummyNode->next;
}


Node *removeNth(Node *head, int n)
{
    Node *fast = head;
    Node *slow = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;

    if (fast == nullptr)
        return head->next;

    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return head;
}

// given that the node to be delete is only provided not the head.
void deleteNode(Node* t) {
    t->data = t->next->data;
    t->next = t->next->next;
    return;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    int carry = 0;
    while ((l1 != NULL || l2 != NULL) || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        Node *nn = new Node(sum % 10);
        temp->next = nn;
        temp = temp->next;
    }
    return dummy->next;
}

Node* intersectionPresent(Node* head1,Node* head2) {
    Node* d1 = head1;
    Node* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    
    return d1;
}

bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true; 
        }
    }

    return false;
}

Node* getKthNode(Node* temp,int k){
    k--;
    while(temp!=nullptr and k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* kthReverse(Node* head, int k){
    Node* temp = head;
    Node* prev = nullptr;

    while(temp!=nullptr){
        Node* kthNode = getKthNode(temp,k);
        if(kthNode==nullptr){
            if(prev){
                prev->next = temp;
            }
            break;
        }
        Node* next = kthNode->next;
        kthNode->next = nullptr;

        reverse(temp);

        if(temp==head){
            head = kthNode;
        }
        else{
            prev->next = kthNode;
        }

        prev = temp;
        temp = next;
    }

    return head;
}


bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }

    Node* newHead = reverse(middle(head)->next);
    Node* first = head;  
    Node* second = newHead; 
    while (second != NULL) {
        if (first->data != second->data) {
            reverse(newHead);  
            return false;
        }
        first = first->next; 
        second = second->next;  
    }

    reverse(newHead);  
    return true;  
}


Node* merge(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }
    if(list1){
        res->child = list1;
    } else {
        res->child = list2;
    }
    if(dummyNode->child){
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

Node* flattenLinkedList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}

Node* rotateRight(Node* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    Node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    temp->next = head;
    k = k%length;
    int end = length-k;
    while(end--) temp = temp->next;
    head = temp->next;
    temp->next = NULL;
        
    return head;
}


int main()
{
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    printLinkedList(head);
    printLinkedList(kthReverse(head,2));
    return 0;
}