#include<iostream>
using namespace std;

void towerOfHanoi(int n, string T1, string T2, string T3, string T4){
    if (n<=0){
        return;
    }
    if (n==1){
        cout<<T1<<" -> "<<T4<<endl;
        return;
    }
    towerOfHanoi(n-2, T1, T4, T3, T2);
    cout<<T1<<" -> "<<T3<<endl;
    cout<<T1<<" -> "<<T4<<endl;
    cout<<T3<<" -> "<<T4<<endl;
    towerOfHanoi(n-2, T2, T3, T1, T4);
}

int main(){

    int n;
    cout<<">> Enter the number of disks : ";
    cin>>n;
    cout<<">> The sequence of steps are:-\n";
    towerOfHanoi(n, "T1", "T2", "T3", "T4");

    return 0;
}