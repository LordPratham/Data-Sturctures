#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int d, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
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
        insertAtTail(head, tail, d);
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->prev = temp;
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
}
void deleteAtBegin(Node *&head)
{
    Node *temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete (temp);
}

void deleteAtPosition(Node* &head,Node* &tail,int pos) {
    if (pos==1){
        deleteAtBegin(head);
        return;
    }
    int cnt=1;
    Node* curr=head;
    Node* prev=NULL;
    while(cnt<pos){
        prev=curr;
        curr=curr->next;
        cnt++;

    }
    prev->next=curr->next;
    curr->next->prev=prev;
    curr->next=NULL;
    curr->prev=NULL;
    delete curr;



}


void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}
int getLenght(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int main(int argc, char const *argv[])
{
    Node *node1 = new Node(0);
    Node *head = NULL;
    Node *tail = NULL;
    // insertAtHead(head,tail, 1);
    // insertAtHead(head,2);
    // insertAtHead(head,3);
    // insertAtHead(head,4);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    // deleteAtBegin(head);
    insertAtPosition(head, tail, 10, 1);
    deleteAtPosition(head,tail,2);
    print(head);
    // cout<<getLenght(head);

    return 0;
}
