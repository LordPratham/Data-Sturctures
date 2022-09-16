#include<iostream>
using namespace std;
class Queue{
    public:
    int front;
    int rear;
    int size;
    int *arr;

    Queue(){
        size=10001;
        arr=new int[size];
        front=0;
        rear=0;
    }
    bool isEmpty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int element){
        if(rear!=size){
            arr[rear]=element;
            rear++;
        }
        else{
            cout<<"Queue is full"<<endl;
        }
    }
    int dequeue(){
        if(front==rear){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else{
            int ans =arr[front];
            arr[front]=-1;
            front++;
            if (front==rear){
                front=0;
                rear=0;
            }
            return ans;
        }
    }
    void disp(){
        int temp =front;
        while(temp<rear){
            cout<<arr[temp]<<"  ";
            temp++;
        }
    }


};
int main(int argc, char const *argv[])
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.disp();
    return 0;
}
