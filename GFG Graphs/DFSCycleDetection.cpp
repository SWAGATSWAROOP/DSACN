#include<iostream>
#include<vector>
using namespace std;

bool DFScycle(vector<int> v[],int m,int parent,bool visited[]){
    visited[m] = true;
    for(int x:v[m]){
        if(x!= -1 && !visited[x] && DFScycle(v,x,m,visited))return true;
        else if(x != parent)return true;
    }
    return false;
}

bool detectDFS(vector<int> v[],int n){
    bool visited[n+1];
    for(int i = 0;i<n;i++)visited[i] = false;
    for(int i = 0;i<n;i++){
        if(!visited[i] && DFScycle(v,i,-1,visited))return true;
    }
    return false;
}

void addedge(vector<int> v[],int s,int m){
    v[s].push_back(m);
    v[m].push_back(s);
}

int main(){
    int n,e;
    cout<<"Enter the number of vertex :-";
    cin>>n;
    cout<<"Enter the number of edges:- ";
    cin>>e;
    vector<int> v[n];
    for(int i =0;i<e;i++){
        int a,b;
        cout<<"Enter the edges:- ";
        cin>>a>>b;
        addedge(v,a,b);
    }
    if(detectDFS(v,n))cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}