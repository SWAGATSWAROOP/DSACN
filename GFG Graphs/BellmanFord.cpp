#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    public:
    int x;
    int y;
    int z;

    static bool comp(Graph s,Graph k){
        return s.z<k.z;
    }

    Graph(){
        cout<<"Enter the vertex's:- ";
        cin>>x>>y;
        cout<<"Enter the weight:- ";
        cin>>z;
    }
};

void Bellford(vector<Graph> v,int n,int s){
    vector<int> v2(n,INT_MAX);
    v2[s] = 0;
    for(int i = 0;i<n-1;i++){
        for(auto j:v){
            if(v2[j.x]!=INT_MAX && v2[j.y] > v2[j.x]+j.z)v2[j.y] = v2[j.x]+j.z;
        }
    }
    for(int i = 0;i<n;i++)cout<<i<<"-> "<<v2[i]<<",";
    cout<<"\n";
    return;
}

int main(){
    int n,e,l;
    cout<<"Enter the number edges of graph:-";
    cin>>n;
    vector<Graph> v;
    cout<<"Enter the number of edges:- ";
    cin>>e;
    while(e--){
        Graph a;
        v.push_back(a);
    }
    cout<<"Enter the starting point:- ";
    cin>>l;
    Bellford(v,n,l);
    return 0;
}