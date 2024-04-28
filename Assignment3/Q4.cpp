#include <iostream>
using namespace std;

class AVL {
    int data;
    AVL* lchild = nullptr;
    AVL* rchild = nullptr;
    int height = 1; 
    int leftNodes = 0;
    int rightNodes = 0;

public:
    AVL(int x) {
        data = x;
    }

    AVL* leftRotate(AVL* head) {
        AVL* root = head->rchild;
        head->rchild = root->lchild;
        root->lchild = head;

        head->height = 1 + maxim(heightof(head->lchild), heightof(head->rchild));
        root->height = 1 + maxim(heightof(root->lchild), heightof(root->rchild));
        head->rightNodes = countNodes(head->rchild);
        root->leftNodes = countNodes(root->lchild);

        return root;
    }

    AVL* rightRotate(AVL* head) {
        AVL* root = head->lchild;
        head->lchild = root->rchild;
        root->rchild = head;

        head->height = 1 + maxim(heightof(head->lchild), heightof(head->rchild));
        root->height = 1 + maxim(heightof(root->lchild), heightof(root->rchild));
        head->leftNodes = countNodes(head->lchild);
        root->rightNodes = countNodes(root->rchild);

        return root;
    }

    AVL* insert(AVL* &head, int x) {
        if (head == nullptr) {
            head = new AVL(x);
            return head;
        }
        if (head->data > x) {
            head->leftNodes++;
            head->lchild = insert(head->lchild, x);
        }
        else if (head->data < x) {
            head->rightNodes++;
            head->rchild = insert(head->rchild, x);
        }
        else {
            return head;
        }

        head->height = 1 + maxim(heightof(head->lchild), heightof(head->rchild));

        if ((heightof(head->lchild)-heightof(head->rchild))>1 && head->lchild->data<x) {
            head->lchild = leftRotate(head->lchild);
            return rightRotate(head);
        }
        else if ((heightof(head->lchild)-heightof(head->rchild))<-1 && head->rchild->data>x) {
            head->rchild = rightRotate(head->rchild);
            return leftRotate(head);
        }
        else if ((heightof(head->lchild)-heightof(head->rchild))>1 && head->lchild->data>x) {
            return rightRotate(head);
        }
        else if ((heightof(head->lchild)-heightof(head->rchild))<-1 && head->rchild->data<x) {
            return leftRotate(head);
        }
        return head;
    }

    AVL* del(AVL* &head, int x) {
        if (head == nullptr) {
            return head;
        }
        if (head->data>x) {
            head->leftNodes--;
            head->lchild = del(head->lchild, x);
        }
        else if (head->data<x) {
            head->rightNodes--;
            head->rchild = del(head->rchild, x);
        }
        else {
            if (head->lchild == nullptr) {
                AVL* tmp = head->rchild;
                delete head;
                return tmp;
            }
            else if (head->rchild == nullptr) {
                AVL* tmp = head->lchild;
                delete head;
                return tmp;
            }
            AVL* tmp = head->rchild;
            while (tmp->lchild != nullptr) {
                tmp = tmp->lchild;
            }
            head->data = tmp->data;
            head->rchild = del(head->rchild, tmp->data);
        }

        head->height = 1 + maxim(heightof(head->lchild), heightof(head->rchild));

        int balance = heightof(head->lchild) - heightof(head->rchild);
        if (balance > 1 && heightof(head->lchild->lchild)-heightof(head->lchild->rchild)>=0) {
            return rightRotate(head);
        }
        if (balance > 1 && heightof(head->lchild->lchild)-heightof(head->lchild->rchild)<0) {
            head->lchild = leftRotate(head->lchild);
            return rightRotate(head);
        }
        if (balance < -1 && heightof(head->rchild->lchild)-heightof(head->rchild->rchild)<=0) {
            return leftRotate(head);
        }
        if (balance < -1 && heightof(head->rchild->lchild)-heightof(head->rchild->rchild)>0) {
            head->rchild = rightRotate(head->rchild);
            return leftRotate(head);
        }

        return head;
    }

    int maxim(int a, int b) {
        if (a>b){
            return a;
        }
        return b;
    }

    int heightof(AVL* node) {
        if (node==nullptr){
            return 0;
        }
        return node->height;
    }

    int countNodes(AVL* node) {
        if (node==nullptr){
            return 0;
        }
        return (node->leftNodes)+(node->rightNodes)+1;
    }

    int search(AVL* head, int index) {
        // cout<<index<<endl;
        if (head == nullptr) {
            return -1;
        }
        if (head->leftNodes+1==index) {
            return head->data;
        }
        if (head->leftNodes>=index){
            return search(head->lchild, index);
        }
        return search(head->rchild, index-(head->leftNodes+1));
    }

    // void display(AVL* head){
    //     if (head==nullptr){
    //         return;
    //     }
        
    //     cout<<"el: \n";
    //     cout<<"Data: "<<head->data<<endl;;
    //     cout<<"left Nodes: "<<head->leftNodes<<endl;
    //     cout<<"right Nodes: "<<head->rightNodes<<endl;
    //     display(head->lchild);
    //     display(head->rchild);
    // }
};

int main(){
    AVL* head=nullptr;
    cout<<"Input number of elements: ";
    int n;
    cin>>n;
    cout<<"Input numbers: ";
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        head = (*head).insert(head, x);
    }
    // (*head).display(head);
    int query;
    do{
        cout<<"Input Query: ";
        cin>>query;
        if (query==1){
            int k= (rand()%2==0? 1: n);
            // cout<<k<<endl;
            int ans;
            ans = (*head).search(head, k);
            cout<<"Output: "<<ans<<endl;
            head = (*head).del(head, ans);
            n--;
        }
        else if (query==2){
            int k;
            cout<<"Input k: ";
            cin>>k;
            int ans;
            ans = (*head).search(head, k);
            cout<<"Output: "<<ans<<endl;
            head = (*head).del(head, ans);
            n--;
        }
        else if (query==3){
            int ans;
            ans = (*head).search(head, (n+1)/2);
            cout<<"Output: "<<ans<<endl;
            head = (*head).del(head, ans);
            n--;
        }
    }while(query>0 && query<4 && n>0);

    return 0;

}
