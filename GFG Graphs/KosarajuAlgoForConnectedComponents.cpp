#include<iostream>
#include<stack>
using namespace std;

void addedge(vector<int> v[],int si,int di){
    v[si].push_back(di);
}

void dfs(vector<int> v[],int index,stack<int>* s,vector<bool>& visited){
    visited[index] = true;
    cout<<index<<" ";
    for(int x:v[index]){
        if(!visited[x])dfs(v,x,s,visited);
        v[index].erase(v[index].begin());
        addedge(v,x,index);
    }
    if(!s)return;
    s->push(index);
    return;
}

void DFS(vector<int> v[],int n){
    stack<int>* s = new stack<int>; 
    vector<bool> visited(n,false);
    cout<<"Normal DFS:- \n";
    for(int i=0;i<n;i++){
        if(!visited[i])dfs(v,i,s,visited);
    }
    cout<<"\nConnected Components:- \n";
    for(int i=0;i<n;i++)visited[i] = false;
    while(!s->empty()){
        int i = s->top();
        s->pop();
        if(visited[i])continue;
        dfs(v,i,0,visited);
        cout<<endl;
    }
    return;
}


int main(){
    int n,e;
    cout<<"Enter the vertex and edges:- ";
    cin>>n>>e;
    cout<<"Enter the edges:- ";
    vector<int> v[n];
    for(int i=0;i<e;i++){
        int si,de;
        cin>>si>>de;
        addedge(v,si,de);
    }
    DFS(v,n);
    return 0;
}