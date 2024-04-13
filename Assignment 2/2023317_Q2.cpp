#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next=nullptr;

    Node(int x):data(x){};
};

class Stack{
    Node* topMost=nullptr;

    public:
    // Stack constructor that has no arguments
    Stack(){};

    Stack(int x){
        topMost = new Node(x);
    }

    /*Push functions makes a temporary node and then joins temporary node to starting of the stack;
    It is just like adding a new node at beginning of a linked list*/
    void push(int x){
        Node* tmp = new Node(x);
        tmp->next = topMost;
        topMost = tmp;
    }

    /*Pop function deletes the first node (topMost element of stack) and returns the value stored within it*/
    int pop(){
        if (topMost==nullptr){
            cout<<"Stack is empty no element to delete returning -1\n";
            return -1;
        }
        Node* toDel = topMost;
        topMost = topMost->next;
        int deleted =  toDel->data;
        delete toDel;
        return deleted;
    }

    /*Empty function returns True when stack is empty and False when stack not empty*/
    bool empty(){
        return topMost==nullptr;
    }

    /*top function returns the value of the topMost element of the stack*/
    int top(){
        if (topMost==nullptr){
            cout<<"Stack is empty returning -1\n";
            return -1;
        }
        return topMost->data;
    }

    /*size function returns the number of elements in the stack*/
    int size(){
        int length=0;
        Node* tmp = topMost;
        while (tmp!=nullptr){
            tmp=tmp->next;
            length++;
        }
        return length;
    }
    
    /*display function shows all values in the stack in the order top to bottom*/
    void display(){
        if (topMost==nullptr){
            cout<<"Stack is empty\n";
            return;
        }
        Node* tmp=topMost;
        while(tmp!=nullptr){
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
};

class Queue{
    Node* front=nullptr;
    Node* back=nullptr;

    public:
    /*Queue constructor with no arguments*/
    Queue(){}

    Queue(int x){
        front = new Node(x);
        back = front;
    }

    /*enque function Pushes element in the queue*/
    void enqueue(int x){
        if (back==nullptr){
            front = new Node(x);
            back = front;
            return;
        }
        Node* tmp = new Node(x);
        back->next = tmp;
        back = tmp;
        return;
    }

    /*deque function removes an element of the queue*/
    int deque(){
        if (front==nullptr){
            cout<<"Queue is empty returning -1\n";
            return -1;
        }
        if (front==back){
            Node* toDel = front;
            front = nullptr;
            back = nullptr;
            int value=toDel->data;
            delete toDel;
            return value;
        }
        Node* toDel = front;
        front = front->next;
        int value = toDel->data;
        delete toDel;
        return value;
    }

    /*frontVal function returns the first element of the queue*/
    int frontVal(){
        if (front==nullptr){
            cout<<"Queue is empty returning -1\n";
            return -1;
        }
        return front->data;
    }

    /*size function returns the number of elements in the queue*/
    int size(){
        int length=0;
        Node* tmp = front;
        while(tmp!=nullptr){
            length++;
            tmp = tmp->next;
        }
        return length;
    }

    /*isEmpty function returns true if queue is empty*/
    bool isEmpty(){
        return front==nullptr;
    }

    /*display function shows all element in the queue in the order front to back*/
    void display(){
        if (front==nullptr){
            cout<<"Queue is empty\n";
            return;
        }
        Node* tmp = front;
        while (tmp!=nullptr){
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
};

int main(){

    int n;
    cout<<"Size of Array: ";
    cin>>n;
    cout<<"Input numbers with a space: ";
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    Stack st;
    int ans[n];
    int index=0;
    st.push(arr[0]);
    for (int i=1; i<n; i++){
        if (st.top()<arr[i]){
            st.pop();
            st.push(arr[i]);
            index=i;
        }
    }
    int ind=index-1;
    ans[index]=-1;
    while(index!=ind){
        if (ind==-1){
            ind=n-1;
            continue;
        }
        while(!st.empty() && st.top()<=arr[ind]){
            st.pop();
        }
        st.empty()==true? ans[ind]=-1: ans[ind]=st.top();
        st.push(arr[ind]);
        ind--;
    }
    cout<<"Output: [ ";
    for (int i=0; i<n-1; i++){
        cout<<ans[i]<<", ";
    }
    cout<<ans[n-1]<<" ]\n";

    return 0;
}