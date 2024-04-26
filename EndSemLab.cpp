#include <iostream>
using namespace std;
// question was that given a preorder is it possible to make a binary search tree with the same preorder
bool isValidBST(int arr[], int start, int end){
	if (start<end){
		int root=arr[start];
		int greater=end;
		for (int i=start+1; i<end; i++){
			if (arr[i]==root){
				return false;
			}
			if(arr[i]>root){
				greater=i;
				break;
			}
		}
		for (int i=greater; i<end; i++){
			if(arr[i]<root){
				return false;
			}
		}
		return (isValidBST(arr, start+1, greater) && isValidBST(arr, greater, end));
	}
	return true;
}
int main() {
	int t;
	cin>>t;
	for (int i=0; i<t; i++){
		int n;
		cin>>n;
		int arr[n];
		for (int j=0; j<n; j++){
			cin>>arr[j];
		}
		cout<<(isValidBST(arr, 0, n)? "True\n": "False\n");
	}
  
    return 0;
}
