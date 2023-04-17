#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

void addedge(vector<int> v[],int source,int destination){
    v[source].push_back(destination);
    v[destination].push_back(source);
}

int BFScolour(vector<int> v[],int n){
    queue<int> q;
    q.push(0);
    int col = 1;
    unordered_map<int,int> map;
    map[0] = 0;
    vector<bool> visited(n,false);
    while(!q.empty()){
        int m = q.front();
        visited[m] = true;
        q.pop();
        set<int> colour;
        for(auto x:v[m]){
            if(visited[x])colour.insert(map[x]);
            else q.push(x);
        }
        int l = colour.size()+1;
        col = max(col,l);
        int count = 0;
        bool p = false;
        for(auto x:colour){
            if(x!=count){
                map[m] = count;
                p = true;
                break;
            }
            count++;
        }
        if(!p)map[m] = count;
    }
    for(auto x:map)cout<<"vertex "<<x.first<<" colour "<<x.second<<endl;
    return col;
}

int main(){
    int n,e;
    cout<<"Enter the number of edges:- ";
    cin>>n>>e;
    vector<int> v[n];
    cout<<"Enter the edges:-\n";
    while(e--){
        int source,destination;
        cin>>source>>destination;
        addedge(v,source,destination);
    }
    cout<<BFScolour(v,n)<<" is the minimum number of colours."<<endl;
    return 0;
}