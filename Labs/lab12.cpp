#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
    string key;
    string value;
    Node* next=nullptr;

    public:
    Node(pair<string,string> x){
        key=x.first;
        value=x.second;
    }

    void insert(Node*& head, pair<string,string> x){
        if (head==nullptr){
            head=new Node(x);
        }
        Node* tmp=head;
        while(tmp->next!=nullptr){
            if(tmp->key==x.first){
                tmp->value=x.second;
                return;
            }
            tmp=tmp->next;
        }
        if(tmp->key==x.first){
            tmp->value=x.second;
            return;
        }
        tmp->next=new Node(x);
    }

    void del(Node*& head, string k){
        if (head==nullptr){
            return;
        }
        if (head->key==k){
            Node* tmp=head;
            head=head->next;
            delete tmp;
            return;
        }
        Node* tmp=head;
        while(tmp->next!=nullptr && tmp->next->key!=k){
            tmp=tmp->next;
        }
        if (tmp->next==nullptr){
            return;
        }
        Node* todel=tmp->next;
        tmp->next=todel->next;
        delete todel;
        return ;
    }

    string search(Node* head, string x){
        int index=0;
        while(head!=nullptr){
            if (head->key==x){
                return to_string(index);
            }
            head=head->next;
            index++;
        }
        return "Key not present";
    }

    void display(Node* head){
        if (head==nullptr){
            cout<<endl;
            return;
        }
        if(head->next==nullptr){
            cout<<head->key<<": "<<head->value<<endl;
            return;
        }
        cout<<head->key<<": "<<head->value<<" --> ";
        display(head->next);
    }
};

void OA(vector<pair<string,string>>& v, int n, int index, pair<string,string> x){
    for (int i=0; i<v.size(); i++){
        index=(index+i)%(v.size());
        if (v[index].first=="" || v[index].first==x.first){
            v[index]=x;
            return; 
        }
    }
    cout<<"Hashtable full\n";
}

void hashingOA(vector<pair<string,string>>& v, int n, pair<string,string> x){
    int index=0;
    for (int i=0; i<x.first.size(); i++){
        index+=x.first[i];
    }
    index=index%n;
    OA(v, n, index, x);
}

void hashingCA(vector<Node*>& v, int n, pair<string,string> x){
    int index=0;
    for (int i=0; i<x.first.size(); i++){
        index+=x.first[i];
    }
    index=index%n;
    (*v[index]).insert(v[index], x);
}

void deleteCA(vector<Node*>& v, string key){
    int index=0;
    for (int i=0; i<key.size(); i++){
        index+=key[i];
    }
    index=index%(v.size());
    (*v[index]).del(v[index], key);
}

void deleteOA(vector<pair<string,string>>& v, string x){
    int index=0;
    for (int i=0; i<x.size(); i++){
        index+=x[i];
    }
    index=index%(v.size());
    for (int i=0; i<v.size(); i++){
        index=(index+i)%(v.size());
        if (v[index].first==x){
            v[index]=make_pair("","");
            return;
        }
    }
}

string searchOA(vector<pair<string,string>> v, string x){
    int index=0;
    for (int i=0; i<x.size(); i++){
        index+=x[i];
    }
    index=index%(v.size());
    for (int i=0; i<v.size(); i++){
        index=(index+i)%(v.size());
        if (v[index].first==x){
            return to_string(index);
        }
    }
    return "key not present";
}

string searchCA(vector<Node*> v, string x){
    int index=0;
    for (int i=0; i<x.size(); i++){
        index+=x[i];
    }
    index=index%(v.size());
    return (*v[index]).search(v[index], x);
}

int main(){
    
    int n;
    cout<<"Input size of the hashtable: ";
    cin>>n;
    string type;
    cout<<"Input type of hashtable('open' for open addressing & 'close' for close addressing): ";
    cin>>type;
    if (type[0]=='o' || type[0]=='O'){
        vector<pair<string,string>> openAddressing(n);
        for (int i=0; i<n; i++){
            openAddressing[i].first="";
        }
        int k;
        cout<<"Input number of elements you want to represent: ";
        cin>>k;
        cout<<"Input elements in a pair\n";
        string num;
        string value;
        for (int i=0; i<k; i++){
            cin>>num;
            cin>>value;
            hashingOA(openAddressing, n, make_pair(num, value));
        }
        for (int i=0; i<openAddressing.size(); i++){
            cout<<openAddressing[i].first<<"\n";
        }
        string toRemove;
        cout<<"Input key to remove: ";
        cin>>toRemove;
        deleteOA(openAddressing, toRemove);
        for (int i=0; i<openAddressing.size(); i++){
            cout<<openAddressing[i].first<<openAddressing[i].second<<"\n";
        }
        string toFind;
        cout<<"Input key to find: ";
        cin>>toFind;
        cout<<searchOA(openAddressing, toFind);
    }
    else{
        vector<Node*> closeAddressing(n);
        for (int i=0; i<n; i++){
            closeAddressing[i]=nullptr;
        }
        int k;
        cout<<"Input number of elements you want to represent: ";
        cin>>k;
        cout<<"Input elements in a pair\n";
        string num;
        string value;
        for (int i=0; i<k; i++){
            cin>>num;
            cin>>value;
            hashingCA(closeAddressing, n, make_pair(num, value));
        }
        for (int i=0; i<closeAddressing.size(); i++){
            (*closeAddressing[i]).display(closeAddressing[i]);
        }
        string toRemove;
        cout<<"Input key to remove: ";
        cin>>toRemove;
        deleteCA(closeAddressing, toRemove);
        for (int i=0; i<closeAddressing.size(); i++){
            (*closeAddressing[i]).display(closeAddressing[i]);
        }
        string toFind;
        cout<<"Input key to find: ";
        cin>>toFind;
        cout<<searchCA(closeAddressing, toFind);
    } 

    return 0;
}