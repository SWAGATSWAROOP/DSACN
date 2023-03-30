#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<utility>
using namespace std;

void BFS(vector<pair<int,int> > v[],vector<int>& inorder,int n,int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int m = q.front();
        q.pop();
        for(auto x:v[m]){
            if(inorder[x.first] > inorder[m]+x.second)inorder[x.first] = inorder[m]+x.second;
            q.push(x.first);
        }
    }
    for(int x:inorder){
        if(x == INT_MAX)continue;
        cout<<x<<" ";
    }
    cout<<"\n";
}

void addedge(vector<pair<int,int> > v[],int s,int d,int f){ // Directed
    pair<int,int> k(d,f);
    v[s].push_back(k);
}

int main(){
    int n,e,l;
    cout<<"Enter the number edges of graph:-";
    cin>>n;
    vector<pair<int,int> > v[n];
    vector<int> inorder(n,INT_MAX);
    cout<<"Enter the number of edges:- ";
    cin>>e;
    while(e--){
        int s,d,f;
        cout<<"Enter the vertex between whose edges are present:-";
        cin>>s>>d;
        cout<<"Enter the weight :- ";
        cin>>f;
        addedge(v,s,d,f);
    }
    cout<<"Enter the starting index:- ";
    cin>>l;
    inorder[l] = 0;
    BFS(v,inorder,n,l);
    return 0;
}