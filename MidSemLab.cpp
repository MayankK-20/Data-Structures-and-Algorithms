//Question was to merge 2 sorted linked list only by changing pointers.

#include<iostream>
using namespace std;

class Node{

	int data;
	Node* next=nullptr;

	public:
	Node(int x){
		data = x;
	}
	
	void push(Node* &head, int x){
		if (head==nullptr){
			head = new Node(x);
			return;
		}
		Node* tmp = head;
		while(tmp->next!=nullptr){
			tmp = tmp->next;
		}
		tmp->next = new Node(x);
	}
	
	void merge(Node* &head1, Node* &head2){
		
		Node* index1 = head1;
		Node* index2 = head2;
		Node* answer = nullptr;
		if (index1!=nullptr && index2!=nullptr && index1->data>index2->data){
			answer = index2;
			index2 = index2->next;
		}
		else{
			answer = index1;
			index1 = index1->next;
		}
		Node* ans = answer;
		while(index1!=nullptr && index2!=nullptr){
			if (index1->data<index2->data){
				answer->next = index1;
				answer = answer->next;
				index1 = index1->next;
			}
			else{
				answer->next = index2;
				answer = answer->next;
				index2 = index2->next;
			}
		}
		if (index2==nullptr){
			answer->next = index1;
		}
		else{
			answer->next = index2;
		}
		
		head1 = ans;	
	}

	void display(Node* head){
		if (head==nullptr){
			return;
		}
		if (head->next==nullptr){
			cout<<head->data<<endl;
			return;
		}
		cout<<head->data<<" ";
		display(head->next);
	}
};

int main(){

	Node* head1=nullptr;
	Node* head2=nullptr;
	int n,m;
	cin>>n>>m;
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		(*head1).push(head1,x);
	}
	for (int i=0; i<m; i++){
		int x;
		cin>>x;
		(*head2).push(head2,x);
	}
	if (head1==nullptr){
		(*head2).display(head2);
	}
	else{
		(*head1).merge(head1, head2);
		(*head1).display(head1);
	}

	return 0;
}