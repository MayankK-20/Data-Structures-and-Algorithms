#include<iostream>
#include<climits>
using namespace std;

int maxim(int arr[], int x, int y){
    if (x>y){
        return INT_MIN;
    }
    int tmp1=x, tmp2=y; 
    int sum = arr[tmp1];
    for (int i=x+1; i<y; i++){
        sum += arr[i];
    }
    for (int i=x; i<y; i++){
        sum = max(sum, maxim(arr, tmp1, --y));
    }
    for (int i=x; i<y; i++){
        sum = max(sum, maxim(arr, ++x, tmp2));
    }
    return sum;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxim(arr, 0, n);

    return 0;
}