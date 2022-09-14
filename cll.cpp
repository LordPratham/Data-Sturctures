#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
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

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        // Node* temp=new Node(d);
        // temp->next=tail->next;
        // tail->next=temp;
        // tail=temp;
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node *&tail, int element)
{
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if(curr==prev){
        tail=NULL;
    }
    else if(tail==curr){
        tail=prev;
    }

    curr->next = NULL;
    delete curr;
}
void print(Node *tail)
{
    if (tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node *temp = tail;
    // Node* temp=tail->next;
    // while (temp!=tail){
    //     cout<<temp->data<<"-> ";
    //     cout<<"temp is "<<temp<<" Value is "<<temp->data<<endl;
    //     temp=temp->next;
    //     cout<<"Tail is "<<temp<<" Value is "<<temp->data<<endl;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail);
}

int main(int argc, char const *argv[])
{
    Node *tail = NULL;
    insertNode(tail, 5, 1);
    // cout << "Tail is " << tail << " Value is " << tail->data << endl;
    // insertNode(tail, 1, 2);
    // insertNode(tail, 2, 3);
    // insertNode(tail, 3, 4);
    // insertNode(tail, 2, 5);
    // deleteNode(tail, 5);
    // deleteNode(tail, 1);
    // cout<<"Tail is "<<tail<<" Value is "<<tail->data<<endl;
    // insertNode(tail,3);
    // cout<<"Tail is "<<tail<<" Value is "<<tail->data<<endl;
    print(tail);
    deleteNode(tail,1);
    print(tail);

    return 0;
}
