#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i]>arr[j]){
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    cout<<arr[n-k]<<endl;

    return 0;
}






/*
#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i]>arr[j]){
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}
/*

// better alternate code time=(O(n))
/*
#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int p0=0, p1=0, p2=n-1;
    while(p1<=p2){
        if (arr[p1]==0){
            arr[p1]=arr[p0];
            arr[p0]=0;
            p1++;
            p0++;
        }
        else if(arr[p1]==1){
            p1++;
        }
        else{
            arr[p1]=arr[p2];
            arr[p2]=2;
            p2--;
        }
    }
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}
*/









/*
#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n/2];
    int brr[n/2];
    for (int i=0; i<n/2; i++){
        cin>>arr[i];
    }
    for (int i=n/2; i<n; i++){
        cin>>brr[i-(n/2)];
    }
    int soln[n];
    int index1=0, index2=0, index3=0;
    while(index1<n/2 && index2<n/2){
        if (arr[index1]<brr[index2]){
            soln[index3]=arr[index1];
            index3++;
            index1++;
        }
        else{
            soln[index3]=brr[index2];
            index3++;
            index2++;
        }
    }
    while(index1<n/2){
        soln[index3]=arr[index1];
        index3++;
        index1++;
    }
    while(index2<n/2){
        soln[index3]=brr[index2];
        index3++;
        index2++;
    }
    for (int i=0; i<n; i++){
        cout<<soln[i]<<" ";
    }cout<<endl;


    return 0;
}
*/
