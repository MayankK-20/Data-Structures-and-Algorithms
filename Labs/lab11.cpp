#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class queue{
    string* arr;
    int front = -1;
    int back = -1;
    int size;

    public:

    queue(int n){
        arr = new string[n];
        size = n;
    }

    /*Enqueue*/
    void push(string x){
        if(++back==size){
            cout<<"Queue overflow\n";
            back--;
            return;
        }
        arr[back] = x;
        if (front==-1){
            front++;
        }
    }

    /*Dequeue*/
    void pop(){
        if (front==-1 || front>back){
            cout<<"Queue is empty\n";
            return;
        }
        front++;
    }

    /*finding first in queue*/
    string peek(){
        if (front==-1 || front>back){
            cout<<"Queue is empty\n";
            return "-1";
        }
        return arr[front];
    }

    bool empty(){
        if (front==-1 || front>back){
            return true;
        }
        return false;
    }
};

void insertAdjacencyMatrix(string nodes[], int**& arr, string first, string second, int n){
    int index1, index2;
    for (int i=0; i<n; i++){
        if (first==nodes[i]){
            index1=i;
        }
        if (second==nodes[i]){
            index2=i;
        }
    }
    arr[index1][index2]=1;
}

void insertAdjacencyList(string nodes[], vector<vector<pair<string,int>>>& v, string first, string second, int weight){
    for (int i=0; i<v.size(); i++){
        if (nodes[i]==first){
            v[i].push_back(make_pair(second, weight));
            break;
        }
    }
}

void deleteAdjacencyList(string nodes[], vector<vector<pair<string,int>>>& v, string first, string second){
    int index;
    for (int i=0; i<v.size(); i++){
        if (nodes[i]==first){
            index=i;
        }
    }
    vector<pair<string,int>> tmp;
    for (int i=0; i<v[index].size(); i++){
        if(v[index][i].first==second){
            continue;
        }
        tmp.push_back(v[index][i]);
    }
    v[index]=tmp;
}

void deleteAdjacencyMatrix(string nodes[], int**& arr, string first, string second, int n){
    int index1, index2;
    for (int i=0; i<n; i++){
        if (first==nodes[i]){
            index1=i;
        }
        if (second==nodes[i]){
            index2=i;
        }
    }
    arr[index1][index2]=0;
}

void displayAdjacencyList(vector<vector<pair<string,int>>> v, string nodes[]){
    cout<<"Adjacency List: \n";
    for (int i=0; i<v.size(); i++){
        cout<<nodes[i]<<": ";
        for (int  j=0; j<v[i].size(); j++){
            cout<<"("<<v[i][j].first<<", "<<v[i][j].second<<") ";
        }
        cout<<endl;
    }
}

void dislayAdjacencyMatrix(int** arr, int n){
    cout<<"Adjacency Matrix: \n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
}

bool check(vector<string> visited, string j){
    for (int i=0; i<visited.size(); i++){
        if (visited[i]==j){
            return true;
        }
    }
    return false;
}

vector<string> BFS(vector<vector<pair<string,int>>> v, string nodes[], string vertex){
    vector<string> visited;
    visited.push_back(vertex);
    queue on(v.size());
    on.push(vertex);
    int i=0;
    while(!on.empty()){
        if (nodes[i]==on.peek()){
            for (int j=0; j<v[i].size(); j++){
                if (!check(visited, v[i][j].first)){
                    visited.push_back(v[i][j].first);
                    on.push(v[i][j].first);
                }
            }
            on.pop();
            i=-1;
        }
        i++;
    }

    cout<<"BFS: ";
    for (int i=0; i<visited.size(); i++){
        cout<<visited[i]<<" ";
    }
    cout<<endl;

    return visited;
}

void DFS(vector<vector<pair<string,int>>> v, string nodes[], string vertex, vector<string>& visited){
    visited.push_back(vertex);
    for (int i=0; i<v.size(); i++){
        if (nodes[i]==vertex){
            for (int j=0; j<v[i].size(); j++){
                if (!check(visited, v[i][j].first)){
                    DFS(v, nodes, v[i][j].first, visited);
                }
            }
            break;
        }
    }
}

