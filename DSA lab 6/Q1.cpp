#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next=nullptr;

    public:
    Node(int x){
        data=x;
    }

    void insertAtTail(Node* &head, int x){
        if (head==nullptr){
            head= new Node(x);
            return;
        }
        Node* head2=head;
        Node* tmp = new Node(x);
        while (head->next!=nullptr){
            head=head->next;
        }
        head->next=tmp;
        head=head2;
    }

    void rotate(Node*& head){
        Node* tmp = head;
        while(head->next!=nullptr){
            head=head->next;
        }
        head->next=tmp;
        head=head->next->next;
        tmp->next=nullptr;
    }

    void display(Node* head){
        if (head==nullptr){
            cout<<"Empty List\n";
            return;
        }
        if (head->next==nullptr){
            cout<<head->data<<endl;
            return;
        }
        cout<<head->data<<"-->";
        display(head->next);
    }
};

int main(){

    int n,k;
    cin>>n;
    Node* head=nullptr;
    for (int i=0; i<n; i++){
        int j;
        cin>>j;
        (*head).insertAtTail(head, j);
    }
    (*head).display(head);
    cin>>k;
    while(k--){
        (*head).rotate(head);
    }
    (*head).display(head);

    return 0;
}