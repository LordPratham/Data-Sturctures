#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
    ~Node(){
        int value =this->data;
        if(this->next!=NULL){
            delete next;
            this->next= NULL;
        }
        cout<<"Memory is free for node with value "<<value<<endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtPosition(Node *&head, Node *&tail, int d, int pos)
{
    // Node* temp= new Node(d);
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteAtBegin(Node *&head)
{
    Node *temp = head;
    head = head->next;
    temp->next=NULL;
    delete (temp);
}
void deleteNode(Node *&head,Node* &tail, int pos)
{
    if (pos == 1)
    {
        deleteAtBegin(head);
        return;
    }
    int cnt = 1;
    Node *curr = head;
    Node *prev=NULL;
    while (cnt < pos)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if (curr->next==NULL){
        tail=prev;
    }
    prev->next = curr->next;
    curr->next=NULL;
    delete curr;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        // cout<<temp<<endl;
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    Node *node1 = new Node(0);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtPosition(head, tail, 10, 1);
    insertAtPosition(head, tail, 10, 7);
    // deleteNode(head, tail, 7);
    // deleteNode(head, 4);
    deleteNode(head,tail, 1);
    print(head);
    cout<<endl<<head->data<<endl;
    cout<<tail->data<<endl;
    return 0;
}
