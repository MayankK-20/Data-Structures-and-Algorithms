#include<iostream>
using namespace std;

class Node{
    int position;
    int health;
    char team;
    int order;
    Node* next=nullptr;
    Node* prev=nullptr;

    public:
    Node(int x, int y, char z, int a){
        position = x;
        health = y;
        team = z;
        order = a;
    }

    void push(Node* &head, int x, int y, char z, int a){
        if (head==nullptr){
            head = new Node(x, y, z, a);
        }
        else{
            Node* tmp = new Node(x, y, z, a);
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
    }

    Node* mergeO(Node* &head1, Node* &head2){
        if (head1==nullptr){
            return head2;
        }
        if (head2==nullptr){
            return head1;
        }
        Node* answer = nullptr;
        if (head1->order < head2->order){
            answer=head1;
            head1 = head1->next;
        }
        else{
            answer=head2;
            head2 = head2->next;
        }
        Node* ans = answer;
        while (head1!=nullptr && head2!=nullptr){
            if (head1->order > head2->order){
                answer->next = head2;
                head2->prev = answer;
                head2 = head2->next;
                answer = answer->next;
            }
            else{
                answer->next = head1;
                head1->prev = answer;
                head1 = head1->next;
                answer = answer->next;
            }
        }
        if (head1!=nullptr){
            answer->next = head1;
            head1->prev = answer;
        }
        else{
            answer->next = head2;
            head2->prev = answer;
        }
        return ans;
    }

    void mergeSortO(Node* &head, int size){
        if (head==nullptr){
            return;
        }
        if (size>1){
            Node* tmp = head;
            int move=0;
            while (move<(size/2)-1){
                tmp=tmp->next;
                move++;
            }
            Node* head2 = tmp->next;
            tmp->next = nullptr;
            head2->prev=nullptr;
            mergeSortO(head, size/2);
            mergeSortO(head2, size-(size/2));
            head = mergeO(head, head2);
        }       
    }

    Node* merge(Node* &head1, Node* &head2){
        if (head1==nullptr){
            return head2;
        }
        if (head2==nullptr){
            return head1;
        }
        Node* answer = nullptr;
        if (head1->position < head2->position){
            answer=head1;
            head1 = head1->next;
        }
        else{
            answer=head2;
            head2 = head2->next;
        }
        Node* ans = answer;
        while (head1!=nullptr && head2!=nullptr){
            if (head1->position > head2->position){
                answer->next = head2;
                head2->prev = answer;
                head2 = head2->next;
                answer = answer->next;
            }
            else{
                answer->next = head1;
                head1->prev = answer;
                head1 = head1->next;
                answer = answer->next;
            }
        }
        if (head1!=nullptr){
            answer->next = head1;
            head1->prev = answer;
        }
        else{
            answer->next = head2;
            head2->prev = answer;
        }
        return ans;
    }

    void mergeSort(Node* &head, int size){
        if (head==nullptr){
            return;
        }
        if (size>1){
            Node* tmp = head;
            int move=0;
            while (move<(size/2)-1){
                tmp=tmp->next;
                move++;
            }
            Node* head2 = tmp->next;
            tmp->next = nullptr;
            head2->prev=nullptr;
            mergeSort(head, size/2);
            mergeSort(head2, size-(size/2));
            head = merge(head, head2);
        }       
    }

    void fight(Node* &r, Node* &d){
        Node* fighter1=r;
        Node* fighter2=d;
        while (fighter1!=nullptr && fighter2!=nullptr){
            if (fighter1->position < fighter2->position){
                if (fighter1->next==nullptr || fighter1->next->position>fighter2->position){
                    if (fighter1->health>fighter2->health){
                        fighter1->health--;
                        Node* tmp = fighter2->prev;
                        if (tmp==nullptr){
                            tmp=fighter2;
                            fighter2=fighter2->next;
                            fighter2==nullptr? fighter2=fighter2:fighter2->prev=nullptr;
                            d=fighter2;
                            delete tmp;
                        }
                        else{
                            Node* toDel = fighter2;
                            fighter2=fighter2->next;
                            tmp->next = fighter2;
                            fighter2==nullptr? fighter2=fighter2:fighter2->prev = tmp;
                            delete toDel;
                        }
                    }
                    else if(fighter2->health>fighter1->health){
                        fighter2->health--;
                        Node* tmp = fighter1->prev;
                        if (tmp==nullptr){
                            tmp=fighter1;
                            fighter1=fighter1->next;
                            fighter1==nullptr? fighter1=fighter1:fighter1->prev=nullptr;
                            r=fighter1;
                            delete tmp;
                        }
                        else{
                            Node* toDel = fighter1;
                            fighter1=fighter1->next;
                            tmp->next = fighter1;
                            fighter1==nullptr? fighter1=fighter1:fighter1->prev = tmp;
                            fighter1=tmp;
                            delete toDel;
                        }
                    }
                    else{
                        Node* tmp = fighter2->prev;
                        if (tmp==nullptr){
                            tmp=fighter2;
                            fighter2=fighter2->next;
                            fighter2==nullptr? fighter2=fighter2:fighter2->prev=nullptr;
                            d=fighter2;
                            delete tmp;
                        }
                        else{
                            Node* toDel = fighter2;
                            fighter2=fighter2->next;
                            tmp->next = fighter2;
                            fighter2==nullptr? fighter2=fighter2:fighter2->prev = tmp;
                            delete toDel;
                        }
                        Node* tmp2 = fighter1->prev;
                        if (tmp2==nullptr){
                            tmp2=fighter1;
                            fighter1=fighter1->next;
                            fighter1==nullptr? fighter1=fighter1:fighter1->prev=nullptr;
                            r=fighter1;
                            delete tmp2;
                        }
                        else{
                            Node* toDel = fighter1;
                            fighter1=fighter1->next;
                            tmp2->next = fighter1;
                            fighter1==nullptr? fighter1=fighter1:fighter1->prev = tmp;
                            fighter1 = tmp2;
                            delete toDel;
                        }
                    }
                }
                else{
                    fighter1=fighter1->next;
                }
            }
            else{
                fighter2=fighter2->next;
            }
        }
    }

    void output(Node* head){
        cout<<"[ ";
        while(head!=nullptr){
            if (head->next==nullptr){
                cout<<head->health<<" ]";
                return;
            }
            cout<<head->health<<", ";
            head = head->next;
        }
        cout<<"]";
    }

    void display(Node* head){
        if (head == nullptr){
            cout<<"List is empty\n";
            return;
        }
        if (head->next == nullptr){
            cout<<"[ "<<head->position<<", "<<head->health<<", "<<head->team<<", "<<head->order<<" ]\n";
            return;
        }
        cout<<"[ "<<head->position<<", "<<head->health<<", "<<head->team<<", "<<head->order<<" ] <--> ";
        display(head->next);
    }

    int size(Node* head){
        int len = 0;
        while(head!=nullptr){
            head=head->next;
            len++;
        }
        return len;
    }
};

int main(){
    
    int n;
    cout<<"Size of Array: ";
    cin>>n;
    int position[n];
    int health[n];
    string team;
    Node* r = nullptr;
    Node* d = nullptr;
    cout<<"Input positions of the heroes with a space: ";
    for (int i=0; i<n; i++){
        cin>>position[i];
    }
    cout<<"Input health of the heroes with a space: ";
    for (int i=0; i<n; i++){
        cin>>health[i];
    }
    cout<<"Input team: ";
    cin>>team;
    int cntR=0, cntD=0;
    for (int i=0; i<n; i++){
        if (team[i]=='R'){
            (*r).push(r, position[i], health[i], team[i], i);
            cntR++;
        }
        else{
            (*d).push(d, position[i], health[i], team[i], i);
            cntD++;
        }
    }
    (*r).mergeSort(r, cntR);
    (*d).mergeSort(d, cntD);
    (*r).fight(r,d);
    (*r).mergeSortO(r, ((*r).size(r)));
    (*d).mergeSortO(d, ((*d).size(d)));
    r = (*r).mergeO(r, d);
    cout<<"Output: ";
    (*r).output(r);

    return 0;
}



//Alternate code
/*
#include<iostream>
using namespace std;

class Node{
    int position;
    int health;
    char team;
    int order;
    Node* next=nullptr;

    public:
    Node(int x, int y, char z, int a){
        position = x;
        health = y;
        team = z;
        order = a;
    }

    void push(Node* &head, int x, int y, char z, int a){
        if (head == nullptr){
            head = new Node(x, y, z, a);
            return;
        }
        if (head->next == nullptr  ||  head->position > x){
            if (head->position > x){
                Node* tmp = new Node(x, y, z, a);
                tmp->next = head;
                head = tmp;
                return;
            }
            head -> next = new Node(x, y, z, a);
            return;
        }
        Node* tmp = head;
        while (tmp->next!=nullptr && tmp->next->position<x){
            tmp = tmp->next;
        }
        if (tmp->next==nullptr){
            tmp->next=new Node(x, y, z, a);
            return;
        }
        Node* toInsert = new Node(x, y, z, a);
        toInsert->next = tmp->next;
        tmp->next = toInsert;
    }

    void fight(Node* &head){
        if (head == nullptr){
            return;
        }
        if (head->next==nullptr){
            return;
        }
        int fighting=1;
        while (fighting>0){
            fighting = 0;
            Node* tmp = head;
            Node* prev = nullptr;
            while (tmp!=nullptr && tmp->next != nullptr){
                if (tmp->team=='R' && tmp->team != tmp->next->team){
                    fighting++;
                    if (tmp->health > tmp->next->health){
                        tmp->health--;
                        Node* toDel = tmp->next;
                        tmp->next = toDel->next;
                        delete toDel;
                    }
                    else if(tmp->health < tmp->next->health){
                        tmp->next->health--;
                        if (prev==nullptr){
                            head=tmp->next;
                            Node* toDel=tmp;
                            tmp=tmp->next;
                            delete toDel;
                        }
                        else{
                            Node* toDel=tmp;
                            tmp=tmp->next;
                            prev->next = tmp;
                            delete toDel;
                        }
                    }
                    else{
                        if (prev==nullptr){
                            Node* toDel=tmp;
                            tmp=tmp->next;
                            Node* toDel2=tmp;
                            tmp=tmp->next;
                            head = tmp;
                            delete toDel;
                            delete toDel2;
                        }
                        else{
                            Node* toDel=tmp;
                            tmp=tmp->next;
                            Node* toDel2=tmp;
                            tmp=tmp->next;
                            prev->next = tmp;
                            delete toDel;
                            delete toDel2;
                        }
                    }
                }
                else{
                    prev = tmp;
                    tmp = tmp->next;
                }
            }
        }
        return;
    }

    void output(Node* head){
        if (head==nullptr){
            cout<<" ]\n";
            return;
        }
        if (head->next==nullptr){
            cout<<head->health<<" ]\n";
            return;
        }
        Node* min=head;
        Node* tmp=head;
        Node* prev=nullptr;
        while (tmp!=nullptr && tmp->next!=nullptr){
            if (tmp->next->order < min->order){
                prev=tmp;
                min=tmp->next;
            }
            tmp=tmp->next;
        }
        cout<<min->health<<", ";
        if (min==head){
            head = head->next;
            delete min;
        }
        else{
            prev->next = min->next;
            delete min;
        }
        output(head);
    }

    void display(Node* head){
        if (head == nullptr){
            cout<<"List is empty\n";
            return;
        }
        if (head->next == nullptr){
            cout<<"[ "<<head->position<<", "<<head->health<<", "<<head->team<<", "<<head->order<<" ]\n";
            return;
        }
        cout<<"[ "<<head->position<<", "<<head->health<<", "<<head->team<<", "<<head->order<<" ] --> ";
        display(head->next);
    }
};

int main(){
    
    int n;
    cout<<"Size of Array: ";
    cin>>n;
    int position[n];
    int health[n];
    string team;
    Node* head = nullptr;
    cout<<"Input positions of the heroes with a space: ";
    for (int i=0; i<n; i++){
        cin>>position[i];
    }
    cout<<"Input health of the heroes with a space: ";
    for (int i=0; i<n; i++){
        cin>>health[i];
    }
    cout<<"Input team: ";
    cin>>team;
    for (int i=0; i<n; i++){
        (*head).push(head, position[i], health[i], team[i], i);
    }
    (*head).fight(head);
    cout<<"Output: [ ";
    (*head).output(head);

    return 0;
}
*/