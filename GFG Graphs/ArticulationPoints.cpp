#include<iostream>
using namespace std;

void addedge(vector<int> v[],int source,int destination){
    v[source].push_back(destination);
    v[destination].push_back(source);
}

int dfs(vector<int> v[],int index,int parent,vector<bool>& visited,vector<int>& dis,vector<int>& low,int& count,int& rcount){
    visited[index] = true;
    dis[index] =  count++;
    low[index] = dis[index];
    for(auto x:v[index]){
        if(parent == x)continue;
        if(!visited[x]){
            low[index] = min(dfs(v,x,index,visited,dis,low,count,rcount),low[index]);
            if(parent == index)rcount++;
        }
        else low[index] = min(low[index],dis[x]);
    }
    return low[index];
}

void DFS(vector<int> v[],int n){
    vector<bool> visited(n,false);
    vector<int> dis(n,0);
    vector<int> low(n,0);
    vector<int> o(n,0);
    int count = 1;
    cout<<"Enter Choice (1 for starting from any vertex and 0 from starting normally):-";
    int x;
    cin>>x;
    cout<<"Articulation Points:- \n";
    if(x){
        cout<<"Enter starting vertex:- ";
        int i;
        cin>>i;
        int rcount = 0;
        dfs(v,i,i,visited,dis,low,count,rcount);
        o[i] = 1;
        if(rcount > 1)cout<<i<<" ";
    }
    for(int i=0;i<n;i++){
        int rcount = 0;
        if(!visited[i]){
            dfs(v,i,i,visited,dis,low,count,rcount);
            o[i] = 1;
            if(rcount > 1)cout<<i<<" ";
        }
    }
    for(int i = 0;i<n;i++){
        if(o[i])continue;
        for(auto x:v[i]){
            if(low[x]>=dis[i]){
                cout<<i<<" ";
                break;
            }
        }
    }
    cout<<endl;
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