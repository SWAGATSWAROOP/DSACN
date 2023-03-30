#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool BFSdis(vector<int> v[],vector<int>& inorder,int n){
    queue<int> q;
    int count = 0;
    for(int i = 0;i<n;i++){
        if(!inorder[i])q.push(i);
    }
    while(!q.empty()){
        int m = q.front();
        cout<<m<<" ";
        q.pop();
        for(auto x:v[m])if(--inorder[x]==0)q.push(x);
        count++;
    }
    cout<<"\n";
    if(count!=n)return true;
    return false;
}

void addedge(vector<int> v[],int s,int d,vector<int>& inorder){ // Directed
    v[s].push_back(d);
    inorder[d]++;
}

int main(){
    int n,e;
    cout<<"Enter the number edges of graph:-";
    cin>>n;
    vector<int> v[n];
    vector<int> inorder(n,0);
    cout<<"Enter the number of edges:- ";
    cin>>e;
    while(e--){
        int s,d;
        cout<<"Enter the vertex between whose edges are present:-";
        cin>>s>>d;
        addedge(v,s,d,inorder);
    }
    if(BFSdis(v,inorder,n))cout<<"It is cyclic\n";
    return 0;
}