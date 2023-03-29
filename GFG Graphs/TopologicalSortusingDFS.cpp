#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(vector<int> v[],int x,bool visited[],stack<int>& st){
    visited[x] = true;
    for(int l:v[x])if(!visited[l])DFS(v,l,visited,st);
    st.push(x);
    return;  
}


void DFSdi(vector<int> v[],int vertex){
    bool visited[vertex+1];
    stack<int> st;
    for(int i=0;i<vertex;i++)visited[i] = false;
    for(int i = 0;i<vertex;i++)if(!visited[i])DFS(v,i,visited,st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    } 
    cout<<"\n";
    return;
}

bool DFScycle(vector<int> v[],int m,bool rec[],bool visited[]){
    visited[m] = true;
    rec[m] = true;
    for(int x:v[m]){
        if(x!= -1 && !visited[x] && DFScycle(v,x,rec,visited))return true;
        else if(rec[x])return true;
    }
    rec[m] = false;
    return false;
}

bool detectDFS(vector<int> v[],int n){
    bool visited[n+1];
    bool rec[n+1];
    for(int i = 0;i<n;i++){
        visited[i] = false;
        rec[i] = false;
    }
    for(int i = 0;i<n;i++){
        if(!visited[i] && DFScycle(v,i,rec,visited))return true;
    }
    return false;
}

void addedge(vector<int> v[],int k,int l){
    v[k].push_back(l);
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
    if(detectDFS(v,n))cout<<"It has cycle\n";
    else DFSdi(v,n);
    return 0;
}