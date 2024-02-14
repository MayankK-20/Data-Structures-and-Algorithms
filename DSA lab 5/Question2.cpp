#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int arr[], int start, int end){
    int index=(rand()%(end-start))+start;
    int i=start-1;
    for (int j=start; j<end; j++){
        if (index==j){
            continue;
        }
        if (arr[j]>arr[index]){
            i++;
            if (index==i){
                index=j;
            }
            int tmp=arr[j];
            arr[j]=arr[i];
            arr[i]=tmp;
        }
    }
    i++;
    int tmp=arr[i];
    arr[i]=arr[index];
    arr[index]=tmp;
    cout<<"Pivot Selected: "<<arr[i]<<endl;
    cout<<"Elements in array after the iteration: ";
    for (int j=start; j<end; j++){
        cout<<arr[j]<<" ";
    }cout<<endl<<endl;
    return i;
}

void quickSort(int arr[], int start, int end){
    if (start<end){
        int pivot=partition(arr, start, end);
        quickSort(arr, start, pivot);
        quickSort(arr, pivot+1, end);
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quickSort(arr, 0, n);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}