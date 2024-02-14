#include<iostream>
using namespace std;

bool IsSafe(int**arr, int n, int m, int x, int y){
    if (x>=0 && y>=0 && x<n && y<m && arr[x][y]==0){
        return true;
    }
    return false;
}

bool out(int**arr, int x, int y, int n, int m){
    if (x==n-1 && y==m-1){
        return true;
    }
    if (IsSafe(arr, n, m, x, y)){ 
        arr[x][y]=1; 
        if (out(arr, x, y+1, n, m)){
            return true;
        }
        if (out(arr, x+1, y, n, m)){
            return true;
        }
        if (out(arr, x-1, y, n, m)){
            return true;
        }
        if (out(arr, x, y-1, n, m)){
            return true;
        }
        return false;
    }
    return false;
}

int main(){

    int n,m;
    cin>>n>>m;
    int**arr=new int*[n];
    for (int i=0; i<n; i++){
        arr[i]=new int[m];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    if (out(arr, 0, 0, n, m)){
        cout<<"True\n";
    }
    else{
        cout<<"False\n";
    }


    return 0;
}