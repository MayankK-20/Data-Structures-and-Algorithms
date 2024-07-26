//Question 1 fibonacci term
/*
#include<iostream>
using namespace std;

int fib(int n){
    if (n==0 || n==1){
        return n;
    }
    return (fib(n-1) + fib(n-2));
}

int main(){

    int n;
    cin>>n;
    cout<<fib(n)<<endl;

    return 0;
}
*/








//Question 2 pallindromic number
/*
#include<iostream>
using namespace std;

bool pall(string num){
    if(num==""){
        return true;
    }
    if (num[0]!=num[(num.size()-1)]){
        return false;
    }
    return pall(num.substr(1, (num.size()-2)));
}

int main(){

    string num;
    cin>>num;
    if (pall(num)){
        cout<<"True\n";
    }
    else{
        cout<<"False\n";
    }

    return 0;
}
*/








//Question 3 Number of type of steps(permutations)
/*
#include<iostream>
using namespace std;

int fac(int n){
    if (n==0 ||  n==1){
        return 1;
    }
    return fac(n-1)*n;
}

int permu(int step1, int step2){
    return (fac((step1+step2))/(fac(step1)*fac(step2)));
}

int main(){

    int n;
    cin>>n;
    int step1=0;
    int step2;
    if (n%2==0){
        step2 = n/2;
    }
    else{
        step1++;
        step2=(n-1)/2;
    }
    int ans=0;
    while(step2>=0){
        ans+=permu(step1, step2);
        step1+=2;
        step2--;
    }
    cout<<ans<<endl;

    return 0;
}
*/










//Question 4 binary search by recursion
/*
#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int k){
    if (start>end){
        return -1;
    }
    int mid=(end+start)/2;
    if (arr[mid]==k){
        return mid;
    }
    if (arr[mid]<k){
        return binarySearch(arr, mid+1, end, k);
    }
    else{
        return binarySearch(arr, start, mid-1, k);
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<binarySearch(arr, 0, n-1, k)<<endl;

    return 0;
}
*/
