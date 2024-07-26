#include<iostream>
#include<climits>
using namespace std;

class Node{
    public:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

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
        else{
            BST(root->right, x);
            return;
        }
    }

    bool valid(Node* root, int upperLimit=INT_MAX, int lowerLimit=INT_MIN, bool flag=true, bool flag2=true){
        if (root==nullptr){
            return true;
        }
        if (root->data == INT_MAX  && flag && upperLimit==INT_MAX){
            flag=false;
            if (root->right!=nullptr || root->data<=lowerLimit){
                return false;
            }
            return valid(root->left, root->data, lowerLimit, flag, flag2);
        }
        if (root->data == INT_MIN  && flag2 && lowerLimit==INT_MIN){
            flag2=false;
            if (root->left!=nullptr || root->data>=upperLimit){
                return false;
            }
            return valid(root->right, upperLimit, root->data, flag, flag2);
        }
        if (root->data<=lowerLimit || root->data>=upperLimit){
            return false;
        }
        if (valid(root->left, root->data, lowerLimit)){
            if (valid(root->right, upperLimit, root->data)){
                return true;
            }
        }
        return false;        
    }
};

int main(){

    //The valid function checks if the tree is a valid Binary search tree or not.


    //The tree i am making is by making a tree of half the elements and joining it with root->left and other half with root->right
    Node* root=nullptr;
    int n;
    cout<<"Input the number of elements: ";
    cin>>n;
    cout<<"Input the elements of the tree (please give only integer values): ";
    int x;
    cin>>x;
    (*root).BST(root, x);
    for (int i=1; i<n; i++){
        cin>>x;
        if (i<=n/2){
            (*root).BST(root->left, x);
        }
        else{
            (*root).BST(root->right, x);
        }
    }
    if ((*root).valid(root)){
        cout<<"Valid BST\n";
    }
    else{
        cout<<"BST not valid\n";
    }

    return 0;
}