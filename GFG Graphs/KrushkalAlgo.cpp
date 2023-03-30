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

int PrimAlgo(vector<Graph> v,int s,int n){
    bool visited[n+1];
    int sum = 0;
    sort(v.begin(),v.end(),Graph::comp);
    for(int i = 0;i<n;i++)visited[i] = false;
    int count = 0;
    for(auto l:v){
        if(visited[l.x] && visited[l.y])continue;
        else if(!visited[l.x] && !visited[l.y]){
            count+=2;
            sum += l.z;
        }
        else{
            count++;
            sum += l.z;
        }
        visited[l.x] = true;
        visited[l.y] = true;
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
    cout<<"MST: "<<PrimAlgo(v,l,n)<<endl;
    return 0;
}