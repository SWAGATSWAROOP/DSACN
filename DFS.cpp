//DFS
#include<iostream>
using namespace std;

void DFS(int** edge,int n,int sv,bool* visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(int j=0;j<n;j++){
        if(edge[sv][j] && !visited[j]){
            DFS(edge,n,j,visited);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    int** edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        for(int j=0;j<n;j++){
            edge[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int k,l;
        cin>>k>>l;
        edge[k][l] = 1;
        edge[l][k] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }  
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(edge,n,i,visited);//Connected
        }
    }
    cout<<endl;
    return 0;
}