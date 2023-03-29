#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<int> v[],int svertex,int vertex){
    bool visited[vertex+1];
    for(int i = 0;i<=vertex;i++)visited[i] = false;
    queue<int> q;
    visited[vertex] = true;
    q.push(vertex);
    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int x:v[u]){
            if(!visited[x])q.push(x);
            visited[x] = true;
        }
    }
    cout<<"\n";
}

void addedge(vector<int> v[],int s,int d){ //Not Directed
    v[s].push_back(d);
    v[d].push_back(s);
}

int main(){

    int n,e;
    cout<<"Enter the number edges of graph:-";
    cin>>n;
    vector<int> v[n];
    cout<<"Enter the number of edges:- ";
    cin>>e;
    while(e--){
        int s,d;
        cout<<"Enter the vertex between whose edges are present:-";
        cin>>s>>d;
        addedge(v,s,d);
    }
    BFS(v,n,0);
    return 0;
}