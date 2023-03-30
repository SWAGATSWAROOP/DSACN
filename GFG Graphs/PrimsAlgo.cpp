#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class comp{
    public:
    bool operator()(pair<int,int> s,pair<int,int> k){
        return s.second>k.second;
    }
};

int PrimAlgo(vector<pair<int,int> > v[],int s,int n){
    bool visited[n+1];
    int sum = 0;
    pair<int,int> p(s,0);
    for(int i = 0;i<n;i++)visited[i] = false;
    priority_queue<pair<int,int>,vector<pair<int,int> >,comp> pq;
    pq.push(p);
    while(!pq.empty()){
        int k = pq.top().second;
        int m = pq.top().first;
        pq.pop();
        if(visited[m])continue;
        cout<<m<<" ";
        sum += k;
        visited[m] = true;
        for(auto x:v[m])if(!visited[x.first])pq.push(x);
    }
    cout<<"\n";
    return sum;
}

void addedge(vector<pair<int,int> > v[],int s,int d,int f){ // Directed
    pair<int,int> k(d,f);
    pair<int,int> o(s,f);
    v[s].push_back(k);
    v[d].push_back(o);
}

int main(){
    int n,e,l;
    cout<<"Enter the number edges of graph:-";
    cin>>n;
    vector<pair<int,int> > v[n];
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
    cout<<"MST: "<<PrimAlgo(v,l,n)<<endl;
    return 0;
}