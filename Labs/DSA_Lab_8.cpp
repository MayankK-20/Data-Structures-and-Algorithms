#include<iostream>
using namespace std;

class BST{
    int data;
    BST* lchild=nullptr;
    BST* rchild=nullptr;

    public:
    BST(int x){
        data=x;
    }

    void insert(BST* &head, int x){
        if (head==nullptr){
            head=new BST(x);
            return;
        }
        if (head->data>x){
            insert(head->lchild, x);
        }
        else if (head->data<x){
            insert(head->rchild, x);
        }
    }

    BST* del(BST* &head, int x){
        if (head==nullptr){
            return head;
        }
        if (head->data==x){
            if (head->lchild==nullptr && head->rchild==nullptr){
                BST* tmp=head;
                head=nullptr;
                delete tmp;
                return head;
            }
            else if (head->lchild==nullptr){
                BST* tmp=head;
                head=head->rchild;
                delete tmp;
                return head;
            }
            else if (head->rchild==nullptr){
                BST* tmp=head;
                head=head->lchild;
                delete tmp;
                return head;
            }
            else{
                BST* tmp=head->rchild;
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
            return head;
        }
        else{
            head->lchild = del(head->lchild, x);
            return head;
        }
    }

    void inorder(BST* head){
        if (head==nullptr){
            return;
        }
        inorder(head->lchild);
        cout<<head->data<<" ";
        inorder(head->rchild);
    }

    void preorder(BST* head){
        if (head==nullptr){
            return;
        }
        cout<<head->data<<" ";
        preorder(head->lchild);
        preorder(head->rchild);
    }

    void postorder(BST* head){
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

    int heightCalc(BST* head){
        if (head==nullptr){
            return -1;
        }
        if (head->lchild==nullptr && head->rchild==nullptr){
            return 0;
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

    int BSTsCalculation(BST* head){
        if (head==nullptr){
            return 0;
        }
        if (head->lchild==nullptr && head->rchild==nullptr){
            return 1;
        }
        else if(head->lchild==nullptr){
            return 1+BSTsCalculation(head->rchild);
        }
        else if(head->rchild==nullptr){
            return 1+BSTsCalculation(head->lchild);
        }
        else{
            return BSTsCalculation(head->lchild)+BSTsCalculation(head->rchild)+1;
        }
    }
};

int main(){
    BST* head=nullptr;
    cout<<"Input number of elements: ";
    int n;
    cin>>n;
    cout<<"Input numbers: ";
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        (*head).insert(head, x);
    }

    (*head).inorder(head);
    cout<<endl;
    (*head).preorder(head);
    cout<<endl;
    (*head).postorder(head);
    cout<<endl;

    cout<<(*head).BSTsCalculation(head)<<endl;
    cout<<(*head).heightCalc(head)<<endl;
    int el;
    cout<<"Input element to delete: ";
    cin>>el;
    head = (*head).del(head, el);
    (*head).inorder(head);
    cout<<endl;
    (*head).preorder(head);
    cout<<endl;
    (*head).postorder(head);
    cout<<endl;

    cout<<(*head).BSTsCalculation(head)<<endl;

    cout<<(*head).heightCalc(head)<<endl;

    return 0;

}
