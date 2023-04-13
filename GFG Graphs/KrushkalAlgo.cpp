#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int find(int x,int parent[]){
    if(parent[x] == x)return x;
    return find(parent[x],parent);
}

void uni(int x,int y,int parent[]){parent[x] = y;}

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

int KruskalAlgo(vector<Graph> v,int s,int n){
    int parent[n];
    for(int i = 0;i<n;i++)parent[i] = i;
    int sum = 0;
    sort(v.begin(),v.end(),Graph::comp);
    for(auto l:v){
        int m = find(l.x,parent);
        int k = find(l.y,parent);
        if(m!=k){
            uni(m,k,parent);
            sum += l.z;
        }
    }
    return sum;
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
    cout<<"MST: "<<KruskalAlgo(v,l,n)<<endl;
    return 0;
}