#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<pair<string, int>> around(vector<pair<string, int>> &v, int i){
    vector<pair<string, int>> connections;
    if (((2*i)+1)<v.size() && (v[(2*i)+1].first!="N")){
        connections.push_back(v[(2*i)+1]);
        v[(2*i)+1].first = "N";
    }
    if (((2*i)+2)<v.size() && (v[(2*i)+2].first!="N")){
        connections.push_back(v[(2*i)+2]);
        v[(2*i)+2].first = "N";
    }
    if (((((i+1)/2)-1)>=0) && v[((i+1)/2)-1].first!="N"){
        connections.push_back(v[((i+1)/2)-1]);
        v[((i+1)/2)-1].first = "N";
    }
    return connections;
}

vector<vector<string>> bombEffect(vector<pair<string, int>> &v, int i){
    vector<vector<string>> ans;
    vector<string> current;
    current.push_back(v[i].first);
    ans.push_back(current);
    vector<pair<string,int>> cur;
    cur.push_back(v[i]);    
    v[i].first="N";
    while (true){
        current.clear();
        vector<pair<string,int>> next;
        for (int j=0; j<cur.size(); j++){
            vector<pair<string,int>> tmp = around(v, cur[j].second);
            for (int k=0; k<tmp.size(); k++){
                next.push_back(tmp[k]);
                current.push_back(tmp[k].first);
            }
        }
        if (current.empty()){
            break;
        }
        ans.push_back(current);
        cur=next;
    }
    
    return ans;
}

int main(){

    vector<pair<string, int>> junction;
    int n;
    cout<<"Input the number of elements in the Binary tree(include N as elements): ";
    cin>>n;
    cout<<"Input the elements with a space: ";
    for (int i=0; i<n; i++){
        string x;
        cin>>x;
        junction.push_back(make_pair(x, i));
    }
    string target;
    cout<<"Input the target: ";
    cin>>target;
    vector<vector<string>> ans;
    for (int i=0; i<n; i++){
        if (junction[i].first==target){
            ans = bombEffect(junction, i);
            break;
        }
    }
    for (int i=0; i<ans.size(); i++){
        for (int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
