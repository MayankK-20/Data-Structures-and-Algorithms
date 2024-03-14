#include<iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int n1=mid-start, n2=end-mid;       //length of temporary arrays which will be used for comparison
    int tmp1[n1];
    int tmp2[n2];
    for (int i=0; i<n1; i++){
        tmp1[i]=arr[i+start];
    }
    for (int i=0; i<n2; i++){
        tmp2[i]=arr[i+mid];
    }
    int index1=0, index2=0, index3=start;
    while(index1<n1 && index2<n2){
        if (tmp1[index1]<tmp2[index2]){
            arr[index3]=tmp1[index1];
            index1++;
            index3++;
        }
        else{
            arr[index3]=tmp2[index2];
            index2++;
            index3++;
        }
    }
    while(index1<n1){
        arr[index3]=tmp1[index1];
        index1++;
        index3++;
    }
    while(index2<n2){
        arr[index3]=tmp2[index2];
        index2++;
        index3++;
    }
}

void recursiveMergeSort(int arr[], int start, int end){
    if (start+1>=end){
        return;
    }
    int mid=((end-start)/2)+start;
    recursiveMergeSort(arr, mid, end);
    recursiveMergeSort(arr, start, mid);
    merge(arr, start, mid, end);
}

void iterativeMergeSort(int arr[], int n){
    int length=1;   //This is the length of array to be joined
    while(length<n){
        for (int start=0; start<n; start+=(2*length)){
            int mid = (length+start>n? n: length+start);
            int end = ((2*length)+start>n? n: (2*length)+start);
            merge(arr, start, mid, end);
        }
        length*=2;
    }
}

int main(){

    int n;
    cout<<"Number of elements in the array : ";
    cin>>n;
    int arr[n];     //array which will be sorted recursively
    int brr[n];     //array which will be sorted iteratively
    cout<<"Enter elements of the array seperated by space : ";
    for (int i=0; i<n;i++){
        cin>>arr[i];
        brr[i]=arr[i];
    }
    cout<<"Sorted array by Recursion is : ";
    recursiveMergeSort(arr, 0, n);
    for (int i=0; i<n-1; i++){
        cout<<arr[i]<<",";
    }
    cout<<arr[n-1]<<endl;
    cout<<"Sorted array by Iteration is : ";
    iterativeMergeSort(brr, n);
    for (int i=0; i<n-1; i++){
        cout<<brr[i]<<",";
    }
    cout<<brr[n-1]<<endl;

    return 0;
}
