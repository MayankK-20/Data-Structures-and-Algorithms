#include<iostream>
using namespace std;

class Node{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    public:
    Node(int x){
        data = x;
    }

    void BST(Node* &root, int x){
        if (root==nullptr){
            root = new Node(x);
            return;
        }
        if (x<root->data){
            BST(root->left, x);
            return;
        }
        else if (x>root->data){
            BST(root->right, x);
            return;
        }
    }

    void kSmallest(Node* root, int& k, int& ans){
        if (root==nullptr){
            return;
        }
        kSmallest(root->left, k, ans);
        if (k<0){
            return;
        }
        k--;
        if (k==0){
            ans = root->data;
            return;
        }
        kSmallest(root->right, k, ans);
    }
};

int main(){

    cout<<"Input number of elements in the tree: ";
    int n;
    cin>>n;
    Node* root = nullptr;
    cout<<"Input elements of tree with a space: ";
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        (*root).BST(root, x);
    }
    cout<<"Input K: ";
    int k;
    cin>>k;
    if (k<1){
        cout<<"Error: K cannot be negative or zero\n";
    }
    else{
        int ans=0;
        (*root).kSmallest(root, k, ans);
        if (k<1){
            cout<<ans<<endl;
        }
        else{
            cout<<"Number of elements in the BST are less than k\n";
        }
    }

    return 0;
}