bool connectedDisconnected(vector<vector<pair<string,int>>> v, string nodes[]){
    vector<string> tmp;
    for (int i=0; i<v.size(); i++){
        DFS(v, nodes, nodes[i], tmp);
        if (tmp.size()!=v.size()){
            cout<<"This is a disconnected graph\n";
            return false;
        }
        tmp.clear();
    }
    cout<<"This is a connected graph\n";
    return true;
}

bool getBack(vector<vector<pair<string,int>>> v, string a, string b, string nodes[]){
    int index1, index2;
    for (int i=0; i<v.size(); i++){
        if (nodes[i]==a){
            index1=i;
        }
        if (nodes[i]==b){
            index2=i;
        }
    }
    for (int i=0; i<v[index1].size(); i++){
        if (v[index1][i].first==b){
            for (int j=0; j<v[index2].size(); j++){
                if (v[index2][j].first==a){
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

bool directedUndirected(vector<vector<pair<string,int>>> v, string nodes[]){
    for (int i=0; i<v.size(); i++){
        for (int j=0; j<v[i].size(); j++){
            if (!getBack(v, nodes[i], v[i][j].first, nodes)){
                cout<<"This is an directed graph\n";
                return true;
            }
        }
    }
    cout<<"This is an undirected graph\n";
    return false;
}

int shortestPath(vector<vector<pair<string,int>>> v, string nodes[], string a, string b){
    if (a==b){
        return 0;           
    }
    int index;
    for (int i=0; i<v.size(); i++){
        if (nodes[i]==a){
            index=i;
        }
    }
    int distance=INT_MAX;
    // for (int i=0; i<v[index].size(); i++){
    //     int tmp = v[index][i].second+shortestPath(v, nodes, v[index][i].first, b);
    //     distance=min(distance, tmp);
    // }
    return distance;
}

int main(){

    int n;
    cout<<"Input number of nodes in the graph: ";
    cin>>n;
    int m;
    cout<<"Input number of edges in the graph: ";
    cin>>m;
    cout<<"Input nodes with a space: ";
    string nodes[n];
    int** adjacencyMatrix=new int*[n];
    for (int i=0; i<n; i++){
        cin>>nodes[i];
    }
    for (int i=0; i<n; i++){
        adjacencyMatrix[i]=new int[n];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            adjacencyMatrix[i][j]=0;
        }
    }
    vector<vector<pair<string,int>>> adjacencyList(n);
    cout<<"Input "<<m<<" edges with 2 space seperated nodes with connection from first to second and its weight(+ve only)\n";
    for (int i=0; i<m; i++){
        string first, second;
        int weight;
        cin>>first>>second>>weight;
        insertAdjacencyMatrix(nodes, adjacencyMatrix, first, second, n);
        insertAdjacencyList(nodes, adjacencyList, first, second, weight);
    }

    displayAdjacencyList(adjacencyList, nodes);
    dislayAdjacencyMatrix(adjacencyMatrix, n);
    
    cout<<"Input vertex for BFS: ";
    string vertex;
    cin>>vertex;
    BFS(adjacencyList, nodes, vertex);
    vector<string> depthFirstSearch;
    DFS(adjacencyList, nodes, vertex, depthFirstSearch);
    cout<<"DFS: ";
    for (int i=0; i<depthFirstSearch.size(); i++){
        cout<<depthFirstSearch[i]<<" ";
    }cout<<endl;

    connectedDisconnected(adjacencyList, nodes);
    directedUndirected(adjacencyList, nodes);

    cout<<"Input nodes a and b where you need shortest path from a to b: ";
    string first, second;
    cin>>first>>second;
    cout<<shortestPath(adjacencyList, nodes, first, second)<<endl;

    return 0;
}