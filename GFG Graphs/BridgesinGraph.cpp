#include<iostream>
using namespace std;

void addedge(vector<int> v[],int source,int destination){
    v[source].push_back(destination);
    v[destination].push_back(source);
}

int dfs(vector<int> v[],int index,int parent,vector<bool>& visited,vector<int>& dis,vector<int>& low,int& count){
    visited[index] = true;
    low[index] = dis[index] = count++;
    for(auto x:v[index]){
        if(x == parent)continue;
        else if(!visited[x])low[index] = min(dfs(v,x,index,visited,dis,low,count),low[index]);
        else low[index] = min(dis[x],low[index]);
    }
    return low[index];
}

void DFS(vector<int> v[],int n){
    vector<bool> visited(n,false);
    vector<int> dis(n,0);
    vector<int> low(n,0);
    cout<<"Do you want from any vertex(1) or in normal manner(0):-";
    int m,count = 1;
    cin>>m;
    if(m){
        cout<<"Enter the vertex:-";
        int x;
        cin>>x;
        dfs(v,x,x,visited,dis,low,count);
    }
    for(int i=0;i<n;i++)if(!visited[i])dfs(v,i,i,visited,dis,low,count);
    for(auto x:visited)x = false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            for(auto x:v[i]){
                if(low[x]>dis[i]){
                    cout<<i<<" to "<<x<<endl;
                }
            }
        }
    }
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