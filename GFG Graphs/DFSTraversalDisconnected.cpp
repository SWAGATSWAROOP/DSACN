#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<int> v[],int x,bool visited[]){
    cout<<x<<" ";
    visited[x] = true;
    for(int l:v[x]){
        if(!visited[l])DFS(v,l,visited);
    }
    return;
}

void DFSdi(vector<int> v[],int vertex){
    bool visited[vertex+1];
    for(int i=0;i<vertex;i++)visited[i] = false;
    for(int i = 0;i<vertex;i++){
        if(!visited[i])DFS(v,i,visited);
    }
    cout<<"\n";
}

void addedge(vector<int> v[],int k,int l){
    v[k].push_back(l);
    v[l].push_back(k);
}

int main(){
    int n,e;
    cout<<"Enter the number of vertex:- ";
    cin>>n;
    vector<int> v[n];
    cout<<"Enter the number of edges:- ";
    cin>>e;
    for(int i=0;i<e;i++){
        int a,f;
        cout<<"Enter the edge :- ";
        cin>>a>>f;
        addedge(v,a,f);
    }
    DFSdi(v,n);
    return 0;
}