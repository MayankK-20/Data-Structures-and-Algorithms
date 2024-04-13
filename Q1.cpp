#include<iostream>
using namespace std;

class AVL{
    int data;
    AVL* lchild=nullptr;
    AVL* rchild=nullptr;
    int balancingFactor=0;

    public:
    AVL(int x){
        data=x;
    }

    AVL* leftRotate(AVL* head){
        AVL* root=head->rchild;
        AVL* tmp=root->lchild;
        root->lchild = head;
        head->rchild = tmp;
        return root;
    }

    AVL* rightRotate(AVL* head){
        AVL* root=head->lchild;
        AVL* tmp=root->rchild;
        root->rchild = head;
        head->lchild = tmp;
        return root;
    }

    AVL* insert(AVL* &head, int x){
        if (head==nullptr){
            head=new AVL(x);
            return head;
        }
        if (head->data>x){
            head->lchild = insert(head->lchild, x);
        }
        else if (head->data<x){
            head->rchild = insert(head->rchild, x);
        }
        else {
            return head;
        }

        head->balancingFactor = (heightCalc(head->lchild)-(heightCalc(head->rchild)));

        if (head->balancingFactor>1 && head->lchild->data<x){
            head->lchild = leftRotate(head->lchild);
            return rightRotate(head);
        }
        else if (head->balancingFactor<-1 && head->rchild->data>x){
            head->rchild = rightRotate(head->rchild);
            return leftRotate(head);
        }
        else if (head->balancingFactor>1 && head->lchild->data>x){
            return rightRotate(head);
        }
        else if (head->balancingFactor<-1 && head->rchild->data<x){
            return leftRotate(head);
        }
        return head;
    }

    AVL* del(AVL* &head, int x){
        if (head==nullptr){
            return head;
        }
        if (head->data==x){
            if (head->lchild==nullptr && head->rchild==nullptr){
                AVL* tmp=head;
                head=nullptr;
                delete tmp;
                return head;
            }
            else if (head->lchild==nullptr){
                AVL* tmp=head;
                head=head->rchild;
                delete tmp;
                return head;
            }
            else if (head->rchild==nullptr){
                AVL* tmp=head;
                head=head->lchild;
                delete tmp;
                return head;
            }
            else{
                AVL* tmp=head->rchild;
                while(tmp->lchild!=nullptr){
                    tmp=tmp->lchild;
                }
                head->data=tmp->data;
                del(head->rchild, tmp->data);
                return head;
            }
        }
        else if(head->data<x){
            head->rchild = del(head->rchild, x);
        }
        else{
            head->lchild = del(head->lchild, x);
        }

        head->balancingFactor = (heightCalc(head->lchild)-(heightCalc(head->rchild)));

        if (head->balancingFactor>1 && head->lchild->data<x){
            head->lchild = leftRotate(head->lchild);
            return rightRotate(head);
        }
        else if (head->balancingFactor<-1 && head->rchild->data>x){
            head->rchild = rightRotate(head->rchild);
            return leftRotate(head);
        }
        else if (head->balancingFactor>1 && head->lchild->data>x){
            return rightRotate(head);
        }
        else if (head->balancingFactor<-1 && head->rchild->data<x){
            return leftRotate(head);
        }
        return head;
    }

    void inorder(AVL* head){
        if (head==nullptr){
            return;
        }
        inorder(head->lchild);
        cout<<head->data<<" ";
        inorder(head->rchild);
    }

    void preorder(AVL* head){
        if (head==nullptr){
            return;
        }
        cout<<head->data<<" ";
        preorder(head->lchild);
        preorder(head->rchild);
    }

    void postorder(AVL* head){
        if (head==nullptr){
            return;
        }
        postorder(head->lchild);
        postorder(head->rchild);
        cout<<head->data<<" ";
    }

    int maxi(int a, int b){
        if (a>b){
            return a;
        }
        return b;
    }

    int heightCalc(AVL* head){
        if (head==nullptr){
            return 0;
        }
        if (head->lchild==nullptr && head->rchild==nullptr){
            return 1;
        }
        else if(head->lchild==nullptr){
            return 1+heightCalc(head->rchild);
        }
        else if(head->rchild==nullptr){
            return 1+heightCalc(head->lchild);
        }
        else{
            return maxi(heightCalc(head->lchild),heightCalc(head->rchild))+1;
        }
    }

    AVL* search(AVL* head, int x){
        if (head==nullptr){
            return head;
        }
        if (head->data==x){
            return head;
        }
        else if (head->data<x){
            return search(head->rchild, x);
        }
        else{
            return search(head->lchild, x);
        }
    }
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
        cout<<"height after "<<i+1<<" insertions = "<<(*head).heightCalc(head)<<endl;
    }

    (*head).inorder(head);
    cout<<endl;
    (*head).preorder(head);
    cout<<endl;
    (*head).postorder(head);
    cout<<endl;

    cout<<"height of tree: "<<(*head).heightCalc(head)<<endl;
    int el;
    cout<<"Input element to delete: ";
    cin>>el;
    head = (*head).del(head, el);
    cout<<"Input element to delete: ";
    cin>>el;
    head = (*head).del(head, el);
    (*head).inorder(head);
    cout<<endl;
    (*head).preorder(head);
    cout<<endl;
    (*head).postorder(head);
    cout<<endl;
    cout<<"height of tree: "<<(*head).heightCalc(head)<<endl;
    cout<<"Input element to search: ";
    cin>>el;
    AVL* searched=(*head).search(head, el);
    if (searched==nullptr){
        cout<<"Element not in tree";
    }
    else{
        cout<<"Memory location: "<<searched;
    }
    // cout<<(searched==nullptr? "": "Memory location: ")<<searched;

    return 0;

}