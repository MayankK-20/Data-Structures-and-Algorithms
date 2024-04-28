#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

//this code is an alternative for the code given and it works too
/*
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Node{
    vector<string> BT;
    
    public:
    void insertNode(string x){
        BT.push_back(x);
    }

    pair<int,int> search(string x, string y){
        pair<int,int> p;
        for (int i=0; i<BT.size(); i++){
            if (BT[i]==x){
                p.first=i;
            }
            if (BT[i]==y){
                p.second=i;
            }
        }
        p.first++;
        p.second++;
        return p;
    }

    bool check(pair<int,int> p){
        int lg1=log(p.first);
        int lg2=log(p.second);
        if (lg1==lg2 && ((p.first/2)-1)>=0 && ((p.second/2)-1)>=0 && BT[((p.first/2)-1)]!=BT[((p.second/2)-1)]){
            return true;
        }
        return false;
    }
};

int main(){

    Node students;
    int n;
    cout<<"Input the number of elements in the Binary tree(include N as elements): ";
    cin>>n;
    cout<<"Input the elements with a space: ";
    for (int i=0; i<n; i++){
        string x;
        cin>>x;
        students.insertNode(x);
    }
    cout<<"Input the pair of students with a space: ";
    string one, two;
    cin>>one>>two;
    pair<int,int> group=students.search(one, two);
    if (students.check(group)){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }

    return 0;
}
*/

int main(){

    vector<string> students;
    int n;
    cout<<"Input the number of elements in the Binary tree(include N as elements): ";
    cin>>n;
    cout<<"Input the elements with a space: ";
    for (int i=0; i<n; i++){
        string x;
        cin>>x;
        students.push_back(x);
    }
    cout<<"Input the pair of students with a space: ";
    string one, two;
    cin>>one>>two;
    int indx1=1, indx2=1;
    for (int i=0; i<n; i++){
        if (one==students[i]){
            indx1+=i;
        }
        if (two==students[i]){
            indx2+=i;
        }
    }
    int lIndx1 = log2(indx1);
    int lIndx2 = log2(indx2);
    if (lIndx1==lIndx2 && ((indx1/2)-1)>=0 && ((indx2/2)-1)>=0 && students[((indx2/2)-1)]!=students[((indx1/2)-1)]){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }

    return 0;
}