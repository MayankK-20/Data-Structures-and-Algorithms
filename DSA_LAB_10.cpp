#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &arr, int i, int j){
    int tmp = arr[j];
    arr[j]=arr[i];
    arr[i]=tmp;
}

void heapify(vector<int> &arr, int i){
    int parent = ((i+1)/2)-1;
    if (arr[parent] > arr[i] && parent<i && parent>-1){
        swap(arr, i, parent);
        heapify(arr, parent);
    }
}

void delRoot(vector<int> &arr, int& height){
    if (height<1){
        return;
    }
    swap(arr, 0, height-1);
    height--;
    int el=0;
    while(((2*el)+2)<height){
        if (arr[el]>arr[(2*el)+1] && arr[(2*el)+2]<arr[el]){
            if (arr[(2*el)+1]>arr[(2*el)+2]){
                swap(arr, el, (2*el)+2);
                el=(2*el)+2;
            }
            else{
                swap(arr, el, (2*el)+1);
                el=(2*el)+1;
            }
        }
        else if (arr[el]>arr[(2*el)+1]){
            swap(arr, el, (2*el)+1);
            el=(2*el)+1;
        }
        else if (arr[el]>arr[(2*el)+2]){
            swap(arr, el, (2*el)+2);
            el=(2*el)+2;
        }
        else{
            break;
        }
    }
    if (((2*el)+1)<height){
        if (arr[el]>arr[(2*el)+1]){
            swap(arr, el, (2*el)+1);
        }
    }
}

int extractMin(vector<int>& v, int& height){
    if (height<1){
        return -1;
    }
    int el = v.front();
    delRoot(v, height);
    return el;
}

vector<int> Heapsort(vector<int> v, int height){
    vector<int> ans;
    int n = height;
    for (int i=0; i<n; i++){
        ans.push_back(extractMin(v, height));
    }
    return ans;
}

int main(){

    vector<int> minHeap;
    int height=0;
    int n;
    cout<<"Input the number of elements in the heap: ";
    cin>>n;
    cout<<"Input the elements of the heap with a space: ";
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        minHeap.push_back(x);
        height++;
    }
    for (int i=0; i<height; i++){               // heapify function;
        heapify(minHeap, i);
        for (int i=0; i<height; i++){
            cout<<minHeap[i]<<" ";
        }cout<<endl;
    }
    // cout<<"After Deleting root: ";
    // delRoot(minHeap, height);
    // for (int i=0; i<height; i++){
    //     cout<<minHeap[i]<<" ";
    // }cout<<endl;
    // cout<<"min extracted: ";
    // cout<<extractMin(minHeap, height)<<endl;
    cout<<"current elements: ";
    for (int i=0; i<height; i++){
        cout<<minHeap[i]<<" ";
    }cout<<endl;

    cout<<"elements after heapsort: ";
    vector<int> heapSort = Heapsort(minHeap, height);   // heapsort returns a vector of the sorted heap;
    for (int i=0; i<height; i++){                       // display elements of the heapsort
        cout<<heapSort[i]<<" ";
    }cout<<endl;


    return 0;
}