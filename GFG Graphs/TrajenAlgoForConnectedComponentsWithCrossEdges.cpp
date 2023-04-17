#include<iostream>
#include<stack>
using namespace std;

void addedge(vector<int> v[],int source,int destination){
    v[source].push_back(destination);
}

int dfs(vector<int> v[],int index,int parent,vector<bool>& visited,vector<bool> bfs,vector<int>& d,vector<int>& l,int& count,stack<int>& st){
    st.push(index);
    visited[index] = true;
    bfs[index] = true;
    d[index] = count++;
    l[index] = d[index];
    for(auto x:v[index]){
        if(parent == x)continue;
        if(!visited[x])l[index] = min(dfs(v,x,index,visited,bfs,d,l,count,st),l[index]);
        else if(bfs[x])l[index] = min(d[x],l[index]);
    }
    cout<<st.top()<<" ";
    if(l[st.top()] == d[st.top()])cout<<endl;
    st.pop();
    return l[index];
}

void DFS(vector<int> v[],int n){
    vector<int> d(n,0);
    vector<int> l(n,0);
    vector<bool> visited(n,false);
    vector<bool> bk(n,false);
    stack<int> st;
    int count = 1;
    cout<<"Do you want to start from an index(1 for yes and 0 for no):- ";
    int x;cin>>x;
    if(x){
        int i;
        cout<<"Enter the starting index:- ";
        cin>>i;
        dfs(v,i,i,visited,bk,d,l,count,st);
    }
    for(int i = 0;i<n;i++)if(!visited[i])dfs(v,i,i,visited,bk,d,l,count,st);
    return;
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
    DFS(v,n);
    return 0;
}