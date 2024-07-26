#include<iostream>
#include<climits>
using namespace std;

int main(){

    int n;
    cout<<">> Enter the number of elements in the array : ";
    cin>>n;
    int arr[n];
    int soln[n];
    cout<<">> Enter the elements of the array seperated by spaces : ";
    for (int i=0; i<n; i++){
        soln[i]=INT_MIN;
        cin>>arr[i];
        if (soln[0]<arr[i]){
            soln[0]=arr[i];
        }
    }
    for (int length=2; length<=n; length++){
        int i=0, j=1;
        int min1=j;
        while(j<n){
            if (j-i>length){
                i=min1;
                min1=i+1;
                for (int k=i+2; k<=j; k++){
                    min1 = (arr[min1]>arr[k]? k: min1);
                }
            }
            if (j>=length){
                if (soln[length-1]<arr[i]){
                    soln[length-1]=arr[i];
                }
            }
            if (arr[i]>arr[j]){
                i=j;
                j++;
                min1=j;
            }
            else if (arr[min1]>=arr[j]){
                min1=j;
                j++;
            }
            else{
                j++;
            }
        }
        if (j-i>length){
            i=min1;
        }
        if (soln[length-1]<arr[i]){
            soln[length-1]=arr[i];
        }
    }
    cout<<"The resulting array is : ";
    for (int i=0; i<n; i++){
        cout<<soln[i]<<" ";
    }cout<<endl;

    return 0;
}
